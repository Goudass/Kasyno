#include "Ruletka.h"
#include <iostream>

Ruletka::Ruletka(Gracz& _gracz)
	: Gra(_gracz)
	, polaCzerwone {1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36}
	, polaCzarne {2, 4, 6, 8, 10, 11, 13, 15, 17, 20, 22, 24, 26, 28, 29, 31, 33, 35}
{
	this->iloscZakladow = 0;
}

void Ruletka::graj()
{
	this->iloscZakladow = 0;
	int opcja = -1;

	while (opcja != 0)
	{
		std::cout << "Pieniadze gracza " << this->gracz.imie << ": " << this->gracz.pieniadze << "zl" << std::endl;
		std::cout << "Wybierz opcje:" << std::endl;
		std::cout << "[1] Dodaj zaklad" << std::endl;
		std::cout << "[2] Zakoncz obstawianie" << std::endl;
		std::cout << "[0] Wyjscie do menu" << std::endl;
		std::cin >> opcja;

		while (opcja < 0 || opcja > 2)
		{
			std::cout << "Niepoprawna wartosc!" << std::endl;
			std::cin >> opcja;
		}

		if (opcja == 0)
		{
			if (this->iloscZakladow > 0)
			{
				std::cout << "Nie mozna wyjsc! Ilosc zakladow: " << this->iloscZakladow << std::endl;
				opcja = -1;
			}
			else
			{
				return;
			}
		}
		else if (opcja == 1)
		{
			this->dodajZaklad();
		}
		else if (opcja == 2)
		{
			int wylosowanaLiczba = std::rand() % 37;
			std::cout << "Wypadla liczba: " << wylosowanaLiczba << std::endl;
			this->sprawdzZaklady(wylosowanaLiczba);
			opcja = 0;
		}

		std::cout << std::endl;
	}
}

void Ruletka::pokazPoleGry()
{
	std::cout << "+----+----+----+----+----+----+----+----+----+----+----+----+----+-----------+" << std::endl;
	std::cout << "|    |  3 |  6 |  9 | 12 | 15 | 18 | 21 | 24 | 27 | 30 | 33 | 36 |  1st col  |" << std::endl;
	std::cout << "+    +----+----+----+----+----+----+----+----+----+----+----+----+-----------+" << std::endl;
	std::cout << "|  0 |  2 |  5 |  8 | 11 | 14 | 17 | 20 | 23 | 26 | 29 | 32 | 35 |  2nd col  |" << std::endl;
	std::cout << "+    +----+----+----+----+----+----+----+----+----+----+----+----+-----------+" << std::endl;
	std::cout << "|    |  1 |  4 |  7 | 10 | 13 | 16 | 19 | 22 | 25 | 28 | 31 | 34 |  3rd col  |" << std::endl;
	std::cout << "+----+----+----+----+----+----+----+----+----+----+----+----+----+-----------+" << std::endl;
	std::cout << "     |       1st 12      |       2nd 12      |       3rd 12      |" << std::endl;
	std::cout << "     +-------------------+-------------------+-------------------+" << std::endl;
}

void Ruletka::dodajZaklad()
{
	int opcja;
	int liczby[6];
	int liczba;
	int stawkaGracza;
	Zaklad nowyZaklad;

	if (this->iloscZakladow == 10)
	{
		std::cout << "Limit 10 zakladow osiagniety!" << std::endl;
		return;
	}

	this->pokazPoleGry();

	std::cout << "Wybierz typ zakladu:" << std::endl;
	std::cout << "[1]  Jedna liczba" << std::endl;
	std::cout << "[2]  Dwie liczby" << std::endl;
	std::cout << "[3]  Trzy liczby" << std::endl;
	std::cout << "[4]  Cztery liczby" << std::endl;
	std::cout << "[5]  Szesc liczb" << std::endl;
	std::cout << "[6]  Kolumna" << std::endl;
	std::cout << "[7]  Tuzin" << std::endl;
	std::cout << "[8]  Parzyste" << std::endl;
	std::cout << "[9]  Nieparzyste" << std::endl;
	std::cout << "[10] Czerwone" << std::endl;
	std::cout << "[11] Czarne" << std::endl;
	std::cout << "[12] Liczby 1-18" << std::endl;
	std::cout << "[13] Liczby 19-36" << std::endl;
	std::cout << "[0]  Powrot" << std::endl;
	std::cin >> opcja;

	if (opcja < 0 || opcja > 13)
	{
		std::cout << "Niepoprawna opcja!" << std::endl;
		return;
	}
	else if (opcja == 0)
	{
		return;
	}

	std::cout << "Stawka gracza: ";
	std::cin >> stawkaGracza;

	if (stawkaGracza > this->gracz.pieniadze)
	{
		std::cout << "Nie posiadasz takiej ilosci pieniedzy!" << std::endl;
		return;
	}

	if (opcja == 1)
	{
		std::cout << "Podaj liczbe" << std::endl;
		std::cin >> liczba;

		if (this->pobierzLiczby(nowyZaklad.liczby, 1, liczba) == false)
		{
			return;
		}

		nowyZaklad.rodzaj = RodzajZakladu::JednaLiczba;
		nowyZaklad.mozliwaWygrana = stawkaGracza * 35;
	}
	else if (opcja == 2)
	{
		std::cout << "Podaj pierwsza liczbe po prawej stronie" << std::endl;
		std::cin >> liczba;

		if (this->pobierzLiczby(nowyZaklad.liczby, 2, liczba) == false)
		{
			return;
		}

		nowyZaklad.rodzaj = RodzajZakladu::DwieLiczby;
		nowyZaklad.mozliwaWygrana = stawkaGracza * 17;
	}
	else if (opcja == 3)
	{
		std::cout << "Podaj pierwsza liczbe po prawej stronie" << std::endl;
		std::cin >> liczba;

		if (this->pobierzLiczby(nowyZaklad.liczby, 3, liczba) == false)
		{
			return;
		}

		nowyZaklad.rodzaj = RodzajZakladu::TrzyLiczby;
		nowyZaklad.mozliwaWygrana = stawkaGracza * 11;
	}
	else if (opcja == 4)
	{
		std::cout << "Podaj pierwsza liczbe w prawym gornym rogu" << std::endl;
		std::cin >> liczba;

		if (this->pobierzLiczby(nowyZaklad.liczby, 4, liczba) == false)
		{
			return;
		}

		nowyZaklad.rodzaj = RodzajZakladu::CzteryLiczby;
		nowyZaklad.mozliwaWygrana = stawkaGracza * 8;
	}
	else if (opcja == 5)
	{
		std::cout << "Podaj pierwsza liczbe w prawym gornym rogu" << std::endl;
		std::cin >> liczba;

		if (this->pobierzLiczby(nowyZaklad.liczby, 6, liczba) == false)
		{
			return;
		}

		nowyZaklad.rodzaj = RodzajZakladu::SzescLiczb;
		nowyZaklad.mozliwaWygrana = stawkaGracza * 5;
	}
	else if (opcja == 6)
	{
		std::cout << "Ktora kolumna (1, 2, 3)?" << std::endl;
		std::cin >> liczba;

		if (liczba < 1 || liczba > 3)
		{
			std::cout << "Niepoprawna wartosc!" << std::endl;
			return;
		}

		nowyZaklad.rodzaj = RodzajZakladu::Kolumna;
		nowyZaklad.mozliwaWygrana = stawkaGracza * 3;
		nowyZaklad.liczby[0] = liczba;
	}
	else if (opcja == 7)
	{
		std::cout << "Ktory tuzin (1, 2, 3)?" << std::endl;
		std::cin >> liczba;

		if (liczba < 1 || liczba > 3)
		{
			std::cout << "Niepoprawna wartosc!" << std::endl;
			return;
		}

		nowyZaklad.rodzaj = RodzajZakladu::Tuzin;
		nowyZaklad.mozliwaWygrana = stawkaGracza * 3;
		nowyZaklad.liczby[0] = liczba;
	}
	else if (opcja == 8)
	{
		nowyZaklad.rodzaj = RodzajZakladu::Parzyste;
		nowyZaklad.mozliwaWygrana = stawkaGracza * 2;
	}
	else if (opcja == 9)
	{
		nowyZaklad.rodzaj = RodzajZakladu::Nieparzyste;
		nowyZaklad.mozliwaWygrana = stawkaGracza * 2;
	}
	else if (opcja == 10)
	{
		nowyZaklad.rodzaj = RodzajZakladu::Czerwone;
		nowyZaklad.mozliwaWygrana = stawkaGracza * 2;
	}
	else if (opcja == 11)
	{
		nowyZaklad.rodzaj = RodzajZakladu::Czarne;
		nowyZaklad.mozliwaWygrana = stawkaGracza * 2;
	}
	else if (opcja == 12)
	{
		nowyZaklad.rodzaj = RodzajZakladu::Liczby1_18;
		nowyZaklad.mozliwaWygrana = stawkaGracza * 2;
	}
	else if (opcja == 13)
	{
		nowyZaklad.rodzaj = RodzajZakladu::Liczby19_36;
		nowyZaklad.mozliwaWygrana = stawkaGracza * 2;
	}

	this->gracz.pieniadze -= stawkaGracza;
	this->zaklady[this->iloscZakladow++] = nowyZaklad;
	std::cout << "Nowy zaklad dodany. Mozliwa wygrana: " << nowyZaklad.mozliwaWygrana << "zl" << std::endl;
}

bool Ruletka::pobierzLiczby(int* tablica, int iloscLiczb, int pierwszaLiczba)
{
	if (pierwszaLiczba < 0 || pierwszaLiczba > 36 || 
		(iloscLiczb > 1 && pierwszaLiczba == 0) ||
		(iloscLiczb == 3 && pierwszaLiczba < 4))
	{
		std::cout << "Niepoprawna wartosc!" << std::endl;
		return false;
	}

	if (iloscLiczb == 1)
	{
		tablica[0] = pierwszaLiczba;
	}
	else if (iloscLiczb == 2)
	{
		tablica[0] = pierwszaLiczba;
		tablica[1] = pierwszaLiczba - 3;
	}
	else if (iloscLiczb == 3)
	{
		tablica[0] = pierwszaLiczba;
		tablica[1] = pierwszaLiczba - 3;
		tablica[2] = pierwszaLiczba - 6;

		if (tablica[2] < 0) tablica[2] = 0;
	}
	else if (iloscLiczb == 4)
	{
		for (int i = 1; i <= 34; i += 3)
		{
			if (i == pierwszaLiczba)
			{
				std::cout << "Niepoprawna wartosc!" << std::endl;
				return false;
			}
		}

		tablica[0] = pierwszaLiczba;
		tablica[1] = pierwszaLiczba - 3;
		tablica[2] = tablica[0] - 1;
		tablica[3] = tablica[1] - 1;

		if (tablica[1] < 0) tablica[1] = 0;
		if (tablica[3] < 0) tablica[3] = 0;
	}
	else if (iloscLiczb == 6)
	{
		bool poprawnaLiczba = false;
		for (int i = 3; i <= 36; i += 3)
		{
			if (i == pierwszaLiczba)
			{
				poprawnaLiczba = true;
				break;
			}
		}
		if (poprawnaLiczba == false)
		{
			std::cout << "Niepoprawna wartosc!" << std::endl;
			return false;
		}

		tablica[0] = pierwszaLiczba;
		tablica[1] = pierwszaLiczba - 3;
		tablica[2] = tablica[0] - 1;
		tablica[3] = tablica[1] - 1;
		tablica[4] = tablica[0] - 2;
		tablica[5] = tablica[1] - 2;

		if (tablica[1] < 0) tablica[1] = 0;
		if (tablica[3] < 0) tablica[3] = 0;
		if (tablica[5] < 0) tablica[5] = 0;
	}

	return true;
}

void Ruletka::sprawdzZaklady(int wylosowanaLiczba)
{
	bool wygrana = false;
	int pierwszaLiczba, ostatniaLiczba;

	for (int i = 0; i < this->iloscZakladow; i++)
	{
		std::cout << "Zaklad " << (i + 1) << "/" << this->iloscZakladow << ": ";

		switch (this->zaklady[i].rodzaj)
		{
		case RodzajZakladu::JednaLiczba:
			if (this->zaklady[i].liczby[0] == wylosowanaLiczba)
			{
				wygrana = true;
			}
			break;

		case RodzajZakladu::DwieLiczby:
			for (int j = 0; j < 2; j++)
			{
				if (this->zaklady[i].liczby[j] == wylosowanaLiczba)
				{
					wygrana = true;
					break;
				}
			}
			break;

		case RodzajZakladu::TrzyLiczby:
			for (int j = 0; j < 3; j++)
			{
				if (this->zaklady[i].liczby[j] == wylosowanaLiczba)
				{
					wygrana = true;
					break;
				}
			}
			break;

		case RodzajZakladu::CzteryLiczby:
			for (int j = 0; j < 4; j++)
			{
				if (this->zaklady[i].liczby[j] == wylosowanaLiczba)
				{
					wygrana = true;
					break;
				}
			}
			break;

		case RodzajZakladu::SzescLiczb:
			for (int j = 0; j < 6; j++)
			{
				if (this->zaklady[i].liczby[j] == wylosowanaLiczba)
				{
					wygrana = true;
					break;
				}
			}
			break;

		case RodzajZakladu::Kolumna:
			pierwszaLiczba = 4 - zaklady[i].liczby[0];
			ostatniaLiczba = 37 - zaklady[i].liczby[0];

			for (int j = pierwszaLiczba; j <= ostatniaLiczba; j += 3)
			{
				if (j == wylosowanaLiczba)
				{
					wygrana = true;
					break;
				}
			}
			break;

		case RodzajZakladu::Tuzin:
			pierwszaLiczba = (12 * (zaklady[i].liczby[0] - 1)) + 1;
			ostatniaLiczba = pierwszaLiczba + 11;

			for (int j = pierwszaLiczba; j <= ostatniaLiczba; j++)
			{
				if (j == wylosowanaLiczba)
				{
					wygrana = true;
					break;
				}
			}
			break;

		case RodzajZakladu::Parzyste:
			if (wylosowanaLiczba % 2 == 0)
			{
				wygrana = true;
			}
			break;

		case RodzajZakladu::Nieparzyste:
			if (wylosowanaLiczba % 2 != 0)
			{
				wygrana = true;
			}
			break;

		case RodzajZakladu::Czerwone:
			for (int j = 0; j < 18; j++)
			{
				if (wylosowanaLiczba == this->polaCzerwone[j])
				{
					wygrana = true;
					break;
				}
			}
			break;

		case RodzajZakladu::Czarne:
			for (int j = 0; j < 18; j++)
			{
				if (wylosowanaLiczba == this->polaCzarne[j])
				{
					wygrana = true;
					break;
				}
			}
			break;

		case RodzajZakladu::Liczby1_18:
			if (wylosowanaLiczba >= 1 && wylosowanaLiczba <= 18)
			{
				wygrana = true;
			}
			break;

		case RodzajZakladu::Liczby19_36:
			if (wylosowanaLiczba >= 19 && wylosowanaLiczba <= 36)
			{
				wygrana = true;
			}
			break;
		}

		if (wygrana)
		{
			this->gracz.pieniadze += this->zaklady[i].mozliwaWygrana;
			std::cout << "wygrana " << this->zaklady[i].mozliwaWygrana << "zl" << std::endl;
			wygrana = false;
		}
		else
		{
			std::cout << "brak wygranej" << std::endl;
		}
	}
}
