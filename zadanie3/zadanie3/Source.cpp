#include<iostream>
using namespace std;
struct DATA{
	int  yyyy, mm, dd;
};
int main() {
	DATA a1,a2;
	cout << "podaj date" << endl;
	cin>>a1.yyyy>>a1.mm>>a1.dd;
	cout << "podaj date" << endl;
	cin >> a2.yyyy >> a2.mm >> a2.dd;
	if (a1.yyyy > a2.yyyy)
		cout << a1.yyyy << "\n" << a1.mm << "\n" << a1.dd << " jest starszy";
	else
		if (a2.yyyy > a1.yyyy)
			cout << a2.yyyy << "\n" << a2.mm << "\n" << a2.dd << " jest starszy";
		else
			if (a1.mm > a2.mm)
				cout << a1.yyyy << "\n" << a1.mm << "\n" << a1.dd << " jest starszy";
			else
				if (a2.mm > a1.mm)
					cout << a2.yyyy << "\n" << a2.mm << "\n" << a2.dd << " jest starszy";
				else
					if (a1.dd > a2.dd)
						cout << a1.yyyy << "\n" << a1.mm << "\n" << a1.dd << " jest starszy";
					else
						if (a2.dd > a1.dd)
							cout << a2.yyyy << "\n" << a2.mm << "\n" << a2.dd << " jest starszy";
						else
							cout << "daty sa takie same ";
	cin.ignore();
	cin.get();
}