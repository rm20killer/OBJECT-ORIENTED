#pragma once
#include <iostream>
class Timer {
public:
	void reset();
	void update();
	std::string returnTime();
private:
	int iMinutes = 0;
	int iSeconds = 0;
	std::time_t unixtime;
};