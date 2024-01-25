#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "Gracz.h"
#include "Gra.h"
#include "BlackJack.h"
#include "JednorekiBandyta.h"
#include "Ruletka.h"

void zapiszWynik(Gracz& gracz)
{
    Gracz top100[101];
    int iloscWynikow = 0;
    std::fstream plik;

    plik.open("wyniki.txt", std::ios::in);
    if (plik.is_open()) 
    {
        while (plik.eof() == false && iloscWynikow < 100)
        {
            plik >> top100[iloscWynikow].imie;
            plik >> top100[iloscWynikow].pieniadze;

            if (top100[iloscWynikow].imie.empty() == false)
            {
                iloscWynikow++;
            }
        }
        plik.close();
    }

    top100[iloscWynikow++] = gracz;

    for (int i = 0; i < iloscWynikow - 1; i++)
    {
        for (int j = 0; j < iloscWynikow - i - 1; j++)
        {
            if (top100[j].pieniadze < top100[j + 1].pieniadze)
            {
                Gracz tmp = top100[j];
                top100[j] = top100[j + 1];
                top100[j + 1] = tmp;
            }
        }
    }

    if (iloscWynikow > 100) iloscWynikow = 100;

    plik.open("wyniki.txt", std::ios::out);
    for (int i = 0; i < iloscWynikow; i++)
    {
        plik << top100[i].imie << "\t" << top100[i].pieniadze;

        if (i < iloscWynikow - 1)
        {
            plik << std::endl;
        }
    }
    plik.close();
}

int main()
{
    std::srand((unsigned int)std::time(nullptr));

    int opcja = -1;
    Gracz gracz;
    Gra* gry[3] = { new BlackJack(gracz), new JednorekiBandyta(gracz), new Ruletka(gracz)};

    std::cout << "Imie gracza: ";
    std::cin >> gracz.imie;

    while (opcja != 0)
    {
        std::cout << "Pieniadze gracza " << gracz.imie << ": " << gracz.pieniadze << "zl" << std::endl;
        std::cout << "Wybierz gre:" << std::endl;
        std::cout << "[1] BlackJack" << std::endl;
        std::cout << "[2] Jednoreki Bandyta" << std::endl;
        std::cout << "[3] Ruletka" << std::endl;
        std::cout << "[0] Zapis wyniku i wyjscie" << std::endl;
        std::cin >> opcja;

        if (opcja < 0 || opcja > 3)
        {
            std::cout << "Niepoprawna wartosc!" << std::endl;
            continue;
        }
        else if (opcja == 0)
        {
            break;
        }

        gry[opcja - 1]->graj();
    }

    zapiszWynik(gracz);
}