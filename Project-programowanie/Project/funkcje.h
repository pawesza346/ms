#ifndef FUNKCJE_H
#define FUNKCJE_H
#include"Struktury.h"

/**Funkcja tworzy listy konkursów i dodaje do nich skoczków z pliku
@param glowa wskaznik na g³owê listy
@param nazwa nazwa pliku z którego nale¿y pobraæ dane
*/
void dodaj_konkurs(konkurs*& glowa, string nazwa);

/**Funkcja edytuje dane dotycz¹ce konkursów
@param glowa wskaznik na g³owê listy konkursów
@param miejsce_szuk nazwa wskazuj¹ca który konkurs urzytkownik chce edytowaæ
*/
void edytuj_konkurs(konkurs *& glowa, string miejsce_szuk);

/**Funkcja edytuje dane dotycz¹ce zawodnika
@param glowa wskaznik na g³owê listy konkursów
*/
void edytuj_zawodnika(konkurs *& glowa);

/**Funkcja tworzy ranking zawodników i narodowoœci
@param glowa wskaznik na g³owê listy konkursów
*/
void ranking(konkurs *& glowa);

/**Funkcja wyœwietla posortowane wed³ug pozycji wyniki z danego konkursu
@param glowa wskaznik na g³owê listy konkursów
@param miejsce miejsce konkursu którego wyniki urzytkownik chce zobaczyæ
*/
void wyswietl_konkurs(konkurs *&glowa, string miejsce);

/**Funkcja wyœwietla posortowane wed³ug daty wystêpy zawodnika
@param glowa wskaznik na g³owê listy konkursów
@param nazwisk nazwisko zawodnika którego wyniki chce zobaczyæ u¿ytkownik
*/
void wyswietl_zawodnika(konkurs *&glowa, string nazwisk);

/**Funkcja zapisuje zmiany jakie naniós³ u¿ytkownik
@param glowa wskaznik na g³owê listy konkursów
@param zapis nazwa pliku podana przez urzytkownika przy uruchamianiu programu, do której zostan¹ zapisane zmiany
*/
void zapisz_zmiany(konkurs*&glowa, string zapis);

/**Funkcja usuwa listê skoczków
@param pHead wskaŸnik na g³owê listy skoczków
*/
void usunskoczkow(skoczek * & pHead);

/**Funkcja usuwa listê konkursów
@param pHead wskaŸnik na g³owê listy konkursów
*/
void usunkonkursy(konkurs * & pHead);

#endif#pragma once
