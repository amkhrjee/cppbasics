#include <iostream>
#include <string>
using namespace std;

class Major
{
public:
	string name;
	// default constructor
	Major() : name("Undefined")
	{
		cout << "Default Constructor" << endl;
	};
	Major(string name) : name(name)
	{
		cout << "Constructor for " << name << endl;
	}
};

class Minor
{
public:
	string name;
	Minor(string name) : name(name){};
};

class Student
{
public:
	string name;
	int start_year;
	int grad_year;
	const string id;
	Major major;
	Minor minor;
	/*
	when working with types of diiferent sizes like
	int and long int, one should use {} in the member
	initializer list insteard of () as it provides
	protection against implicit type conversions and
	throws errors
	*/
	Student(string name, int start_year, string major, string minor)
		: name(name),
		  start_year(start_year),
		  grad_year(start_year + 4),
		  id(name.append(to_string(start_year))),
		  major(major),
		  minor(minor)
	{
		// this will call the default constructor too!
		// this->major = Major(major);
	}
};

int main()
{
	Student john("John", 2020, "Computer Science", "Math");
	cout << "name: " << john.name << endl
		 << "start_year: " << john.start_year << endl
		 << "grad_year: " << john.grad_year << endl
		 << "id: " << john.id << endl
		 << "major: " << john.major.name << endl
		 << "minor: " << john.minor.name << endl;
}
