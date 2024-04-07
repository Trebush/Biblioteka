#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
using namespace std;
using namespace sql;
Connection* connectToDatabase() {
    Driver* driver;
    Connection* con;

    try {
        driver = get_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "root", ""); // Sprawdź poprawność adresu, użytkownika i hasła
        cout << "Connected successfully!" << endl;
        con->setSchema("biblioteka");
        return con; // Zwróć połączenie
    }
    catch (SQLException& e) {
        cout << "SQL Exception: " << e.what() << endl; // Wyświetl błąd w przypadku wystąpienia wyjątku
        return nullptr; // Zwróć nullptr w przypadku błędu
    }
}
class Czytelnik {
private:
    string imie;
public:
    Czytelnik(const string& imieCzytelnika) : imie(imieCzytelnika) {}

    string getName() const {
        return imie;
    }
};
class book {
private:
    vector <bool> czyWypozyczona;
    vector <string> tytul;
    vector <string> autor;
    vector <Czytelnik*> wypozyczenia;
public:
    void display(Connection* con) {
        cout << "1 - wyswietl wszystkie ksiazki " << endl;
        cout << "2 - wyswietl dostepne ksiazki " << endl;
        int wybor;
        cin >> wybor;
        switch (wybor) {
        case 1:
            try {
                Statement* stmt1;
                ResultSet* res;
                stmt1 = con->createStatement();
                res = stmt1->executeQuery("SELECT * FROM ksiazki"); // Zmodyfikuj zapytanie SQL dla swoich potrzeb

                while (res->next()) {
                    cout << "ID: " << res->getInt("ID") << ", ";
                    cout << "Autor: " << res->getString("autor") << ", ";
                    cout << "Tytul: " << res->getString("tytul") << ", ";
                    cout << "CzyWypozyczona: " << res->getString("czyWypozyczona") << ", ";
                    if (res->getString("czyWypozyczona") == "Tak") {
                        cout << "Imie i Nazwisko czytelnika: " << res->getString("czytelnik") << endl;
                        // Dodaj inne kolumny, które chcesz wyświetlić
                    }
                    else {
                        cout << endl;
                    }
                }
                delete res;
                delete stmt1;
            }
            catch (SQLException& e) {
                cout << "SQL Exception: " << e.what() << endl; // Wyświetl błąd w przypadku wystąpienia wyjątku
            }
            break;
        case 2:
            try {
                Statement* stmt2;
                ResultSet* res;
                stmt2 = con->createStatement();
                res = stmt2->executeQuery("SELECT * FROM ksiazki WHERE czyWypozyczona = 'Nie'"); // Zmodyfikuj zapytanie SQL dla swoich potrzeb

                while (res->next()) {
                    cout << "ID: " << res->getInt("ID") << ", ";
                    cout << "Autor: " << res->getString("autor") << ", ";
                    cout << "Tytul: " << res->getString("tytul") << ", ";
                    cout << "Czy Wypozyczona: " << res->getString("czyWypozyczona") << endl;
                }
                delete res;
                delete stmt2;
            }
            catch (SQLException& e) {
                cout << "SQL Exception: " << e.what() << endl; // Wyświetl błąd w przypadku wystąpienia wyjątku
            }
            break;
        default:
            cout << "Nieprawidlowy wybor" << endl;
            break;
        }
        cin.ignore();
    }
    void addBook(Connection* con) {
        string title, author, czyDostepna, czytelnik;

        cout << "Podaj tytul ksiazki: ";
        getline(cin >> ws, title);

        cout << "Podaj autora: ";
        getline(cin >> ws, author);

        cout << "Czy jest wypozyczona (Tak/Nie): ";
        cin >> czyDostepna;

        if (czyDostepna == "Tak" || czyDostepna == "tak" || czyDostepna == "T") {
            cout << "Podaj imie i nazwisko czytelnika czytelnika: ";
            getline(cin >> ws, czytelnik);
        }
        try {;
            Statement* stmt3 = con->createStatement();

            // Dodaj rekord do tabeli ksiazki
            string query = "INSERT INTO ksiazki (autor, tytul, czyWypozyczona,czytelnik) VALUES ('" + author + "', '" + title + "', '" + czyDostepna + "', '" + czytelnik + "')";
            stmt3->executeUpdate(query);

            delete stmt3;

            cout << "Ksiazka dodana pomyslnie!" << endl;
        }
        catch (SQLException& e) {
            cout << "SQL Exception: " << e.what() << endl; // Wyświetl błąd w przypadku wystąpienia wyjątku
        }
     }
    void borrowBook(Connection* con) {
        int index;
        cout << "Ktora ksiazke chcesz wypozyczyc? Podaj indeks: ";
        cin >> index;
        cin.ignore();
        try {
            Statement* stmt4 = con->createStatement();

            // Sprawdź, czy książka istnieje
            ResultSet* res = stmt4->executeQuery("SELECT * FROM ksiazki WHERE id = " + to_string(index));
            if (res->next()) {
                bool czyWypozyczona = res->getBoolean("czyWypozyczona");
                if (!czyWypozyczona) {
                    string czytelnik;
                    cout << "Podaj imie i nazwisko czytelnika: ";
                    getline(cin >> ws, czytelnik);

                    // Zaktualizuj dane wypożyczenia książki w bazie danych
                    string query = "UPDATE ksiazki SET czyWypozyczona = true, czytelnik = '" + czytelnik + "' WHERE id = " + to_string(index);
                    stmt4->executeUpdate(query);

                    cout << "Ksiazka zostala wypozyczona przez " << czytelnik << "." << endl;
                }
                else {
                    cout << "Ksiazka jest juz wypozyczona." << endl;
                }
            }
            else {
                cout << "Ksiazka o podanym indeksie nie istnieje." << endl;
            }

            delete stmt4;
        }
        catch (SQLException& e) {
            cout << "SQL Exception: " << e.what() << endl; // Wyświetl błąd w przypadku wystąpienia wyjątku
        }
    }
    void returnBook(Connection* con) {
        int index;
        cout << "Ktora ksiazke chcesz zwrocic? Podaj indeks: ";
        cin >> index;
        cin.ignore();
        try {
            Statement* stmt5 = con->createStatement();
            // Sprawdź, czy indeks książki jest prawidłowy
            // Zapytanie SQL aktualizujące rekord książki
            string query = "UPDATE ksiazki SET czyWypozyczona = 'Nie', czytelnik = '' WHERE id = " + to_string(index);
            stmt5->executeUpdate(query);
            cout << "Ksiazka " << " zostala zwrocona." << endl;
            delete stmt5;
        }
        catch (SQLException& e) {
            cout << "SQL Exception: " << e.what() << endl; // Wyświetl błąd w przypadku wystąpienia wyjątku
        }
    }
};

int main() {
    Connection* con = connectToDatabase();
    book Book;
    int wybor;
    do {
        cout << "1 - dodaj ksiazke " << endl;
        cout << "2 - zobacz nasza biblioteke" << endl;
        cout << "3 - wypozycz dostepna ksiazke" << endl;
        cout << "4 - oddaj ksiazke" << endl;
        cout << "0 - wyjscie z programu" << endl;
        cin >> wybor;
        switch (wybor) {
        case 1:
            Book.addBook(con);
            break;
        case 2:
            Book.display(con);
            break;
        case 3:
            Book.borrowBook(con);
            break;
        case 4:
            Book.returnBook(con);
            break;
        default:
            cout << "Zly znak";
            break;
        }
    } while (wybor != 0);
    return 0;
}