#include <iostream>
using namespace std;

class Grade
{
    double grade;

public:
    Grade(double grade)
    {
        this->grade = grade;
    }

    operator double()
    {
        return grade;
    }
    operator char()
    {
        if (grade > 80)
            return 'A';
        else if (grade > 60)
            return 'B';
        else if (grade > 30)
            return 'C';
        else
            return 'F';
    }
};

int main()
{
    Grade gradeA(74.32);

    char char_grade = gradeA;
    double dbl_grade = gradeA;

    cout << "chr_grade: " << char_grade << endl
         << "dbl_grade: " << dbl_grade << endl;
}