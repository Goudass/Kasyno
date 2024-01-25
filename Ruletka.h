#pragma once
#include "Gra.h"

enum RodzajZakladu
{
	JednaLiczba,
	DwieLiczby,
	TrzyLiczby,
	CzteryLiczby,
	SzescLiczb,
	Kolumna,
	Tuzin,
	Parzyste,
	Nieparzyste,
	Czerwone,
	Czarne,
	Liczby1_18,
	Liczby19_36
};

typedef struct Zaklad
{
	RodzajZakladu rodzaj;
	int liczby[6];
	int mozliwaWygrana;
} Zaklad;

class Ruletka : public Gra
{
public:
	Ruletka(Gracz& _gracz);
	void graj() override;

private:
	void pokazPoleGry();
	void dodajZaklad();
	bool pobierzLiczby(int* tablica, int iloscLiczb, int pierwszaLiczba);
	void sprawdzZaklady(int wylosowanaLiczba);
	Zaklad zaklady[10];
	int iloscZakladow;
	int polaCzerwone[18];
	int polaCzarne[18];
};

