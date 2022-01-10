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
};

Fraction operator + (const Fraction& one, const Fraction& two); // ������������ �������� ������
Fraction operator - (const Fraction& one, const Fraction& two); // ������������ ��������� ������
Fraction operator * (const Fraction& one, const Fraction& two); // ������������ ��������� ������
Fraction operator / (const Fraction& one, const Fraction& two); // ������������ ������� ������
bool operator > (const Fraction& one, const Fraction& two); // ������������ �������� ������
bool operator < (const Fraction& one, const Fraction& two); // ������������ �������� ������
bool operator == (const Fraction& one, const Fraction& two); // ������������ �������� �����