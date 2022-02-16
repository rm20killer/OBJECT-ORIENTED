#pragma once

#include <iostream>
#include "quadruped.h"

using namespace std;

class Hamster:public Quadruped
//makes "Hamster" a inheritance of Quadruped
{
public:
	void talk(); //talk
};

