#include <iostream>
using namespace std;

class Number
{
public:
	int n;
	Number(int set_n)
	{
		n = set_n;
	}
	Number operator+(const Number &num)
	{
		cout << "Number.n: " << this->n << endl;
		cout << "num.n: " << num.n << endl;
		return Number(this->n + num.n);
	}
	bool operator==(const Number &num)
	{
		if (this->n == num.n)
			return true;
		else
			return false;
	}
};

int main()
{
	Number n1(4);
	Number n2(5);

	Number n3 = n1 + n2;

	cout << "n3.n: " << n3.n << endl;
}
