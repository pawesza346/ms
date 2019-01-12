#include"funkcje.h"

void wyswietl1(skoczek* g) {
	skoczek * temp = g;
	while (temp != NULL)
	{
		cout << temp->nazwisko << " " << temp->kraj << " " << temp->pozycja << endl;
		temp = temp->nast;
	}
};

void wyswietl2(konkurs* glowa) {
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
	konkurs* nowyy = new konkurs;
	nowyy = glowa;
	skoczek* g = new skoczek;
	skoczek* gg = new skoczek;
	gg=g;
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
			skoczek* g = new skoczek;
			gg = g;
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
};

int main() {
	string nazwa = "zawodnicy.txt";
	konkurs*glowa = new konkurs;
	dodaj_konkurs(glowa, nazwa);
	wyswietl2(glowa);
	cin.get();
	return 0;
}