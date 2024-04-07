# Biblioteka
## README.md

### Opis

Ten projekt to prosty program biblioteczny napisany w języku C++, który wykorzystuje MySQL do przechowywania informacji o książkach i czytelnikach. Program umożliwia:

* Dodawanie nowych książek do bazy danych
* Przeglądanie listy wszystkich książek
* Wyświetlanie tylko dostępnych książek
* Wypożyczanie książek przez czytelników
* Zwracanie książek

### Wymagania

* Kompilator C++
* Biblioteka MySQL Connector/C++ 
* Serwer MySQL

### Instalacja

1. Zainstaluj kompilator C++.
2. Zainstaluj bibliotekę MySQL Connector/C++.
3. Ustaw visual studio aby MySQL Connector/C++ (jeśli nie wiesz, https://www.youtube.com/watch?v=a_W4zt5sR1M - obejrz filmik)
4. Jeśli masz problem z libcrypto-3-x64.dll dodaj ścieżkie do PATH w zmienne Środowiskowe systemu jak w tym filmie https://www.youtube.com/watch?v=ggRohENBgek.
5. Upewnij się, że serwer MySQL jest uruchomiony.
6. Utwórz bazę danych 'biblioteka'.
7. Importuj do bazy danych biblioteke plik biblioteka.sql.
8. Skompiluj program `biblioteka.exe`.
9. Uruchom program `biblioteka.exe`.

### Użycie

Program posiada menu, które umożliwia wybór opcji:

1. **Dodaj książkę:** Pozwala na dodanie nowej książki do bazy danych. Użytkownik musi podać tytuł, autora, informację o dostępności oraz imię i nazwisko czytelnika (w przypadku wypożyczenia).
2. **Zobacz naszą bibliotekę:** Wyświetla listę wszystkich książek w bazie danych, wraz z informacją o ich dostępności i wypożyczeniu.
3. **Wypożycz dostępną książkę:** Użytkownik wybiera książkę z listy dostępnych pozycji i podaje swoje imię i nazwisko. Książka zostaje oznaczona jako wypożyczona w bazie danych.
4. **Oddaj książkę:** Użytkownik wybiera książkę, którą chce zwrócić. Książka zostaje oznaczona jako dostępna w bazie danych.
5. **Wyjście z programu:** Zamyka program.

### Kontakt

Jeśli masz pytania lub uwagi dotyczące programu, skontaktuj się z autorem.
