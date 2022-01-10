#include "Fraction.h"

Fraction::Fraction() : Fraction(1, 5) {}
//Fraction::Fraction(double num)
//{
//	cout << "DROP \n";
//	if (num == 0)
//	{
//		throw "Ноль не допустимое значение";
//	}
//	int celoe;
//	double drobnoe;
//	celoe = num;
//	drobnoe = num - celoe;
//	
//	int kol = 10;
//	int temp = drobnoe;
//	int j = 0;	
//	cout << "celoe = " << celoe << "\n";
//	cout << "temp = " << temp << "\n";
//	cout << "drobnoe = " << drobnoe << "\n";
//	cout << "kol = " << kol << "\n";
//	//cout << "uslovie = " << (drobnoe * kol - temp * kol) << "\n";
//	cout << "uslovie = " << (drobnoe * kol) << " - " << (temp * kol) << "\n";
//	cout << "j = " << j << "\n";
//	while (drobnoe - temp != 0)
//	{
//		//drobnoe *= kol;
//		
//			
//		temp = drobnoe * kol;
//		drobnoe = drobnoe * kol;
//		cout << "temp = " << temp << "\n";
//		j++;
//		cout << "uslovie = " << (drobnoe * kol) << " - " << (temp * kol) << "\n";
//		system("pause");
//	}
//	cout << "j = " << j << "\n";
//	cout << "kol = " << kol << "\n";
//	ches = kol * celoe + drobnoe;
//	cout << "ches = " << (kol * celoe + drobnoe) << "\n";
//	znam = kol;
//	cout << "znam = " << kol << "\n";
//}
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