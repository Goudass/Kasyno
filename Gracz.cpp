#include "Gracz.h"
#include <iostream>

Gracz::Gracz()
{
	// Losowa wartoœæ od 500 do 1500;
	this->pieniadze = 500 + (std::rand() % 1001);
}
