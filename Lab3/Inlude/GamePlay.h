#pragma once
#include <iostream>
using namespace std;

class GamePlay
{
private:
	int iPetType;
	int iCatType;
	string sPetName;
public:
	string asPets[3] = {"Dog","Cat","Hamster"};
	string getName();
	void startup();
	void RaiseLeg(int leg);
	void LowerLeg(int leg);
	void Jump();
	int getPetType();
	int getCatType();
};
