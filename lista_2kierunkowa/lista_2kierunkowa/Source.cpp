#include<iostream>
using namespace std;

struct liczba {
	int l;
	liczba* pop;
	liczba* nast;
};
void dodaj(liczba*& g, liczba * nowy)
{
	if (g == NULL)
	{
		g = nowy;
	}
	else
	{
		nowy->nast = g;
		g->pop = nowy;
		g = nowy;
	}
}
void wyswietl(liczba*& g)
{
	liczba* next = g;
	while (next != NULL)
	{
		cout << next->l << endl;
		next = next->nast;
	}
}
void usun_z_listy_max(liczba*& g)
{
	liczba* maksimum = g;
	liczba* nastepny = g;
	while (nastepny != NULL)
	{
		if (nastepny->l > maksimum->l)
			maksimum = nastepny;
		nastepny = nastepny->nast;
	}
	if (maksimum->nast != NULL && maksimum->pop != NULL)
	{
		maksimum->pop = maksimum->nast;
		maksimum->nast = maksimum->pop;
	}
	if (maksimum->nast != NULL && maksimum->pop == NULL)
	{
		maksimum->pop = NULL;
		maksimum->nast = maksimum->pop;
	}
	if (maksimum->nast == NULL && maksimum->pop != NULL)
	{
		maksimum->pop = maksimum->nast;
		maksimum->nast = NULL;
	}
}
int main()
{
	liczba*g = NULL;
	for (int i = 0;i < 10;i++)
	{
		liczba * nowy = new liczba{ rand() % 100,NULL,NULL };
		dodaj(g, nowy);
	}
	wyswietl(g);
	cin.get();

}