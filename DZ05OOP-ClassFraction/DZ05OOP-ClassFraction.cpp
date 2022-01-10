#include "Fraction.h"

int main()
{
    Fraction one;
    one.ShowFraction();

    Fraction two(1, 5);
    two.ShowFraction();

    Fraction three;
    three = one + two;
    three.ShowFraction();
    
    cout << (one == two) << "\n";

    cout << one.Decimal() << "\n";

    three.Shrink();

    three.ShowFraction();

    system("pause >> NULL");
}

