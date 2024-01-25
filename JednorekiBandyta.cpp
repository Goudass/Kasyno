#include "JednorekiBandyta.h"
#include <iostream>

JednorekiBandyta::JednorekiBandyta(Gracz& _gracz) : Gra(_gracz)
{
}

void JednorekiBandyta::graj()
{
	int stawkaGracza;
	int opcja = -1;
	int wygrana;

	while (opcja != 0)
	{
		std::cout << std::endl << "Pieniadze gracza " << this->gracz.imie << ": " << this->gracz.pieniadze << "zl" << std::endl;
		std::cout << "Za ile chcesz zagrac?" << std::endl;
		std::cout << "[1] 30zl" << std::endl;
		std::cout << "[2] 50zl" << std::endl;
		std::cout << "[3] 70zl" << std::endl;
		std::cout << "[0] Wyjscie do menu" << std::endl;
		std::cin >> opcja;

		if (opcja == 0)
		{
			break;
		}
		else if (opcja < 0 || opcja > 3)
		{
			std::cout << "Niepoprawna opcja!" << std::endl;
			continue;
		}

		stawkaGracza = 10 + (opcja * 20);

		if (stawkaGracza > this->gracz.pieniadze)
		{
			std::cout << "Nie posiadasz takiej ilosc pieniedzy!" << std::endl;
			continue;
		}

		wygrana = this->losowanie(opcja);

		if (wygrana > 0)
		{
			std::cout << "Gracz " << this->gracz.imie << " wygral " << wygrana << "zl" << std::endl;
			this->gracz.pieniadze += wygrana;
		}
		else
		{
			std::cout << "Gracz " << this->gracz.imie << " przegral " << stawkaGracza << "zl" << std::endl;
			this->gracz.pieniadze -= stawkaGracza;
		}
	}
}

int JednorekiBandyta::losowanie(int stopienWygranej)
{
	std::string wynikLosowania;
	int powtorzenia;

	for (int i = 0; i < 3; i++)
	{
		wynikLosowania += std::to_string(1 + (std::rand() % 9));
	}

	std::cout << "Wynik losowania: --" << wynikLosowania << "--" << std::endl;

	for (int i = 1; i < 10; i++)
	{
		powtorzenia = this->ilePowtorzen(wynikLosowania, '0' + i);

		if (powtorzenia > 1)
		{
			return i * 20 * powtorzenia;
		}
	}

	return 0;
}

int JednorekiBandyta::ilePowtorzen(std::string wynik, char znak)
{
	int powtorzenia = 0;

	for (int i = 0; i < wynik.length(); i++)
	{ 
		if (wynik[i] == znak)
		{
			powtorzenia++;
		}
	}

	return powtorzenia;
}
