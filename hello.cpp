#include <iostream>
using namespace std;
class Fraction
{
private:
    long num;
    long den;

    // helper function
    long gcd(long, long);

public:
    // constructors
    Fraction()
        : num(0), den(1) {}
    Fraction(long num)
        : num(num), den(1) {}
    Fraction(long num, long den)
        : num(num), den(den == 0 ? 1 : den) {}
    // copy constructor
    Fraction(const Fraction &lhs)
        : Fraction(lhs.num, lhs.den) {}
    // prints reduced form
    void print();
    // adds two fractions
    friend Fraction add(const Fraction &, const Fraction &);
    // substracts two fractions
    friend Fraction sub(const Fraction &, const Fraction &);
    // adds +1
    void inc();
    // operators
    Fraction operator+(const Fraction &);
    Fraction operator-(const Fraction &);
    // just for test
    void show()
    {
        cout << "Num: " << num << endl
             << "Denom: " << den << endl
             << "GCD: " << gcd(num, den) << endl;
        for (int i = 0; i < 20; i++)
        {
            cout << "-";
        }
        cout << endl;
    }
};

// helper function definition
long Fraction::gcd(long a, long b)
{
    while (b != 0)
    {
        long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

Fraction add(const Fraction &lhs, const Fraction &rhs)
{
    long lcm;
    Fraction res;
    if (lhs.num * rhs.num >= 0)
    {
        lcm = lhs.den * (rhs.den / res.gcd(lhs.den, rhs.den));
    }
    else if (lhs.num * rhs.den < 0)
    {
        cout << "Negative" << endl;
        lcm = -lhs.den * rhs.den / res.gcd(lhs.den, rhs.den);
    }

    res.num = (lhs.num * (lcm / lhs.den)) + (rhs.num * (lcm / rhs.den));
    res.den = lcm;

    return Fraction(res.num / res.gcd(res.num, res.den), res.den / res.gcd(res.num, res.den));
}

void Fraction::print()
{
    cout << "The fraction in its reduced form: "
         << num / gcd(num, den) << "/"
         << den / gcd(num, den) << endl;
}

// operators
Fraction Fraction::operator+(const Fraction &rhs)
{

    return add(*this, rhs);
}

inline void Fraction::inc()
{
    Fraction rhs(1);
    *this = add(*this, rhs);
}

int main()
{
    Fraction frac(8, 2);
    frac.show();
    // frac.inc();
    // frac.show();
    Fraction anotherFrac(10, 5);
    anotherFrac.show();
    Fraction some;
    some = anotherFrac + frac;
    some.show();
    // anotherFrac = frac;
    // frac.show();
    // frac.print();
    // anotherFrac.show();

    add(frac, anotherFrac).show();
    // my.show();
    // anotherFrac.show();

    // Fraction f1, f2(2L, 0L);
    // Fraction f3(f1);
    // f1.print();
    // f2.print();
    // f3.print();
    // f3 = add(f3, Fraction(-5, 4));
    // f3.print();
    // f1 = add(f2, f3);
    // f1.print();
    // f1 = sub(f2, f3);
    // f1.print();
    // f1 = mult(f2, f3);
    // f1.print();
    // f1.inc().inc().print();
    // f1.print();
    // f1.div(f2, f3);
    // f1.print();
    // return 0;
}