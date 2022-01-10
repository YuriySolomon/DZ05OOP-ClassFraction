#pragma once
#include "AllLibraries.h"

class Fraction
{
	int ches;
	int znam;

public:
	Fraction();
	//Fraction(double num);
	Fraction(int ches, int znam);
	Fraction(const Fraction& original);

	void SetChes(int ches);
	void SetZnam(int znam);
	int GetChes() const;
	int GetZnam() const;
	void ShowFraction();
	double Decimal();
	void Shrink();

	//Fraction operator + (const Fraction& one, const Fraction& two);
};

Fraction operator + (const Fraction& one, const Fraction& two); // перезагрузка сложения дробей
Fraction operator - (const Fraction& one, const Fraction& two); // перезагрузка вычитания дробей
Fraction operator * (const Fraction& one, const Fraction& two); // перезагрузка умножение дробей
Fraction operator / (const Fraction& one, const Fraction& two); // перезагрузка деление дробей
bool operator > (const Fraction& one, const Fraction& two); // перезагрузка операции больше
bool operator < (const Fraction& one, const Fraction& two); // перезагрузка операции меньше
bool operator == (const Fraction& one, const Fraction& two); // перезагрузка операции равно