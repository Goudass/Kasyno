#pragma once
#include <string>
#include "Gra.h"

class JednorekiBandyta : public Gra
{
public:
	JednorekiBandyta(Gracz& _gracz);
	void graj() override;

private:
	int losowanie(int stopienWygranej);
	int ilePowtorzen(std::string wynik, char znak);
};

