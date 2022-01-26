#include "student.h"
#include <iostream>
#include <string>
#include <ctime>

//StudentClass::Student(){}
string FirstName;
string LastName;
int BirthOfDate; //ddmmyy exmaple 260122
void StudentClass::Student(string FirstNameIn, string LastnameIn, int BirthOfDateIn) {
	FirstName = FirstNameIn ;
	LastName = LastnameIn;
	BirthOfDate = BirthOfDateIn;
}

void StudentClass::setFirstName(string fristIn)
{
	FirstName = fristIn;
	printf("First name has been set");
}

void StudentClass::setLastName(string LastIn)
{
	LastName = LastIn;
	printf("First name has been set");
}

string StudentClass::getFirstName()
{
	return FirstName;
}

string StudentClass::getLastName()
{
	return LastName;
}

float StudentClass::getDateOfBirth()
{
	return float(BirthOfDate);
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
	 currentyear = 1970 + CurrentUnix / 31536000; // 31536000 is secounds into year
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
