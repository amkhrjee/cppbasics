#include <iostream>
using namespace std;

class MenuItem
{
public:
    string name;

    MenuItem()
    {
        name = "Unknown";
        cout << "MenuItem default Constructor" << endl;
    }

    MenuItem(string name)
    {
        this->name = name;
        cout << "MenuItem param Constructor" << endl;
    }
};

class Drink : public MenuItem
{
public:
    int glasses;

    Drink()
    {
        cout << "Drink Default Constructor" << endl;

        glasses = 0;
    }

    Drink(int glasses)
    {
        cout << "Drink param Constructor" << endl;
        this->glasses = glasses;
    }
};

class HotDrinks : public Drink
{

public:
    using Drink::Drink; // using the Drink constructor
    // using MenuItem::MenuItem;
    int temperature;

    HotDrinks()
    {
        cout << "HotDrinks Default Constructor" << endl;
        temperature = 0;
    }

    HotDrinks(int temperature, int glasses, string name)
        : Drink(glasses)
    {
        this->name = name;
        this->temperature = temperature;
        cout << "HotDrinks param Constructor" << endl;
    }
};

int main()
{
    HotDrinks hot_chocolate(56, 2, "hot choco");

    cout << "hot_chocolate.temperature: " << hot_chocolate.temperature << endl;
    cout << "hot_chocolate.glasses: " << hot_chocolate.glasses << endl;
    cout << "hot_chocolate.name: " << hot_chocolate.name << endl;
}