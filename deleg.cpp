#include <iostream>
#include <string>

using namespace std;

class Rectangle
{
public:
	int len;
	int wid;
	int area;
	string color = "black";
	void print()
	{
		cout << "Length: " << len << endl;
		cout << "Width: " << wid << endl;
		cout << "Area: " << area << endl;
		cout << "Color: " << color << endl;
	}

	Rectangle(int len, int wid)
	{
		this->len = len;
		this->wid = wid;
		this->area = len * wid;
	}
	// delegation
	Rectangle(int len, int wid, string c)
		: Rectangle(len, wid)
	{
		this->color = c;
	}
};

int main()
{
	Rectangle rect(20, 30);
	rect.print();
	Rectangle square(50, 50, "red");
	square.print();
}
