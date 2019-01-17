#include<iostream>
#include<fstream>
#include<cstring>
#include<sstream>
#include<conio.h>
#include<vector>
#include<algorithm>
using namespace std;

struct skoczek {
	string nazwisko;
	string kraj;
	int pozycja;
	skoczek *nast;
};
struct konkurs {
	string data;
	string miejsce;
	struct skoczek *kol;
	konkurs *kolejny;
};
