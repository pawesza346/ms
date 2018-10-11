#include<iostream>
#include<string>
using namespace std;
int main() {
	int msc, suma = 0,szcz;
	string imie;
	cout << "podaj imie" << endl;
	cin >> imie;
	cout << "podaj miesiac" << endl;
	cin >> msc;
	for (int i = 0;i < imie.size();i++)
		suma = suma + (int)imie[i];
	szcz=suma/imie.size();
	while(szcz>30)
		szcz = (szcz / 2) + msc;
	cout << "twoj szczesliwy dzien to" << endl<< szcz;
	cin >> msc;
	return 0;
}