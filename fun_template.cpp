#include <iostream>
using namespace std;

template <typename T>
T find_max(T a, T b)
{
    if (a > b)
        return a;
    else
        return b;
}

int main()
{
    double x = 10.23;
    double y = 45.56;

    int a = 30, b = 45;

    cout << "Double Max: " << find_max(x, y) << endl;
    cout << "Int Max: " << find_max(a, b) << endl;
}

// At compile time, based on how we use the function template in our function
// calls, the compiler will decide to generate different type-specific versions
// of the function to be used at run-time (called template functions).  The
// process is visualized below.
//
//
// double x = 10.6                           int m = 5;
// double y = 5.3;                           int n = 3;
//
// find_max(x,y)     <- Function Calls ->    find_max(m,n)
//              \                           /
//               \                         /
//                \                       /
//                 \                     /
//
//                  template <typename T>
//                  T find_max(T a, T b)
//  Function        {
//  Template ->       if (a > b) return a;
//                    else return b;
//                  }
//
//                 /               \
//                /                 \
//               /                   \
//              /                     \
//
// double find_max(double a,       int find_max(int a,
//                 double b)                    int b)
// {                               {
//   if (a > b) return a;            if (a > b) return a;
//   else return b;                  else return b;
// }                               }
//
//                \                  /
//                 Template Functions