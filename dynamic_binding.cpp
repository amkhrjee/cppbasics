#include <iostream>
using namespace std;

class Student
{
public:
    string name;
    Student(string name) : name(name){};
    virtual void print()
    {
        cout << "name: " << name << endl;
    }
};

class MedicalStudent : public Student
{
public:
    string speciality;
    MedicalStudent(string name, string speciality)
        : speciality(speciality),
          Student(name) {}
    void print() override
    {
        cout << "name: " << name << " : " << speciality << endl;
    }
};

int main()
{
    Student *students[] = {
        new Student("Rishi"),
        new Student("Aakash"),
        new MedicalStudent("Lisa", "Pediatrics"),
        new MedicalStudent("Liz", "Oncology")};

    for (Student *elem : students)
        elem->print();
    // for (int i = 0; i < 4; i++)
    //     students[i]->print();
}