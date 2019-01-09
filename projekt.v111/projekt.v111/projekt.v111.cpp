$include"PCH.h"
#include"funkcje.h"
int main() {
	string nazwa = "zawodnicy.txt";
	konkurs*glowa = NULL;
	dodaj_konkurs(glowa, nazwa);
	wyswietl2(glowa);
	cin.get();
}