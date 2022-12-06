#include <iostream>
// #include <utility>
using namespace std;

// class Shape{
//     we don't need this but it will be useful if we had
//     something like this. Enter Abstract Classes.
// }

class Shape
{
public:
    // this is a pure virtual function ╰(*°▽°*)╯
    virtual double area() = 0;
};

class Square : public Shape
{
public:
    double side;
    Square(double side) : side(side){};
    double area()
    {
        return side * side;
    }
};

class Triangle : public Shape
{
public:
    double height, base;
    Triangle(double height, double base)
        : height(height), base(base){};
    double area()
    {
        return 0.5 * height * base;
    }
};

int main()
{
    Shape *shapes[] = {
        new Square(5),
        new Triangle(5, 3)};

    for (Shape *elem : shapes)
    {
        cout << "area: " << elem->area() << endl;
    }

    return 0;
}