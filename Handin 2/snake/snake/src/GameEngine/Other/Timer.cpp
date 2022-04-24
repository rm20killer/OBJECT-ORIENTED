#include "..\..\..\include\GameEngine\Other\Timer.h"
#include <string>

void Timer::reset()
{
	unixtime= std::time(nullptr);
	std::cout << unixtime << std::endl;
}

void Timer::update()
{ 
	std::time_t currentTime = std::time(nullptr);
	//change currentTime to int
	int time = currentTime - unixtime;
	//std::cout << time << std::endl;
	//if time is over 60 divide by 60
	iMinutes = int(time / 60);
	float fRemaining_Seconds = time - (iMinutes * 60);
	iSeconds = int(fRemaining_Seconds);
	//std::cout << iMinutes << ":" << iSeconds << std::endl;
}

std::string Timer::returnTime()
{
	std::string sSecounds="00";
	std::string sMinutes= "00";
	if (iSeconds < 10)
	{
			sSecounds = "0" + std::to_string(iSeconds);
	}
	else
	{
		sSecounds = std::to_string(iSeconds);
	}
	if (iMinutes < 10)
	{
			sMinutes = "0" + std::to_string(iMinutes);
	}
	else
	{
		sMinutes = std::to_string(iMinutes);
	}
	std::string ReadableTime = sMinutes + ":" + sSecounds;
	//std::cout << ReadableTime << std::endl;
	return ReadableTime;
}