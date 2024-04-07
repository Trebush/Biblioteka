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
3. Upewnij się, że serwer MySQL jest uruchomiony.
4. Dodaj bazę danych na serwer MySQL.
5. Skompiluj program `biblioteka.exe`.
6. Uruchom program `biblioteka.exe`.

### Użycie

Program posiada menu, które umożliwia wybór opcji:

1. **Dodaj książkę:** Pozwala na dodanie nowej książki do bazy danych. Użytkownik musi podać tytuł, autora, informację o dostępności oraz imię i nazwisko czytelnika (w przypadku wypożyczenia).
2. **Zobacz naszą bibliotekę:** Wyświetla listę wszystkich książek w bazie danych, wraz z informacją o ich dostępności i wypożyczeniu.
3. **Wypożycz dostępną książkę:** Użytkownik wybiera książkę z listy dostępnych pozycji i podaje swoje imię i nazwisko. Książka zostaje oznaczona jako wypożyczona w bazie danych.
4. **Oddaj książkę:** Użytkownik wybiera książkę, którą chce zwrócić. Książka zostaje oznaczona jako dostępna w bazie danych.
5. **Wyjście z programu:** Zamyka program.

### Kontakt

Jeśli masz pytania lub uwagi dotyczące programu, skontaktuj się z autorem.
