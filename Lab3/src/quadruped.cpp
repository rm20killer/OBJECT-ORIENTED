#include "quadruped.h"

#include <iostream>

using namespace std;

void Quadruped::raiseLeg(int legIndex)
{
	if(legIndex >=0 && legIndex<kiNoLegs)
	{
		//if input is greater than 0 but lower than amount of legs
		//to make the user does not try and increase more legs than the animal has.
		legs[legIndex].raise();
		//then raise leg
	}
}

void Quadruped::lowerLeg(int legIndex)
{
	if(legIndex>=0 && legIndex< kiNoLegs)
	{
		//if input is greater than 0 but lower than amount of legs
		//to make the user does not try and increase more legs than the animal has.
		legs[legIndex].lower();
		//then lower leg
	}
}

void Quadruped::CheckLegs()
{
	for(int i=0;i<4;i++)
	{
		printf("%i:", i);
		int irasied = legs[i].display();
		if(irasied == 1){
			printf("raised \n");
		}
		else
		{
			printf("lowered \n");
		}
	}
}
