#pragma once

#include <iostream>
#include "quadruped.h"

using namespace std;

class Cat:public Quadruped
//makes "Cat" a inheritance of Quadruped
{
protected:
	int iJumpHeight = 1;
public:
	void talk(); //talk
	void WhatIsTheCatDoing();

	//method overload//
	void jump(int iJump);
	void jump();

};

