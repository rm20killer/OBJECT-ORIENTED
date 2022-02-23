#include "GamePlay.h"

#include <iostream>
#include <string>

#include <Pets/Cat.h>
#include <Pets/Cats/Bengal.h>
#include <Pets/Cats/Sphynx.h>
#include <Pets/Dog.h>
#include <Pets/Hamster.h>
using namespace std;

string GamePlay::getName()
{
	return sPetName;
}

int GamePlay::getPetType()
{
	return iPetType;
}

int GamePlay::getCatType()
{
	return iCatType;
}

void GamePlay::startup()
{
	//string aPetType[3] = { "Dog","Cat","Hamster"};
	bool bInMenu = true;
	while (bInMenu)
	{
		char CUser_Input;
		system("CLS");
		printf("What type of pet do you want? \n");
		for (int i = 0; i < 3; i++)
		{
			int x = i + 1;
			printf("%i) %s \n", x, asPets[i].c_str());
		}
		//instead of using a printf for all the types of pets using an for loop and an array (which is stored in the Header file) to display it.
		cin >> CUser_Input;
		iPetType = int(CUser_Input);
		//coveret char into inv this also covert the number into ASCII.
		if (iPetType >= 49 && iPetType < 52) {
			//check if value is between 1 and 3
			bInMenu = false;
			printf("Enter name of your %s\n", asPets[iPetType].c_str());
			cin >> sPetName;
			printf("%s said '", sPetName.c_str());
			if (iPetType == 49) //1 (dog)
			{
				iPetType = 0;
				Dog userPet;
				userPet.talk();
			}
			else if (iPetType == 50) //2 (Cat)
			{
				iPetType = 1;
				//cat have a subclass that the user can pick from
				system("CLS");
				printf("What type of Cat is %s? \n", sPetName.c_str());
				printf("1) Bengal (Outdoors cat) \n");
				printf("2) Sphynx (Indoors cat) \n");
				cin >> CUser_Input;
				iCatType = int(CUser_Input);
				if (iCatType == 49) //1
				{
					iCatType = 1;
					Bengal userPet;
					userPet.talk();
				}
				else if (iCatType == 50) //2
				{
					iCatType = 2;
					Sphynx userPet;
					userPet.talk();
				}
				else { //0 (No spefic type)
					int iComputerChoice = (rand() % 1) + 1;
					//get a random number from 1 to 2
					printf("Invalid input\n");
					printf("Computer picked option %i for you \n", iComputerChoice);
					system("pause");
					if (iCatType == 1) //1
					{
						Bengal userPet;
						userPet.talk();
					}
					else if (iCatType == 2) //2
					{
						Sphynx userPet;
						userPet.talk();
					}
				}

			}
			else if (iPetType == 51) //3
			{
				iPetType = 2;
				Hamster userPet;
				userPet.talk();
			}
			else {
				printf("Invalid input\n");
				system("pause");
				bInMenu = true;
				return;
			}
			printf("'\n");
		}
		else {
			printf("Invalid input\n");
			system("pause");
		}
	}
}


void GamePlay::RaiseLeg(int leg)
{

	if (iPetType == 0)
	{
		Dog userPet;
		userPet.raiseLeg(leg);
	}
	else if (iPetType == 1)
	{
		if (iCatType == 1)
		{
			Bengal userPet;
			userPet.raiseLeg(leg);
		}
		else if (iCatType == 2)
		{
			Sphynx userPet;
			userPet.raiseLeg(leg);
		}
	}
	else if (iPetType == 2)
	{
		Hamster userPet;
		userPet.raiseLeg(leg);
	}
}

void GamePlay::LowerLeg(int leg)
{
	if (iPetType == 0)
	{
		Dog userPet;
		userPet.lowerLeg(leg);
	}
	else if (iPetType == 1)
	{
		if (iCatType == 1)
		{
			Bengal userPet;
			userPet.lowerLeg(leg);
		}
		else if (iCatType == 2)
		{
			Sphynx userPet;
			userPet.lowerLeg(leg);
		}
	}
	else if (iPetType == 2)
	{
		Hamster userPet;
		userPet.lowerLeg(leg);
	}
}

void GamePlay::Jump()
{
	printf("How high should the chat jump \n");
	printf("entering `0` will give a random jump height\n");
	int ijump;
	cin >> ijump;
	if (ijump == 0) {
		if (iCatType == 1)
		{
			Bengal userPet;
			userPet.jump();
		}
		else if (iCatType == 2)
		{
			Sphynx userPet;
			userPet.jump();
		}
	}
	else {
		if (iCatType == 1)
		{
			Bengal userPet;
			userPet.jump(ijump);
		}
		else if (iCatType == 2)
		{
			Sphynx userPet;
			userPet.jump(ijump);
		}
	}
}

void GamePlay::WhatIsTheCatDoing()
{
	if (iCatType == 1)
	{
		Bengal userPet;
		userPet.WhatIsTheCatDoing();
	}
	else if (iCatType == 2)
	{
		Sphynx userPet;
		userPet.WhatIsTheCatDoing();
	}
}