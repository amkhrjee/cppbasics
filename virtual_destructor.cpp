#include <iostream>
using namespace std;

class BaseClass
{
public:
    int x;
    BaseClass(int x)
        : x(x) {}
    virtual ~BaseClass()
    {
        cout << "Base Class Destructor Executing" << endl;
    }
};

class DerivedClass : public BaseClass
{
public:
    int y;
    DerivedClass(int x, int y)
        : y(y), BaseClass(x) {}
    void print()
    {
        cout << "hello" << endl;
    }
    ~DerivedClass()
    {
        cout << "Derived Class Destructor Executing" << endl;
    }
};

int main()
{
    BaseClass *dc = new DerivedClass(12, 23);
    delete dc;
}