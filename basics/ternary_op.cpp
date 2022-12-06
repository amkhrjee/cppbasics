// using ternary operator as an lvalue!
// more on lvalue: https://www.notion.so/amkhrjee/Understanding-lvalues-and-rvalues-in-C-C-01bcbdc9686f4a279919b6bbf1274472

#include <iostream>
using namespace std;

int main()
{
    int grade = 0, pass_total = 0, fail_total = 0;

    while (true)
    {
        cout << "Enter Grade (Enter -1 to Quit): ";
        cin >> grade;

        if (grade == -1)
            break;

        // what a fucking elegant line
        ((grade >= 50) ? pass_total : fail_total) += 1;

        cout << "Total Pass: " << pass_total << endl
             << "Fail Total: " << fail_total << endl;
    }
}