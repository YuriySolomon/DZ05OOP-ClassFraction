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
		throw "Деление на ноль запрещено";
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
	result.SetChes(one.GetChes() * two.GetZnam() + two.GetChes() * one.GetZnam());
	result.SetZnam(one.GetZnam() * two.GetZnam());
	return result;
}
Fraction operator - (const Fraction& one, const Fraction& two)
{
	Fraction result;
	result.SetChes(one.GetChes() * two.GetZnam() - two.GetChes() * one.GetZnam());
	result.SetZnam(one.GetZnam() * two.GetZnam());
	return result;
}
Fraction operator * (const Fraction& one, const Fraction& two)
{
	Fraction result;
	result.SetChes(one.GetChes() * two.GetChes());
	result.SetZnam(one.GetZnam() * two.GetZnam());
	return result;
}
Fraction operator / (const Fraction& one, const Fraction& two)
{
	Fraction result;
	result.SetChes(one.GetChes() * two.GetZnam());
	result.SetZnam(one.GetZnam() * two.GetChes());
	return result;
}
bool operator > (const Fraction& one, const Fraction& two)
{
	return (one.GetChes() * two.GetZnam() > two.GetChes() * one.GetZnam());
}
bool operator < (const Fraction& one, const Fraction& two)
{
	return (one.GetChes() * two.GetZnam() < two.GetChes() * one.GetZnam());
}
bool operator == (const Fraction& one, const Fraction& two)
{
	return (one.GetChes() * two.GetZnam() == two.GetChes() * one.GetZnam());
}