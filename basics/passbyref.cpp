#include <iostream>
#include <string>

using namespace std;

void increment(int &x)
{
	x++;
	cout << "Incrementd value = " << x << endl;
}
int main()
{
	int a = 4;
	cout << "Value of a = " << a << endl;
	increment(a);
	cout << "Value of a = " << a << endl;
}
