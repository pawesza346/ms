#include<iostream>
#include<funkcje.h>
using namespace std;
int main()
{
	char imie[20];
	strcpy_s(imie, 20, "ola");
	cout << imie;
	cin.get();
}