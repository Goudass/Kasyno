#pragma once
#include <string>

typedef struct Karta
{
	std::string symbol;
	std::string kolor;
	int wartosc;
} Karta;

class TaliaKart
{
public:
	TaliaKart();
	void potasujKarty();
	Karta wezKarte();

private:
	Karta karty[52];
	int aktualnaPozycja;
};

