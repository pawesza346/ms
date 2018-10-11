#include<iostream>
using namespace std;
int main()
{
	int a[10][10];
	int b;
	for (int i = 0;i < 10;i++)
		for (int j = 0;j < 10;j++)
			a[i][j] = 0;

	for (int i = 0;i < 10;i++)
		for (int j = 0;j < 10;j++)
			if (j % 2 == 1 or i % 2 == 1)
				a[i][j] = 1;

	for (int i = 0;i < 10;i++)
	{
		cout << endl;
		for (int j = 0;j < 10;j++)
			cout << a[i][j];
	}
	cin >> b;
	return 0;
}