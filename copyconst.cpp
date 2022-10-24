#include <iostream>
using namespace std;

class BasicNumber
{
public:
	int n;
	BasicNumber(int set_n)
	{
		n = set_n;
	}

	// copy constructor
	BasicNumber(const BasicNumber &basic_num)
	{
		n = 2 * basic_num.n;
		cout << "Copy Constructor Called" << endl;
	}
};

int main()
{
	BasicNumber basicnum(45);
	// shallow copy
	BasicNumber num2 = basicnum;
	cout << "num2.n = " << num2.n << endl;
}
