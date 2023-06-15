#include <iostream>
#include "Calculator.h"

using namespace std;

void Calculator::Dodawanie(float zmienna1, float zmienna2)
{
	wynik = zmienna1 + zmienna2;
}

void Calculator::Odejmowanie(float zmienna1, float zmienna2)
{
	wynik = zmienna1 - zmienna2;
}

void Calculator::Mnozenie(float zmienna1, float zmienna2)
{
	wynik = zmienna1 * zmienna2;
}

void Calculator::Dzielenie(float zmienna1, float zmienna2)
{
	wynik = zmienna1 / zmienna2;
}

void Calculator::Reszta(float zmienna1, float zmienna2)
{
	wynik = (int)zmienna1 % (int)zmienna2;
}

void Calculator::Pierwiastek(float zmienna1, float zmienna2)
{
	wynik = pow(zmienna1, (1 / zmienna2));
}

void Calculator::Potega(float zmienna1, float zmienna2)
{
	wynik = pow(zmienna1, zmienna2);
}

void Calculator::Wynik()
{
	cout << wynik;
}

Calculator::Calculator(float wynik1, float zmienna1, float pamiec1)
{
	wynik = wynik1;
	zmienna = zmienna1;
	pamiec = pamiec1;
}

Calculator::~Calculator()
{

}