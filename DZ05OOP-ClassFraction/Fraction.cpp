#include "Fraction.h"

Fraction::Fraction() : Fraction(1, 5) {}

Fraction::Fraction(int ches, int znam)
{
	SetChes(ches);
	SetZnam(znam);
}
Fraction::Fraction(const Fraction& original)
{
	SetChes(original.ches);
	SetZnam(original.znam);
}

void Fraction::SetChes(int ches)
{
	this->ches = ches;
}
void Fraction::SetZnam(int znam)
{
	if (znam == 0)
	{
		throw "Division by zero is not allowed";
	}
	this->znam = znam;
}
int Fraction::GetChes() const
{
	return ches;
}
int Fraction::GetZnam() const
{
	return znam;
}
void Fraction::ShowFraction()
{
	cout << GetChes() << "/" << GetZnam() << "\n";
}
double Fraction::Decimal()
{
	return ((double)ches / znam);
}
void Fraction::Shrink()
{
	int size;
	int temp = 1;
	size = ches < znam ? ches : znam;
	cout << "size = " << size << "\n";
	for (int i = 1; i <= size; i++)
	{
		if (ches % i == 0 && znam % i == 0)
		{
			temp = i;
		}
	}
	ches /= temp;
	znam /= temp;
}

Fraction operator + (const Fraction& one, const Fraction& two)
{
	Fraction result;
	result.SetChes(one.ches * two.znam + two.ches * one.znam);
	result.SetZnam(one.znam * two.znam);
	return result;
}
Fraction operator - (const Fraction& one, const Fraction& two)
{
	Fraction result;
	result.SetChes(one.ches * two.znam - two.ches * one.znam);
	result.SetZnam(one.znam * two.znam);
	return result;
}
Fraction operator * (const Fraction& one, const Fraction& two)
{
	Fraction result;
	result.SetChes(one.ches * two.ches);
	result.SetZnam(one.znam * two.znam);
	return result;
}
Fraction operator / (const Fraction& one, const Fraction& two)
{
	Fraction result;
	result.SetChes(one.ches * two.znam);
	result.SetZnam(one.znam * two.ches);
	return result;
}
bool operator > (const Fraction& one, const Fraction& two)
{
	return (one.ches * two.znam > two.ches * one.znam);
}
bool operator < (const Fraction& one, const Fraction& two)
{
	return (one.ches * two.znam < two.ches * one.znam);
}
bool operator == (const Fraction& one, const Fraction& two)
{
	return (one.ches * two.znam == two.ches * one.znam);
}