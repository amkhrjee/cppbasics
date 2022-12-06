// friend functions are special type of functions that can access private
// protected memeber of a class
#include <iostream>
using namespace std;

class Entity
{
    friend void double_x(Entity &obj);

private:
    int x;
    int n = 10;
    void add()
    {
        x += n;
    }

public:
    Entity(int x)
        : x(x) {}
    int print_x()
    {
        return x;
    }
};

void double_x(Entity &obj)
{
    obj.x *= 2;
}

int main()
{
    Entity myEntity(30);
    // myEntity.add();
    double_x(myEntity);

    cout << "x: " << myEntity.print_x() << endl;
}
