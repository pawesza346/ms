#ifndef FUNKCJE_H
#define FUNKCJE_H
#include"struktury.h"

void dodaj_konkurs(konkurs*& glowa, string nazwa);

void edytuj_konkurs(konkurs *& glowa, string miejsce_szuk);

void edytuj_zawodnika(konkurs *& glowa);

void ranking(konkurs *& glowa);

void wyswietl_konkurs(konkurs *&glowa, string miejsce);

void wyswietl_zawodnika(konkurs *&glowa, string nazwisk);

void zapisz_zmiany(konkurs*&glowa, string zapis);

#endif