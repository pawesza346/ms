#include"struktury.h"

void wyswietl1(skoczek*& g) {
	skoczek*next = g;
	while (next != NULL)
	{
		cout << next->nazwisko << " " << next->kraj << " " << next->pozycja << endl;
		next = next->nast;
	}
};

void wyswietl2(konkurs*& glowa) {
	konkurs*next = glowa;
	while (next != NULL)
	{
		cout << next->data << " " << next->miejsce << endl;
		wyswietl1(next->kol);
		next = next->kolejny;
	}
};

void dodaj_konkurs(konkurs*& glowa, string nazwa)
{
	stringstream ss;
	string miejsce1, miejsce2, czas1, czas2, nazwisko1, nazwisko2, kraj1, kraj2, pozycja1, pozycja2;
	ifstream dane;
	dane.open(nazwa.c_str(), ios::in);
	dane >> miejsce1 >> czas1 >> nazwisko1 >> kraj1 >> pozycja1;
	konkurs* kolejny = new konkurs;
	glowa = kolejny;
	skoczek* g = new skoczek;
	glowa->kol = g;
	while (!dane.eof())
	{
		dane >> miejsce2 >> czas2 >> nazwisko2 >> kraj2 >> pozycja2;
		if (miejsce1 == miejsce2 and czas1 == czas2)
		{
			g->nazwisko = nazwisko1;
			g->kraj = kraj1;
			ss << pozycja1;
			ss >> g->pozycja;
			ss.clear();
			skoczek* nowy = new skoczek;
			g->nast = nowy;
			g = nowy;
			nazwisko1 = nazwisko2;
			kraj1 = kraj2;
			pozycja1 = pozycja2;
		}
		else
		{
			g->nazwisko = nazwisko1;
			g->kraj = kraj1;
			ss << pozycja1;
			ss >> g->pozycja;
			ss.clear();
			glowa->miejsce = miejsce1;
			glowa->data = czas1;
			konkurs* kolejnyy = new konkurs;
			glowa->kolejny = kolejnyy;
			glowa = kolejnyy;
			skoczek* g = new skoczek;
			glowa->kol = g;
			nazwisko1 = nazwisko2;
			kraj1 = kraj2;
			pozycja1 = pozycja2;
		}
	}
	if (miejsce1 == miejsce2 and czas1 == czas2)
	{
		skoczek* nowy = new skoczek;
		g->nast = nowy;
		g = nowy;
		g->nazwisko = nazwisko2;
		g->kraj = kraj2;
		ss << pozycja2;
		ss >> g->pozycja;
		ss.clear();
		glowa->miejsce = miejsce1;
		glowa->data = czas1;
	}
	else
	{
		glowa->miejsce = miejsce1;
		glowa->data = czas1;
		konkurs* kolejnyy = new konkurs;
		glowa->kolejny = kolejnyy;
		glowa = kolejnyy;
		glowa->miejsce = miejsce2;
		glowa->data = czas2;
		skoczek* g = new skoczek;
		glowa->kol = g;
		g->nazwisko = nazwisko2;
		g->kraj = kraj2;
		ss << pozycja2;
		ss << g->pozycja;
		ss.clear();
	}
};