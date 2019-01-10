#include"funkcje.h"

void wyswietl1(skoczek *g) {
	skoczek * temp = g;
	while (temp != nullptr)
	{
		cout << temp->nazwisko << " " << temp->kraj << " " << temp->pozycja << endl;
		temp = temp->nast;
	}
};

void wyswietl2(konkurs* glowa) {
	konkurs*next = glowa;
	while (next != nullptr)
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
	konkurs* nowy = glowa;
	skoczek* g = new skoczek;
	skoczek* gg = g;
	while (!dane.eof())
	{
		
		dane >> miejsce2 >> czas2 >> nazwisko2 >> kraj2 >> pozycja2;
		if (miejsce1 == miejsce2 and czas1 == czas2)
		{
			cout << "a";
			gg->nazwisko = nazwisko1;
			gg->kraj = kraj1;
			ss << pozycja1;
			ss >> gg->pozycja;
			ss.clear();
			skoczek* nowy = new skoczek;
			gg->nast = nowy;
			gg = nowy;
			nazwisko1 = nazwisko2;
			kraj1 = kraj2;
			pozycja1 = pozycja2;
		}
		else
		{
			
			gg->nazwisko = nazwisko1;
			gg->kraj = kraj1;
			ss << pozycja1;
			ss >> gg->pozycja;
			ss.clear();
			nowy->miejsce = miejsce1;cout << "b";
			nowy->data = czas1;
			nowy->kol = g;
			konkurs* najnowszy = new konkurs;
			nowy->kolejny = najnowszy;
			nowy=najnowszy;
			skoczek* g = new skoczek;
			skoczek* gg = g;
			nazwisko1 = nazwisko2;
			kraj1 = kraj2;
			pozycja1 = pozycja2;
		}
	}
	if (miejsce1 == miejsce2 and czas1 == czas2)
	{
		gg->nazwisko = nazwisko1;
		gg->kraj = kraj1;
		ss << pozycja1;
		ss >> gg->pozycja;
		ss.clear();
		nowy->miejsce = miejsce1;
		nowy->data = czas1;
		nowy->kol = g;
	}
	else
	{
		nowy->miejsce = miejsce1;
		nowy->data = czas1;
		nowy->kol = g;
		konkurs* najnowszy = new konkurs;
		nowy->kolejny = najnowszy;
		nowy=najnowszy;
		nowy->miejsce = miejsce2;
		nowy->data = czas2;
		skoczek* g = new skoczek;
		nowy->kol = g;
		g->nazwisko = nazwisko1;
		g->kraj = kraj1;
		ss << pozycja1;
		ss >> g->pozycja;
		ss.clear();
	}
};

int main() {
	string nazwa = "zawodnicy.txt";
	konkurs*glowa = nullptr;
	dodaj_konkurs(glowa, nazwa);
	wyswietl2(glowa);
	cin.get();
	return 0;
}