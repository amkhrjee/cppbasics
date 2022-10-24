#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int x = 0x12A;
    int y = 0b1010;

    cout << "x: " << setbase(16) << x << endl
         << "y: " << setbase(8) << y << endl
         << 0xabcd1223 << endl;
}