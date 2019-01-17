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
struct ranking_skoczkow {
	string nazwisko;
	string kraj;
	int il_punktow;
	ranking_skoczkow *naste;
};
struct ranking_krajow {
	string kraj;
	int il_punktow1;
	ranking_krajow *nastep;
};
