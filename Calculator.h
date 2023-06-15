#include <iostream>
#pragma once

using namespace std;

class Calculator
{
	float zmienna;
	float pamiec;

public:
	float wynik;
	Calculator(float = 0, float = 0, float = 0);
	~Calculator();

	void Dodawanie(float, float);
	void Odejmowanie(float, float);
	void Mnozenie(float, float);
	void Dzielenie(float, float);
	void Reszta(float, float);
	void Pierwiastek(float, float);
	void Potega(float, float);
	void Wynik();
};

