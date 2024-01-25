#include "TaliaKart.h"

TaliaKart::TaliaKart()
{
	std::string kolorStr[4] = { "Tr", "Ka", "Ki", "Pi" };
	std::string symbolStr[13] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };

	int kartaIndex = 0;

	for (int kolor = 0; kolor < 4; kolor++)
	{
		for (int symbol = 0; symbol < 13; symbol++)
		{
			this->karty[kartaIndex].kolor = kolorStr[kolor];
			this->karty[kartaIndex].symbol = symbolStr[symbol];

			if (symbol >= 1 && symbol <= 9)
			{
				// Karty od 2 do 10
				this->karty[kartaIndex].wartosc = symbol + 1;
			}
			else if (symbol >= 10)
			{
				// Karty J, Q, K
				this->karty[kartaIndex].wartosc = symbol - 7;
			}
			else
			{
				// As
				this->karty[kartaIndex].wartosc = 11;
			}

			kartaIndex++;
		}
	}
}

void TaliaKart::potasujKarty()
{
	for (int i = 0; i < 150; i++)
	{
		int indexA = std::rand() % 52;
		int indexB = std::rand() % 52;

		Karta temp = this->karty[indexA];
		this->karty[indexA] = this->karty[indexB];
		this->karty[indexB] = temp;
	}

	this->aktualnaPozycja = 0;
}

Karta TaliaKart::wezKarte()
{
	this->aktualnaPozycja++;
	return this->karty[this->aktualnaPozycja - 1];
}
