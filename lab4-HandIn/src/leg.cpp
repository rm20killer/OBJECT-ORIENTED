#include "leg.h"

#include <cstdio>
#include <iostream>

using namespace std;
Leg::Leg()
{
	bRaised = false;
}

void Leg::raise()
{
	bRaised = true;
}

void Leg::lower()
{
	bRaised = false;
	printf("lowered there legs\n");
}

int Leg::display()
{
	int irasied = 0;
	if(bRaised == false)
	{
		irasied = 0;
	}
	else
	{
		irasied = 1;
	}
	return irasied;
}
