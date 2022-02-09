#include "leg.h"

#include <cstdio>

Leg::Leg()
{
	bRaised = false;
}

void Leg::raise()
{

	bRaised = true;
	printf("raised there legs\n");
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
