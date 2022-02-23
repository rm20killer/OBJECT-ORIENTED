#pragma once

#include <iostream>
#include "quadruped.h"

using namespace std;

class Cat:public Quadruped
//makes "Cat" a inheritance of Quadruped
{
protected:
	int iJumpHeight = 5;
public:
	void talk(); //talk
	void jump(int iJump);
	void jump();
	void WhatIsTheCatDoing();
};

