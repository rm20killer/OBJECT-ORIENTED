#include "GamePlay.h"

#include <iostream>
#include <string>

#include <Pets/Cat.h>
#include <Pets/Dog.h>
#include <Pets/Hamster.h>
using namespace std;

string GamePlay::getName()
{
	return sPetName;
}

void GamePlay::startup()
{
	bool bInMenu=true;
	while (bInMenu)
	{
		system("CLS");
		printf("\n What type of pet do you want? \n");
		printf("1) Dog \n");
		printf("2) Cat \n");
		printf("3) Hamster \n");
		cin >> iPetType;
		if (iPetType >= 1 && iPetType < 4) {
			bInMenu = false;
			iPetType = iPetType - 1;
			printf("Enter name of your %s\n", asPets[iPetType].c_str());
			cin >> sPetName;
			printf("%s said '", sPetName.c_str());
			if (iPetType == 1)
			{
				Dog userPet;
				userPet.talk();
			}
			else if (iPetType == 2)
			{
				Cat userPet;
				userPet.talk();
			}
			else if (iPetType == 3)
			{
				Hamster userPet;
				userPet.talk();
			}
			printf("'\n");
		}
		else {
			bInMenu = true;
		}
	}
}

void GamePlay::RaiseLeg(int leg)
{

	if (iPetType == 1)
	{
		Dog userPet;
		userPet.raiseLeg(leg);
	}
	else if (iPetType == 2)
	{
		Cat userPet;
		userPet.raiseLeg(leg);
	}
}

void GamePlay::LowerLeg(int leg)
{
	if (iPetType == 1)
	{
		Dog userPet;
		userPet.lowerLeg(leg);
	}
	else if (iPetType == 2)
	{
		Cat userPet;
		userPet.lowerLeg(leg);
	}
}