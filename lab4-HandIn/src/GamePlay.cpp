#include "GamePlay.h"

#include <iostream>
#include <string>

#include <Pets/Cat.h>
#include <Pets/Cats/Bengal.h>
#include <Pets/Cats/Sphynx.h>
#include <Pets/Dog.h>
#include <Pets/Hamster.h>
using namespace std;

/// getName function
/// 
/// <returns><an string value for the pet name>
string GamePlay::getName()
{
	//printf("%s\n", sPetName.c_str());
	return sPetName;
}
/// getPetType function
/// 
/// <returns><an int value for the pet type>
int GamePlay::getPetType()
{
	//printf("%i\n", iPetType);
	return iPetType;
}

/// getCatType function
/// 
/// <returns><an int value for the cat type>
int GamePlay::getCatType()
{
	//printf("%i\n", iCatType);
	return iCatType;
}

/// <startup function>
/// </summary>
/// This function display selections the user can pick from and than allow the user to put an input which allow them to
/// select the pet type, name and if cat was selected a sub category. This data is than saved so it can be used later on.
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
			if (iPetType == 49) //1 (dog)
			{
				printf("%s said '", sPetName.c_str());
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
				CUser_Input = int(CUser_Input);
				if (CUser_Input == 49) //1
				{
					printf("%s said '", sPetName.c_str());
					iCatType = 1;
					Bengal userPet;
					userPet.talk();
				}
				else if (CUser_Input == 50) //2
				{
					printf("%s said '", sPetName.c_str());
					iCatType = 2;
					Sphynx userPet;
					userPet.talk();
				}
				else { //0 (No spefic type)
					int iComputerChoice = (rand() % 1) + 1;
					//get a random number from 0 to 1 than adds 1 resulting in a number from 1 to 2.
					printf("Invalid input\n");
					printf("Computer picked option %i for you \n", iComputerChoice);
					system("pause");
					printf("%s said '", sPetName.c_str());
					if (iComputerChoice == 1) //1
					{
						iCatType = 1;
						Bengal userPet;
						userPet.talk();
					}
					else if (iComputerChoice == 2) //2
					{
						iCatType = 2;
						Sphynx userPet;
						userPet.talk();
					}
				}

			}
			else if (iPetType == 51) //3
			{
				printf("%s said '", sPetName.c_str());
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
			//printf("%i\n", iCatType);
		}
		else {
			printf("Invalid input\n");
			system("pause");
		}
	}
}

// Interaction functions
// I could not figure out how to call the class function outside of the same if statement so the class function were put in side each if statment. 


/// <RaiseLeg function><param: int "leg number">
/// </summary>
/// This Raises the leg of the pet by redirecting the function to the right class
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
/// <LowerLeg function>
/// </summary>
/// This Lowers the leg of the pet by redirecting the function to the right class
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

//cat only functions

/// <Jump function> (Contains method overloading)
/// </summary>
/// Ask the user how high the cat should jump and than call the function
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


/// <WhatIsTheCatDoing function>
/// </summary>
/// redirects the function to the right class
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

	/*TESTING
	if (iCatType == 1)
	{
		Bengal userPet;
		printf(" %s %s", sPetName.c_str(), userPet.GetRandomResponse().c_str());
	}
	else {
		Sphynx userPet;
		printf(" %s %s", sPetName.c_str(), userPet.GetRandomResponse().c_str());
	}
	  TESTING*/
}