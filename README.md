# Symulator Gier Kasynowych

Witaj w Symulatorze Gier Kasynowych - aplikacji konsolowej napisanej w C++, która oferuje wirtualne doświadczenie popularnych gier kasynowych. Symulator zawiera takie gry jak BlackJack, Jednoręki Bandyta i Ruletka.

## Funkcje

- Wiele Gier: Wybierz jedną z trzech różnych gier kasynowych do gry.
- Zarządzanie Graczem: Śledź nazwę gracza i kredyty w trakcie rozgrywki.
- Trwałe Wyniki: Zapisuj i wczytuj 100 najlepszych wyników graczy za pomocą pliku tekstowego.

## Jak Grać

Po uruchomieniu programu zostaniesz poproszony o wprowadzenie nazwy gracza. Następnie zostaną wyświetlone dostępne gry, a Ty możesz wybrać grę, w którą chcesz zagrać, wprowadzając odpowiedni numer:
1. BlackJack
2. Jednoręki Bandyta
3. Ruletka

Po zakończeniu sesji gry Twój wynik zostanie automatycznie zapisany, jeśli znajduje się wśród 100 najlepszych. Możesz wyjść z programu, wprowadzając '0'.

## Zarządzanie Wynikami

Wyniki są zarządzane przez funkcję zapiszWynik, która sortuje najlepsze wyniki i zapisuje je do wyniki.txt. Zachowanych jest tylko 100 najlepszych wyników.
