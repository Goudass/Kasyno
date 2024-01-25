#include "BlackJack.h"
#include <iostream>

BlackJack::BlackJack(Gracz& _gracz) : Gra(_gracz)
{
	this->iloscKartGracza = 0;
	this->iloscKartKomputera = 0;
	this->pula = 0;
	this->stawkaGracza = 0;
}

void BlackJack::graj()
{
	this->iloscKartGracza = 0;
	this->iloscKartKomputera = 0;

	this->taliaKart.potasujKarty();
	this->pula = 200 + (std::rand() % 801);

	this->kartyGracza[iloscKartGracza++] = taliaKart.wezKarte();
	this->kartyKomputera[iloscKartKomputera++] = taliaKart.wezKarte();

	std::cout << "Pula: " << this->pula << "zl" << std::endl;
	std::cout << "Karty gracza " << this->gracz.imie << ": ";
	this->pokazKarty(this->kartyGracza, iloscKartGracza);
	std::cout << std::endl << "Pieniadze gracza " << this->gracz.imie << ": " << this->gracz.pieniadze << "zl" << std::endl;
	std::cout << "Podaj stawke gracza. \"0\" aby wyjsc." << std::endl;
	std::cout << "Stawka = ";
	std::cin >> this->stawkaGracza;

	if (this->stawkaGracza == 0)
	{
		return;
	}

	while (this->stawkaGracza > this->gracz.pieniadze || this->stawkaGracza > this->pula)
	{
		if (this->stawkaGracza > this->gracz.pieniadze)
		{
			std::cout << "Nie posiadasz takiej ilosc pieniedzy!" << std::endl;
		}
		else
		{
			std::cout << "Twoja stawka nie moze byc wieksza od puli!" << std::endl;
		}

		std::cout << "Stawka = ";
		std::cin >> this->stawkaGracza;
	}

	std::cout << std::endl;

	int opcja = -1;

	while (opcja != 2)
	{
		std::cout << "Wybierz opcje:" << std::endl;
		std::cout << "[1] Dobierz karte" << std::endl;
		std::cout << "[2] Zakoncz dobieranie" << std::endl;
		std::cin >> opcja;

		if (opcja == 1)
		{
			this->kartyGracza[iloscKartGracza++] = taliaKart.wezKarte();
		}
		else if (opcja == 2)
		{
			break;
		}
		else
		{
			std::cout << "Niepoprawna opcja!" << std::endl;
		}

		std::cout << "Karty gracza " << this->gracz.imie << ": ";
		this->pokazKarty(this->kartyGracza, iloscKartGracza);
		std::cout << std::endl;

		if (this->policzPunkty(this->kartyGracza, iloscKartGracza) > 21)
		{
			std::cout << "Przekroczono 21 punktow - przegrana!" << std::endl;
			this->gracz.pieniadze -= this->stawkaGracza;
			return;
		}
	}

	std::cout << "Ruch komputera" << std::endl;

	while (this->policzPunkty(this->kartyKomputera, iloscKartKomputera) < 18)
	{
		this->kartyKomputera[iloscKartKomputera++] = taliaKart.wezKarte();

		std::cout << "Komputer dobral karte" << std::endl;

		std::cout << "Karty komputera " << ": ";
		this->pokazKarty(this->kartyKomputera, iloscKartKomputera);
		std::cout << std::endl;
	}

	int punktyGracza = this->policzPunkty(this->kartyGracza, iloscKartGracza);
	int punktyKomputera = this->policzPunkty(this->kartyKomputera, iloscKartKomputera);

	std::cout << "Punkty gracza: " << punktyGracza << std::endl;
	std::cout << "Punkty komputera: " << punktyKomputera << std::endl;

	if (punktyKomputera > 21 || (punktyGracza > punktyKomputera))
	{
		std::cout << "Gracz " << this->gracz.imie << " wygral " << this->pula << "zl" << std::endl;
		this->gracz.pieniadze += this->pula;
	}
	else if (punktyGracza <= punktyKomputera)
	{
		std::cout << "Gracz " << this->gracz.imie << " przegral" << std::endl;
		this->gracz.pieniadze -= this->stawkaGracza;
	}
}

void BlackJack::pokazKarty(Karta* karty, int ilosc)
{
	for (int i = 0; i < ilosc; i++)
	{
		std::cout << karty[i].symbol << "-" << karty[i].kolor << " ";
	}

	std::cout << "(Punkty: " << this->policzPunkty(karty, ilosc) << ")";
}

int BlackJack::policzPunkty(Karta* karty, int ilosc)
{
	int wynik = 0;

	for (int i = 0; i < ilosc; i++)
	{
		wynik += karty[i].wartosc;
	}

	return wynik;
}
