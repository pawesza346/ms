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
		if (miejsce1 == miejsce2 && czas1 == czas2)
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
	if (miejsce1 == miejsce2 && czas1 == czas2)
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
	case 1: {cout << "\n" << " podaj nowa nazwe " << endl;
		cin >> nowe;
		pomocniczy->miejsce = nowe;
		cout << endl << " zmiana zostala wykonana " << endl; break; }
	case 2: {cout << endl << " podaj nowa date " << endl;
		cin >> nowe;
		if (nowe.size() != 10)
		{	cout << " podana data jest nieprawidlowa , format daty to : dd.mm.rrrr"; break; }
		if(nowe[2]!= nowe[5])
		{cout << " podana data jest nieprawidlowa , format daty to : dd.mm.rrrr"; break;}
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
	for (pomocniczy = glowa; pomocniczy != nullptr; pomocniczy = pomocniczy->kolejny)
		for (pomocniczyy = pomocniczy->kol; pomocniczyy != nullptr; pomocniczyy = pomocniczyy->nast, il++)
		{
			nazwiskor = pomocniczyy->nazwisko;
			krajr = pomocniczyy->kraj;
			for (int i = 0; i < rank.size(); i++)
			{if (rank[i] == nazwiskor)
			{czy_jest = true; break;}}
			if (czy_jest == false)
			{rank.push_back(nazwiskor);
			tab.push_back(0);}
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
			for (int i = 0;i < rank1.size();i++)
				if (rank1[i] == krajr)
					if(pozycjar<=max_zaw)
					tab2[i] += tab_rank[pozycjar-1];
					
			for (int i = 0; i < rank.size(); i++)
				if (rank[i] == nazwiskor)
					if (pozycjar <= max_zaw)
						tab[i] += tab_rank[pozycjar-1];
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
	vector<int>poz;
	int max, poz_max;
	konkurs* pomocniczy = new konkurs;
	pomocniczy=glowa;
	for (string n_miejsce = glowa->miejsce; n_miejsce != miejsce; n_miejsce = pomocniczy->miejsce)
		pomocniczy = pomocniczy->kolejny;
	cout << pomocniczy->miejsce << " " << pomocniczy->data << endl;
	skoczek * temp = new skoczek;
	for(temp=pomocniczy->kol;temp!=NULL;temp=temp->nast)
		poz.push_back(temp->pozycja);
	while (poz.size() != 0)
	{max = poz[0], poz_max = 0;
	for (int i = 1; i < poz.size(); i++)
		{if (poz[i] > max)
			{max = poz[i];
			poz_max = i;}
		}
	for (temp = pomocniczy->kol; temp->pozycja != max;)
		temp = temp->nast;
	cout << temp->nazwisko << " " << temp->kraj << " " << temp->pozycja << endl;
	poz.erase(poz.begin() + poz_max);}
		
}

void wyswietl_zawodnika(konkurs *&glowa, string nazwisk)
{
	skoczek *pomocniczyy = new skoczek;
	konkurs *pomocniczy = new konkurs;
	pomocniczy = glowa;
	vector<string>dane1;
	cout << nazwisk << endl;
	string max,porownanie,nazwiskoo;
	int poz_max;
	while(pomocniczy!=NULL)
	{pomocniczyy = pomocniczy->kol;
	for (nazwiskoo = pomocniczyy->nazwisko; nazwiskoo != nazwisk; nazwiskoo = pomocniczyy->nazwisko)
	pomocniczyy = pomocniczyy->nast; 
	if(nazwiskoo==nazwisk)
		dane1.push_back(pomocniczy->data);
	pomocniczy = pomocniczy->kolejny;}
	while (dane1.size() != 0)
	{max = dane1[0];
	poz_max = 0;
	for (int i = 1; i < dane1.size(); i++)
	{porownanie = dane1[i];
	if (porownanie[6] < max[6])
	{max = porownanie;
	poz_max = i;}
	else
		{if (porownanie[7] < max[7])
		{max = porownanie;
		poz_max = i;}
		else
			{if (porownanie[8] < max[8])
			{max = porownanie;
			poz_max = i;}
			else
				{if (porownanie[9] < max[9])
				{max = porownanie;
				poz_max = i;}
				else
					{if (porownanie[3] < max[3])
					{max = porownanie;
					poz_max = i;}
					else
						{if (porownanie[4] < max[4])
						{max = porownanie;
						poz_max = i;}
						else
							{if (porownanie[0] < max[0])
							{max = porownanie;
							poz_max = i;}
							else
								{if (porownanie[1] < max[1])
								{max = porownanie;
								poz_max = i;}
									}
								}
							}
						}
					}
				}
			}
		}
		pomocniczy = glowa;
		for (string dataa = pomocniczy->data; dataa != max; dataa = pomocniczy->data)
			pomocniczy = pomocniczy->kolejny;
		pomocniczyy = pomocniczy->kol;
		for (string nazwiskoo = pomocniczyy->nazwisko; nazwiskoo != nazwisk; nazwiskoo = pomocniczyy->nazwisko)
			pomocniczyy = pomocniczyy->nast;
		cout << pomocniczy->data << " " << pomocniczy->miejsce << " lokata: " << pomocniczyy->pozycja<<endl;
		dane1.erase(dane1.begin()+poz_max);
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
		cout << "nie podales wlasciwego przelacznika." << endl;
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
	ifstream dana(plik);
	if (!dana.is_open()) {
		cout << " Podany plik nie istnieje ";
		system("pause");
		return 0;
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