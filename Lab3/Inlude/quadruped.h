#pragma once

#include "leg.h"
class Quadruped
{
protected:
	//can be used by only  by this class and subclasses.

	//the amount of legs all Quadruped have
	static const int kiNoLegs = 4;

	//creates an array which is connected to leg.h, each leg being a different value of leg
	Leg legs[kiNoLegs];
public:
	void raiseLeg(int legIndex);
	void lowerLeg(int legIndex);
	void CheckLegs();
};