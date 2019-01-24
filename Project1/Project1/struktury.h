#include<iostream>
#include<fstream>
#include<cstring>
#include<sstream>
#include<conio.h>
#include<vector>
#include<algorithm>
using namespace std;

const int tab_rank[] = {100, 80,60,50,45,40,36,32,29,26,24,22,20,18,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
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
