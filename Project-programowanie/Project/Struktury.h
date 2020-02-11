#include<iostream>
#include<fstream>
#include<cstring>
#include<sstream>
#include<conio.h>
#include<vector>
#include<algorithm>
using namespace std;

const int tab_rank[] = { 100,80,60,50,45,40,36,32,29,26,24,22,20,18,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1 };
const int max_zaw = 30;
/** Komórka strutkury danych */
struct skoczek {
	string nazwisko;///< napis(nazwisko zawodnika)
	string kraj;///< napis(nazwa karju)
	int pozycja;///< numer(pozycja zawodnika)
	skoczek *nast;
};
/** Komórka listy podiweszonej */
struct konkurs {
	string data;///< napis(data konkursu)
	string miejsce;///< napis (miejsce konkursu)
	struct skoczek *kol;
	konkurs *kolejny;
};
