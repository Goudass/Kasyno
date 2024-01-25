#pragma once
#include "Gracz.h"
#include "Gra.h"
#include "TaliaKart.h"

class BlackJack : public Gra
{
public:
	BlackJack(Gracz& _gracz);
	void graj() override;
	void pokazKarty(Karta* karty, int ilosc);
	int policzPunkty(Karta* karty, int ilosc);

private:
	TaliaKart taliaKart;

	Karta kartyGracza[10];
	Karta kartyKomputera[10];
	int iloscKartGracza;
	int iloscKartKomputera;

	int pula;
	int stawkaGracza;
};

