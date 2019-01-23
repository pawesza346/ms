#include"funkcje.h"
#include<vld.h>

void dodaj_konkurs(konkurs*& glowa, string nazwa)
{
	stringstream ss;
	string miejsce1, miejsce2, czas1, czas2, nazwisko1, nazwisko2, kraj1, kraj2, pozycja1, pozycja2;
	ifstream dane;
	dane.open(nazwa.c_str(), ios::in);
	dane >> miejsce1 >> czas1 >> nazwisko1 >> kraj1 >> pozycja1;
	konkurs* nowyy = new konkurs;
	nowyy = glowa;
	skoczek* gg = new skoczek;
	skoczek* g = new skoczek;
	g = gg;
	while (!dane.eof())
	{
		dane >> miejsce2 >> czas2 >> nazwisko2 >> kraj2 >> pozycja2;
		if (miejsce1 == miejsce2 and czas1 == czas2)
		{
			gg->nazwisko = nazwisko1;
			gg->kraj = kraj1;
			ss << pozycja1;
			ss >> gg->pozycja;
			ss.clear();
			skoczek* nowy = new skoczek;
			nowy->nast = NULL;
			gg->nast = nowy;
			gg = nowy;
			nazwisko1 = nazwisko2;
			kraj1 = kraj2;
			pozycja1 = pozycja2;
			miejsce1 = miejsce2;
			czas1 = czas2;
		}
		else
		{
			gg->nazwisko = nazwisko1;
			gg->kraj = kraj1;
			ss << pozycja1;
			ss >> gg->pozycja;
			ss.clear();
			nowyy->miejsce = miejsce1;
			nowyy->data = czas1;
			nowyy->kol = g; 
			konkurs* najnowszy = new konkurs;
			najnowszy->kolejny = NULL;
			nowyy->kolejny = najnowszy;
			nowyy=najnowszy;
			skoczek *nowy = new skoczek;
			nowy->nast = NULL;
			gg = nowy;
			g = gg;
			nazwisko1 = nazwisko2;
			kraj1 = kraj2;
			pozycja1 = pozycja2;
			miejsce1 = miejsce2;
			czas1 = czas2;
		}
	}
	if (miejsce1 == miejsce2 and czas1 == czas2)
	{
		gg->nazwisko = nazwisko1;
		gg->kraj = kraj1;
		ss << pozycja1;
		ss >> gg->pozycja;
		ss.clear();
		nowyy->miejsce = miejsce1;
		nowyy->data = czas1;
		nowyy->kol = g;
	}
	else
	{
		nowyy->miejsce = miejsce1;
		nowyy->data = czas1;
		nowyy->kol = g;
		gg = nullptr;
		konkurs* najnowszy = new konkurs;
		nowyy->kolejny = najnowszy;
		nowyy=najnowszy;
		nowyy->miejsce = miejsce2;
		nowyy->data = czas2;
		skoczek* g = new skoczek;
		nowyy->kol = g;
		g->nazwisko = nazwisko1;
		g->kraj = kraj1;
		ss << pozycja1;
		ss >> g->pozycja;
		ss.clear();
	}
	dane.close();
};

void edytuj_konkurs(konkurs *& glowa,string miejsce_szuk)
{
	
	konkurs* pomocniczy = new konkurs;
	pomocniczy = glowa;
	for (string szukane_miejsce = glowa->miejsce; szukane_miejsce != miejsce_szuk; szukane_miejsce = pomocniczy->miejsce)
		pomocniczy = pomocniczy->kolejny;
	cout << " jezeli chcesz edytowac nazwe konkursu wcisnij : 1 " << endl << " jezeli chcesz edytowac date konkursu wcisnij : 2 " << endl;
	char wybor;
	wybor = _getch();
	stringstream ss1;
	int wyb;
	string nowe;
	ss1 << wybor;
	ss1 >> wyb;
	switch (wyb) {
	case 1: {cout << endl << " podaj nowa nazwe " << endl;
		cin >> nowe;
		pomocniczy->miejsce = nowe;
		cout << endl << " zmiana zostala wykonana " << endl; break; }
	case 2: {cout << endl << " podaj nowa date " << endl;
		cin >> nowe;
		pomocniczy->data = nowe;
		cout << endl << " zmiana zostala wykonana " << endl; break; }
	default:{cout << endl << " podales zla wartosc, za chwile powrocisz do menu " << endl; break;}
	}
}

void edytuj_zawodnika(konkurs *& glowa) {
	string miejsce_konk, nazwiskoo;
	cout << endl << " podaj miejsce konkursu w ktorym chcesz edytowac zawodnika " << endl;
	cin >> miejsce_konk;
	konkurs *pomocniczy = new konkurs;
	pomocniczy = glowa;
	for (string szukane_miejsce = glowa->miejsce; szukane_miejsce != miejsce_konk; szukane_miejsce = pomocniczy->miejsce)
		pomocniczy = pomocniczy->kolejny;
	cout << endl << " podaj nazwisko zawodnika ktorego chcesz edytowac w konkursie : " << miejsce_konk << endl;
	cin >> nazwiskoo;
	skoczek *pomocniczyy = new skoczek;
	pomocniczyy = pomocniczy->kol;
	for (string szukane_nazwisko = pomocniczyy->nazwisko; szukane_nazwisko != nazwiskoo; szukane_nazwisko = pomocniczyy->nazwisko)
		pomocniczyy = pomocniczyy->nast;
	cout << " jezeli chcesz edytowac nazwisko skoczka wcisnij : 1 " << endl << " jezeli chcesz edytowac kraj skoczka wcisnij : 2 " << endl << " jezeli chcesz edytowac pozycje skoczka wcisnij : 3" << endl;
	char wybor;
	wybor = _getch();
	stringstream ss1;
	int wyb;
	string nowe;
	ss1 << wybor;
	ss1 >> wyb;
	ss1.clear();
	switch (wyb) {
	case 1: {cout << endl << " podaj nowe nazwisko skoczka " << endl;
		cin >> nowe;
		pomocniczyy->nazwisko = nowe;
		cout << endl << " zmiana zostala wykonana " << endl; break; }
	case 2: {cout << endl << " podaj nowy kraj skoczka " << endl;
		cin >> nowe;
		pomocniczyy->kraj = nowe;
		cout << endl << " zmiana zostala wykonana " << endl; break; }
	case 3: {cout << endl << " podaj nowa pozycje skoczka " << endl;
		cin >> nowe;
		ss1 << nowe;
		ss1 >> pomocniczyy->pozycja;
		cout << endl << " zmiana zostala wykonana " << endl; break; }
	default: {cout << endl << " podales zla wartosc, za chwile powrocisz do menu " << endl; break; }
	}
}

void ranking(konkurs *& glowa) {
	konkurs *pomocniczy = new konkurs;
	skoczek *pomocniczyy = new skoczek;
	int pozycjar, il = 0;
	string nazwiskor, krajr;
	bool czy_jest = false,czy_kraj = false;
	vector<string> rank;
	vector<string> rank1;
	vector<string> rank2;
	vector<string> rank3;
	vector<int>tab;
	vector<int>tab1;
	vector<int>tab2; 
	vector<int>tab3;
	for (pomocniczy = glowa; pomocniczy != NULL; pomocniczy = pomocniczy->kolejny)
		for (pomocniczyy = pomocniczy->kol; pomocniczyy != NULL; pomocniczyy = pomocniczyy->nast, il++)
		{
			nazwiskor = pomocniczyy->nazwisko;
			krajr = pomocniczyy->kraj;
			for (int i = 0; i < rank.size(); i++)
			{if (rank[i] == nazwiskor)
			{czy_jest = true; break;}}
			if (czy_jest == false)
			{rank.push_back(nazwiskor);
			tab.push_back(0);
			}
			for (int j = 0; j < rank1.size(); j++)
			{if(rank1[j]==krajr)
			{czy_kraj = true; break;}}
			if(czy_kraj == false)
			{rank1.push_back(krajr);
			tab2.push_back(0);}
			czy_jest = false; czy_kraj = false;
		}
	for (pomocniczy = glowa; pomocniczy != NULL; pomocniczy = pomocniczy->kolejny)
		for (pomocniczyy = pomocniczy->kol; pomocniczyy != NULL; pomocniczyy = pomocniczyy->nast)
		{
			nazwiskor = pomocniczyy->nazwisko;
			krajr = pomocniczyy->kraj;
			pozycjar = pomocniczyy->pozycja;
			for(int i=0;i<rank1.size();i++)
				if(rank1[i]==krajr)
					switch(pozycjar)
					{
					case 1: {tab2[i] = tab2[i] + 100; break; }
					case 2: {tab2[i] = tab2[i] + 80; break; }
					case 3: {tab2[i] = tab2[i] + 60; break; }
					case 4: {tab2[i] = tab2[i] + 50; break; }
					case 5: {tab2[i] = tab2[i] + 45; break; }
					case 6: {tab2[i] = tab2[i] + 40; break; }
					case 7: {tab2[i] = tab2[i] + 36; break; }
					case 8: {tab2[i] = tab2[i] + 32; break; }
					case 9: {tab2[i] = tab2[i] + 29; break; }
					case 10: {tab2[i] = tab2[i] + 26; break; }
					case 11: {tab2[i] = tab2[i] + 24; break; }
					case 12: {tab2[i] = tab2[i] + 22; break; }
					case 13: {tab2[i] = tab2[i] + 20; break; }
					case 14: {tab2[i] = tab2[i] + 18; break; }
					case 15: {tab2[i] = tab2[i] + 16; break; }
					case 16: {tab2[i] = tab2[i] + 15; break; }
					case 17: {tab2[i] = tab2[i] + 14; break; }
					case 18: {tab2[i] = tab2[i] + 13; break; }
					case 19: {tab2[i] = tab2[i] + 12; break; }
					case 20: {tab2[i] = tab2[i] + 11; break; }
					case 21: {tab2[i] = tab2[i] + 10; break; }
					case 22: {tab2[i] = tab2[i] + 9; break; }
					case 23: {tab2[i] = tab2[i] + 8; break; }
					case 24: {tab2[i] = tab2[i] + 7; break; }
					case 25: {tab2[i] = tab2[i] + 6; break; }
					case 26: {tab2[i] = tab2[i] + 5; break; }
					case 27: {tab2[i] = tab2[i] + 4; break; }
					case 28: {tab2[i] = tab2[i] + 3; break; }
					case 29: {tab2[i] = tab2[i] + 2; break; }
					case 30: {tab2[i] = tab2[i] + 1; break; }
					default: {tab2[i] = tab2[i]; break; }
					}
			for (int i = 0; i < rank.size(); i++)
				if (rank[i] == nazwiskor)
					switch (pozycjar)
					{
					case 1: {tab[i] = tab[i] + 100;break; }
					case 2: {tab[i] = tab[i] + 80;break; }
					case 3: {tab[i] = tab[i] + 60;break; }
					case 4: {tab[i] = tab[i] + 50;break; }
					case 5: {tab[i] = tab[i] + 45;break; }
					case 6: {tab[i] = tab[i] + 40;break; }
					case 7: {tab[i] = tab[i] + 36;break; }
					case 8: {tab[i] = tab[i] + 32;break; }
					case 9: {tab[i] = tab[i] + 29;break; }
					case 10: {tab[i] = tab[i] + 26;break; }
					case 11: {tab[i] = tab[i] + 24;break; }
					case 12: {tab[i] = tab[i] + 22;break; }
					case 13: {tab[i] = tab[i] + 20;break; }
					case 14: {tab[i] = tab[i] + 18;break; }
					case 15: {tab[i] = tab[i] + 16;break; }
					case 16: {tab[i] = tab[i] + 15;break; }
					case 17: {tab[i] = tab[i] + 14;break; }
					case 18: {tab[i] = tab[i] + 13;break; }
					case 19: {tab[i] = tab[i] + 12;break; }
					case 20: {tab[i] = tab[i] + 11;break; }
					case 21: {tab[i] = tab[i] + 10;break; }
					case 22: {tab[i] = tab[i] + 9;break; }
					case 23: {tab[i] = tab[i] + 8;break; }
					case 24: {tab[i] = tab[i] + 7;break; }
					case 25: {tab[i] = tab[i] + 6;break; }
					case 26: {tab[i] = tab[i] + 5;break; }
					case 27: {tab[i] = tab[i] + 4;break; }
					case 28: {tab[i] = tab[i] + 3;break; }
					case 29: {tab[i] = tab[i] + 2;break; }
					case 30: {tab[i] = tab[i] + 1;break; }
					default: {tab[i] = tab[i];break; }
					}
		}
	int max = 0, poz_max = 0; 
	for (int j = 0; j < rank.size(); j++)
	{for (int i = 0; i < rank.size(); i++)
	{if (tab[i] > max)
		{poz_max = i;
		max = tab[i];}}
	tab[poz_max] = 0; 
		tab1.push_back(max);
		rank2.push_back(rank[poz_max]);
		max = 0;
		poz_max = 0;
	}
	for (int i = 0; i < rank.size(); i++)
		
	max = 0, poz_max = 0;
	for (int j = 0; j < rank1.size(); j++)
	{for (int i = 0; i < rank1.size(); i++)
	{if (tab2[i] > max)
			{poz_max = i;
			max = tab2[i];}}
		tab2[poz_max] = 0;
		tab3.push_back(max);
		rank3.push_back(rank1[poz_max]);
		max = 0;
		poz_max = 0;
	}
	cout << " aby zobzczyc ranking indywidualny wcisnij : 1" << endl<<" aby zobzczyc ranking narodowy wcisnij : 2" << endl << " aby zobzczyc ranking indywidualny i narodowy wcisnij : 3" << endl;
	char wybor;
	wybor = _getch();
	stringstream ss1;
	int wyb;
	ss1 << wybor;
	ss1 >> wyb;
	ss1.clear();
	switch (wyb) {
	case 1: {for (int i = 0; i < rank.size(); i++)
		cout << rank2[i] << " " << tab1[i] << endl; break; }
	case 2: {for (int i = 0; i < rank1.size(); i++)
		cout << rank3[i] << " " << tab3[i] << endl; break; }
	case 3: {for (int i = 0; i < rank.size(); i++)
		cout << rank2[i] << " " << tab1[i] << endl;
		cout << endl;
		for (int i = 0; i < rank1.size(); i++)
			cout << rank3[i] << " " << tab3[i] << endl; break; }
	default: {cout << endl << " podales zla wartosc, za chwile powrocisz do menu " << endl; break; }
	}
}

void wyswietl_konkurs(konkurs *&glowa, string miejsce)
{
	konkurs* pomocniczy = new konkurs;
		pomocniczy=glowa;
		for (string n_miejsce = glowa->miejsce; n_miejsce != miejsce; n_miejsce = pomocniczy->miejsce)
			pomocniczy = pomocniczy->kolejny;
		cout << pomocniczy->miejsce << " " << pomocniczy->data << endl;
		skoczek * temp = new skoczek;
			temp=pomocniczy->kol;
		while (temp != NULL)
		{
			cout << temp->nazwisko << " " << temp->kraj << " " << temp->pozycja << endl;
			temp = temp->nast;
		}
}

void wyswietl_zawodnika(konkurs *&glowa, string nazwisk)
{
	konkurs *pomocniczy = new konkurs;
	pomocniczy = glowa;
	cout << nazwisk << endl;
	while(pomocniczy!=NULL)
	{
		skoczek *pomocniczyy = new skoczek;
		pomocniczyy = pomocniczy->kol;
		for (string nazwiskoo = pomocniczyy->nazwisko; nazwiskoo != nazwisk; nazwiskoo = pomocniczyy->nazwisko)
			pomocniczyy = pomocniczyy->nast;
		cout << pomocniczy->miejsce << " " << pomocniczy->data << " lokata: " << pomocniczyy->pozycja << endl;
		pomocniczy = pomocniczy->kolejny;
	}
}

void zapisz_zmiany(konkurs*&glowa, string zapis)
{
	ofstream nowe;
	nowe.open(zapis.c_str(), ios::out);
	konkurs *pomocniczy = new konkurs;
	skoczek *pomocniczyy = new skoczek;
	for (pomocniczy = glowa; pomocniczy != NULL; pomocniczy = pomocniczy->kolejny)
		for (pomocniczyy = pomocniczy->kol; pomocniczyy != NULL; pomocniczyy = pomocniczyy->nast)
			nowe << pomocniczy->miejsce << " " << pomocniczy->data << " " << pomocniczyy->nazwisko << " " << pomocniczyy->kraj << " " << pomocniczyy->pozycja << endl;
	nowe.close();
}
void usunskoczkow(skoczek * & pHead)
{
	while (pHead)
	{
		skoczek * pNastepnik = pHead->nast;
		delete pHead;
		pHead = pNastepnik;
	}
	pHead = NULL;
}
void usunkonkursy(konkurs * & pHead)
{
	while (pHead)
	{
		konkurs * pNastepnik = pHead->kolejny;
		usunskoczkow(pHead->kol);
		delete pHead;
		pHead = pNastepnik;
	}
	pHead = NULL;
}
int main(int argc, char* argv[]) {
	if (argc != 5) {
		cout << "Zle uruchomiony program." << endl;
		system("pause");
		return 0;
	}
	string przelacznik = argv[2];
	if (przelacznik == "-i" || przelacznik == "-o") {
		cout << "nie poda³es wlasciwego prze³¹cznika." << endl;
		system("pause");
		return 0;
	}
	string plik, zapis;
	for (int i = 1; i < argc; i++) {
		string pob_wart = argv[i];
		if (pob_wart == "-i")
			plik = argv[i + 1];
		if (pob_wart == "-o")
			zapis = argv[i + 1];
	}
	string mie;
	char w=0;
	int wyborrr;
	stringstream ss2;
	konkurs*glowa = new konkurs;
	dodaj_konkurs(glowa, plik);
	while(w!=48)
	{
		cout << "\t" << "MENU" << endl << " Aby edytowac zawodnika wybierz : 1" << endl << " Aby wyswietlic obecny ranking pucharu wybierz : 2" << endl << " Aby wyswietlic wynik z wybranego konkursu wybierz : 3" << endl << " Aby wyswietlic wyniki danego skoczka wybierz : 4" << endl<<" Aby etytowac informacje o konkursie wybeirz : 5"<<endl<<" Aby zakonczyc wybierz : 0"<<endl;
		w = _getch();
		ss2 << w; system("cls");
		ss2 >> wyborrr;
		ss2.clear();
		switch(wyborrr)
		{
		case 0: {zapisz_zmiany(glowa, zapis); usunkonkursy(glowa); return 0; break; }
		case 1: {edytuj_zawodnika(glowa); break; }
		case 2: {ranking(glowa); break; }
		case 3: {cout << " Prosze podac miejsce konkursu " << endl;
			cin >> mie; cout << endl;
			wyswietl_konkurs(glowa, mie); break; }
		case 4: {cout << " Prosze podac nazwisko zawodnika " << endl;
				cin >> mie; cout << endl;
				wyswietl_zawodnika(glowa, mie); break; }
		case 5: {cout << " Prosze podac miejse konkursu ktory chcesz edytowac" << endl;
				cin >> mie; cout << endl;
				edytuj_konkurs(glowa,mie); break; }
		default: {cout << " Podales niewlasciwa warotsc " << endl; break; }
		}
	}
	cin.get();

	return 0;
}