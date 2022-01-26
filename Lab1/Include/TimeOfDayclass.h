#pragma once

using namespace std;

class TimeOfdayclass
{
private:
	int iHours;
	int iMinutes;
	int iSecounds;

public:
	float TimeOfday();
	std::string getReadableDOB(int ddmmyy);
};