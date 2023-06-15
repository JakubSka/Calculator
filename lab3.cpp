#include <iostream>
#include <string>
#include <sstream>
#include "Calculator.h"

using namespace std;

static bool koniec = false;
static string polecenie;
static int nrZnakuP = 0, nrZnakuK = 0, nrZnaku = 0;

float LiczbaPoLewej()
{
	int a = nrZnaku, dlugosc = 1, cos = a - 1;
	string liczba;
	while (cos >= 0 && (isdigit(polecenie[cos]) || polecenie[cos] == '.'))
	{
		dlugosc++;
		a--;
		cos--;
	}

	if (cos >= 1)
	{
		if (polecenie[cos] == '-' && polecenie[cos - 1] == '(')
		{
			dlugosc++;
			a--;
		}
	}

	for (int i = a; i < a + dlugosc; i++)
	{
		liczba += polecenie[i];
	}
	nrZnakuP = a;

	float liczbaF;
	liczbaF = stof(liczba);
	return liczbaF;
}

float LiczbaPoPrawej()
{
	int a = nrZnaku + 1;
	string liczba;
	if (polecenie[a] == '(')
	{
		a += 2;
		liczba += '-';
	}
	while (a < polecenie.length() && (isdigit(polecenie[a]) || polecenie[a] == '.'))
	{
		liczba += polecenie[a];
		a++;
	}
	a--;
	nrZnakuK = a;

	float liczbaF;
	liczbaF = stof(liczba);
	return liczbaF;
}

void NowePolecenie(string nowaLiczba)
{
	string nowe = "";
	int dlugosc = nrZnakuK - nrZnakuP;
	int ile = polecenie.length() - dlugosc + nowaLiczba.length();
	for (int i = 0; i < nrZnakuP; i++)
	{
		nowe += polecenie[i];
	}

	if (nowaLiczba[0] == '-')
	{
		nowe += '(';
	}

	for (int j = 0; j < nowaLiczba.length(); j++)
	{
		nowe += nowaLiczba[j];
	}

	for (int i = nrZnakuK; i < polecenie.length(); i++)
	{
		nowe += polecenie[i];
	}

	polecenie = nowe;
}

bool SprawdzZnak(char znak)
{
	for (int i = 0; i < polecenie.length(); i++)
	{
		if (polecenie[i] == znak && polecenie[i - 1] != '(')
		{
			nrZnaku = i;
			return true;
		}
	}

	return false;
}

int main()
{
	Calculator k1;

	do
	{
		system("cls");
		cout << "Wynik to: ";
		k1.Wynik();
		cout << endl << endl;
		cout << "Aby wyjsc napisz \"E\"" << endl;
		cout << "Podaj polecenie: ";
		cout << endl;
		cin >> polecenie;

		if (polecenie[0] == '-')
		{
			polecenie = '(' + polecenie;
		}

		string liczba123 = "", znak123 = "", nowePolecenie = "";

		koniec = false;
		while (!koniec)
		{
			if (SprawdzZnak('%'))
			{
				k1.Reszta(LiczbaPoLewej(), LiczbaPoPrawej());
				string wynik123 = to_string(k1.wynik);
				NowePolecenie(wynik123);
			}
			else if (SprawdzZnak('p'))
			{
				k1.Pierwiastek(LiczbaPoLewej(), LiczbaPoPrawej());
				string wynik123 = to_string(k1.wynik);
				NowePolecenie(wynik123);
			}
			else if (SprawdzZnak('^'))
			{
				k1.Potega(LiczbaPoLewej(), LiczbaPoPrawej());
				string wynik123 = to_string(k1.wynik);
				NowePolecenie(wynik123);
			}
			else if (SprawdzZnak('/'))
			{
				k1.Dzielenie(LiczbaPoLewej(), LiczbaPoPrawej());
				string wynik123 = to_string(k1.wynik);
				NowePolecenie(wynik123);
			}
			else if (SprawdzZnak('*'))
			{
				k1.Mnozenie(LiczbaPoLewej(), LiczbaPoPrawej());
				string wynik123 = to_string(k1.wynik);
				NowePolecenie(wynik123);
			}
			else if (SprawdzZnak('-'))
			{
				k1.Odejmowanie(LiczbaPoLewej(), LiczbaPoPrawej());
				string wynik123 = to_string(k1.wynik);
				NowePolecenie(wynik123);
			}
			else if (SprawdzZnak('+'))
			{
				k1.Dodawanie(LiczbaPoLewej(), LiczbaPoPrawej());
				string wynik123 = to_string(k1.wynik);
				NowePolecenie(wynik123);
			}
			else
			{
				koniec = true;
			}
		}
	} while (polecenie != "E");
}
