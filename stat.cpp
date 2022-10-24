#include <iostream>
#include <string>

using namespace std;

class Animals
{
private:
	static int total;

public:
	string name;
	// class variable  or static member variable
	Animals(string n)
	{
		name = n;
		cout << "Total: " << total++ << endl;
	}
	~Animals()
	{
		total -= 1;
	}
	static int getTotal()
	{
		return total;
	}
};

int Animals::total = 0;
int main()
{
	Animals *tiger = new Animals("tiger");
	Animals *lion = new Animals("lion");

	cout << "Tiger: " << tiger->name << endl;
	cout << "Lion: " << lion->name << endl;
	cout << "Total: " << Animals::getTotal() << endl; // best practice
	cout << "Total: " << tiger->getTotal() << endl;	  // also works
	cout << "Total: " << lion->getTotal() << endl;	  // also works
	delete (lion);
	cout << "Total: " << Animals::getTotal() << endl; // best practice
}
