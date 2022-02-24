#include "leg.h"

#include <cstdio>
#include <iostream>

using namespace std;
Leg::Leg()
{
	bRaised = false;
}

/// <raise function>
/// </summary>
/// turn the raised boolen to true for a spefic leg.
void Leg::raise()
{
	bRaised = true;
	//printf("raised there legs\n");
}

/// <lower function>
/// </summary>
/// turn the raised boolen to false for a spefic leg.
void Leg::lower()
{
	bRaised = false;
	//printf("lowered there legs\n");
}

/// <display function>
/// </summary>
/// check if a leg is raised or not and return a value.
/// 
/// <returns><1 or 0 depending on it if reaised or not>
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
