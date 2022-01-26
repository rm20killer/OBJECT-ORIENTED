#pragma once

#include <iostream>
#include <vector>


using std::string;
using std::vector;

class StudentClass {
private:
	string FirstName;
	string LastName;
	int BirthOfDate;

public:
	//Student();
	void Student(string FirstName, string Lastname, int BirthOfDate);

	void setFirstName(string fristIn);
	void setLastName(string LastIn);

	string getFirstName();
	string getLastName();
	float getDateOfBirth();
	string getReadableDOB();
};