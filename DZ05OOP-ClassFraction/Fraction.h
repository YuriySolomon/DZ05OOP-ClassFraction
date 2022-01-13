#pragma once
#include "AllLibraries.h"

class Fraction
{
	int ches;
	int znam;

public:
	Fraction();
	Fraction(int ches, int znam);
	Fraction(const Fraction& original);

	void SetChes(int ches);
	void SetZnam(int znam);
	int GetChes() const;
	int GetZnam() const;
	void ShowFraction();
	double Decimal();
	void Shrink();

	friend Fraction operator + (const Fraction& one, const Fraction& two);
	friend Fraction operator - (const Fraction& one, const Fraction& two);
	friend Fraction operator * (const Fraction& one, const Fraction& two);
	friend Fraction operator / (const Fraction& one, const Fraction& two);
	friend bool operator > (const Fraction& one, const Fraction& two);
	friend bool operator < (const Fraction& one, const Fraction& two);
	friend bool operator == (const Fraction& one, const Fraction& two);
};

Fraction operator + (const Fraction& one, const Fraction& two); // peregruzka slozheniya drobi
Fraction operator - (const Fraction& one, const Fraction& two); // peregruzka vychitaniya drobey
Fraction operator * (const Fraction& one, const Fraction& two); // peregruzka umnozheniye drobey
Fraction operator / (const Fraction& one, const Fraction& two); // perezagruzka deleniye drobey
bool operator > (const Fraction& one, const Fraction& two); // peregruzka operatsii bol'she
bool operator < (const Fraction& one, const Fraction& two); // peregruzka operatsii men'she
bool operator == (const Fraction& one, const Fraction& two); // peregruzka operatsii ravno