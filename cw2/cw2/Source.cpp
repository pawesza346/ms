#include<iostream>
using namespace std;
int main()
{
	int a[10][10];
	int s = 0, i = 0, j = 0, n = 10, m = 10, b = 0;
	while (s < 100)
	{
		i = b;
		j = b;
		do {
			a[i][j] = s;
			s++;i++;
		} while (i < n - b);
			i = n - b - 1;
		do {
			a[i][j] = s;
			s++;j++;
		} while (j < m - b);
			j = m - b - 1;
		do {
			a[i][j] = s;
			s++;i--;
		} while (i > b);
			i = b;
		do {
			a[i][j] = s;
			s++;j--;
		} while (j > b);
			b++;
	}
	for (int f = 0;f < 10;f++)
	{cout << endl;
		for (int g = 0;g < 10;g++)
			cout << a[f][g];}
	cin >> b;
	return 0;
}