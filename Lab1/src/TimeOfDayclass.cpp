#include "TimeOfDayclass.h"

#include <iostream>
#include <string>
#include <ctime>
using namespace std;

float TimeOfdayclass::TimeOfday(){
	float current_time = time(NULL);
	//string time = ctime(current_time);
	return current_time;
}


string TimeOfdayclass::getReadableDOB(int ddmmyy)
{
	string day = std::to_string(ddmmyy);
	day = day.substr(0, day.size() - 4);

	string month = std::to_string(ddmmyy);
	month = month.substr(2, month.size() - 4);

	string year = std::to_string(ddmmyy);
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