#ifndef FUNKCJE_H
#define FUNKCJE_H
#include"Struktury.h"

/**Funkcja tworzy listy konkurs�w i dodaje do nich skoczk�w z pliku
@param glowa wskaznik na g�ow� listy
@param nazwa nazwa pliku z kt�rego nale�y pobra� dane
*/
void dodaj_konkurs(konkurs*& glowa, string nazwa);

/**Funkcja edytuje dane dotycz�ce konkurs�w
@param glowa wskaznik na g�ow� listy konkurs�w
@param miejsce_szuk nazwa wskazuj�ca kt�ry konkurs urzytkownik chce edytowa�
*/
void edytuj_konkurs(konkurs *& glowa, string miejsce_szuk);

/**Funkcja edytuje dane dotycz�ce zawodnika
@param glowa wskaznik na g�ow� listy konkurs�w
*/
void edytuj_zawodnika(konkurs *& glowa);

/**Funkcja tworzy ranking zawodnik�w i narodowo�ci
@param glowa wskaznik na g�ow� listy konkurs�w
*/
void ranking(konkurs *& glowa);

/**Funkcja wy�wietla posortowane wed�ug pozycji wyniki z danego konkursu
@param glowa wskaznik na g�ow� listy konkurs�w
@param miejsce miejsce konkursu kt�rego wyniki urzytkownik chce zobaczy�
*/
void wyswietl_konkurs(konkurs *&glowa, string miejsce);

/**Funkcja wy�wietla posortowane wed�ug daty wyst�py zawodnika
@param glowa wskaznik na g�ow� listy konkurs�w
@param nazwisk nazwisko zawodnika kt�rego wyniki chce zobaczy� u�ytkownik
*/
void wyswietl_zawodnika(konkurs *&glowa, string nazwisk);

/**Funkcja zapisuje zmiany jakie nani�s� u�ytkownik
@param glowa wskaznik na g�ow� listy konkurs�w
@param zapis nazwa pliku podana przez urzytkownika przy uruchamianiu programu, do kt�rej zostan� zapisane zmiany
*/
void zapisz_zmiany(konkurs*&glowa, string zapis);

/**Funkcja usuwa list� skoczk�w
@param pHead wska�nik na g�ow� listy skoczk�w
*/
void usunskoczkow(skoczek * & pHead);

/**Funkcja usuwa list� konkurs�w
@param pHead wska�nik na g�ow� listy konkurs�w
*/
void usunkonkursy(konkurs * & pHead);

#endif#pragma once
