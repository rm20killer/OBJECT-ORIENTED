#pragma once

#include <iostream>
#include "quadruped.h"

using namespace std;

class Cat:public Quadruped
//makes "Cat" a inheritance of Quadruped
{
public:
	void talk(); //talk
};

