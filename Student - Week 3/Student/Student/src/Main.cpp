#include "Student.h"
#include<iostream>



int main() {

	Student mainStudent;
	Student secondStudent("Smith","Bob", 100499); //Can be problems with octal digits if 0 is used first.


	//Pass in variables for the mainstudent.
	mainStudent.setFirstName("Chris");
	mainStudent.setLastName("Jones");
	mainStudent.setBirthDate(20058);

	//Add modules for second student;
	secondStudent.inputModule("C++");
	secondStudent.inputModule("Intro OO");

	//Put the information on the console.
	std::cout << "Student Details: " << mainStudent.getFirstName() << " " << mainStudent.getLastName() << std::endl;


	system("pause");
	return 0;
}