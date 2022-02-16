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
		printf("%s raised \n", aslegType[legIndex].c_str());
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
		printf("%s lowered \n", aslegType[legIndex].c_str());
	}
}

void Quadruped::CheckLegs()
{
	for (int i = 0; i < kiNoLegs; i++)
	{
		printf("%i:", i);
		int irasied = legs[i].display();
		//loop all through all the legs and check if is rasied or not from the leg class
		if(irasied == 1){
			//if the return value is 1 than leg raised
			printf("%s is raised \n", aslegType[i].c_str());
			//From the array legType find which leg the value correspond to
		}
		else
		{
			//if the return value is 0 than lowered raised
			printf("%s is lowered \n", aslegType[i].c_str());
		}
	}
}
