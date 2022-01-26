#include "student.h"
#include <iostream>

using namespace std;


int main()
{
    StudentClass student;
    string firstName = "test";
    string LastName = "last";
    int BirthOfDate = 260103;

    student.Student(firstName, LastName, BirthOfDate);
    cout << student.getFirstName();
    cout << " ";
    cout << student.getLastName();
    cout << " ";
    cout << student.getDateOfBirth();
    cout << "\n";
    cout << student.getReadableDOB();
}
