#pragma once

#include <iostream>
#include "quadruped.h"

using namespace std;

class Dog:public Quadruped
//makes "Dog" a inheritance of Quadruped
{
public:
	void talk(); //talk
};

