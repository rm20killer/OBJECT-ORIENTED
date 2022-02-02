#include "student.h"
#include <iostream>
#include <string>
#include <ctime>

//StudentClass::Student(){}
string FirstName;
string LastName;
int BirthOfDate; //ddmmyy exmaple 260122

void StudentClass::Student(string FirstNameIn, string LastnameIn, int BirthOfDateIn) {
	FirstName = FirstNameIn;
	LastName = LastnameIn;
	BirthOfDate = BirthOfDateIn;
	printf("\nFirst name has been set to %s \n", FirstNameIn.c_str());
	printf("Last name has been set to %s \n", LastnameIn.c_str());
	printf("Date of Birth set to %i \n", BirthOfDateIn);
}

void StudentClass::setFirstName(string fristIn)
{
	FirstName = fristIn;
	printf("\nFirst name has been set to %s \n", FirstName.c_str());
}

void StudentClass::setLastName(string LastIn)
{
	LastName = LastIn;
	printf("\nLast name has been set to %s \n", LastName.c_str());
}

void StudentClass::setBirthOfdate(int BirthOfDateIn)
{
	int LengthOfinput = std::to_string(BirthOfDateIn).length();
	if (LengthOfinput != 6){
		printf("Date of birth should be 6 charector long in the format ddmmyy, \n Example 26 jan 2003 would be : 260103");
		return;
	}
	
	BirthOfDate = BirthOfDateIn;
	printf("\Birth of date has been set to %i \n", BirthOfDate);
}


string StudentClass::getFirstName()
{
	return FirstName;
}

string StudentClass::getLastName()
{
	return LastName;
}

int StudentClass::getDateOfBirth()
{
	return BirthOfDate;
}

string StudentClass::getReadableDOB()
{
	string day = std::to_string(BirthOfDate);
	day = day.substr(0, day.size() - 4);

	string month = std::to_string(BirthOfDate);
	month = month.substr(2, month.size() - 4);

	string year = std::to_string(BirthOfDate);
	year = year.substr(4, year.size());

	int CurrentUnix = std::time(nullptr);
	int currentyear;
	currentyear = 1970 + CurrentUnix / 31536000;
	currentyear = currentyear - 2000;
	string scurrentyear = std::to_string(currentyear);
	if (stoi(year) <= currentyear) {
		year = "20" + year;
	}
	else {
		year = "19" + year;
	}

	string sBirthOfDate = day + "/" + month + "/" + year;
	//string month = getDateOfBirth();
	//string year = getDateOfBirth();
	return sBirthOfDate;
}