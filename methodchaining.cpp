#include <iostream>
#include <string>
using namespace std;

class Car
{
public:
	string name;
	int model;
	string color;

	Car(string name = "Mahindra", int model = 12,
		string color = "red")
	{
		this->name = name;
		this->model = model;
		this->color = color;
	}

	Car &setName(string name)
	{
		this->name = name;
		return *this;
	}
	Car &setModel(int model)
	{
		this->model = model;
		return *this;
	}
	Car &setColor(string color)
	{
		this->color = color;
		return *this;
	}
};

int main()
{
	Car carA;
	cout << "Name: " << carA.name << endl;
	cout << "Model: " << carA.model << endl;
	cout << "Color: " << carA.color << endl;
	for (int i = 0; i < 10; i++)
		cout << "-";
	cout << endl;
	carA.setName("Tata").setColor("Blue").setModel(10);
	cout << "Name: " << carA.name << endl;
	cout << "Model: " << carA.model << endl;
	cout << "Color: " << carA.color << endl;
}
