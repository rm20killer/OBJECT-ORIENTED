#pragma once
#include <iostream>
using namespace std;

class GamePlay
{
private:
	int iPetType=0;
	int iCatType=0;
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
	void WhatIsTheCatDoing();
};
