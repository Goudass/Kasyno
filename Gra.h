#pragma once
#include "Gracz.h"

class Gra
{
public:
	virtual void graj() = 0;

protected:
	Gra(Gracz& _gracz);
	Gracz& gracz;
};

