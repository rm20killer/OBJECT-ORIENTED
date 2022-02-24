#include "menu.h"
#include "GamePlay.h"
#include <iostream>

using namespace std;

GamePlay Gameplay;

/// <MainMenu function>
/// </summary>
/// get user input to either exit or play. Using a while loop so it user must input a valid input.
/// 
/// <returns><0 if exiting or 1 if playing>
int Menu::MainMenu()
{
	bInMainMenu = true;
	while (bInMainMenu)
	{
		int iInput;
		printf("#= MENU =#\n");
		printf("1) Play\n");
		printf("9) exit\n");
		cin >> iInput;
		if (iInput == 9) //exit
		{
			bInMainMenu = false;
			return 0;
		}
		else if (iInput == 1) {
			//if user wasnt to play enter start up from userinput class
			bInMainMenu = false;
			Gameplay.startup();
			system("pause");
			return 1;
		}
		else
		{
			//clear screen if invalid input
			printf("Invalid input\n");
			system("pause");
			system("CLS");
		}
	}
	return 0;
}

/// <intract function>
/// </summary>
/// get user input for intractions that the user can do with the pet. If valid input it will call in the function from gameplay class.
/// 

void Menu::intract()
{
	bool bInmenu = true;
	while (bInmenu) {
		//loop so they can only exit if they press "9"
		system("CLS"); //clear screenS
		int iInput;
		printf("#= interact with %s =#\n", Gameplay.getName().c_str());
		//get the name of the pet from gameplay class and than covert the string so it display correctly  
		printf("1) Raise leg\n");
		printf("2) Lower leg\n");
		if (Gameplay.getPetType() == 1) {
			//only show option 3 and 4 if the pet is a cat
			printf("3) jump\n");
			printf("4) check on %s \n", Gameplay.getName().c_str());
		}
		printf("9) exit\n");
		cin >> iInput;
		if (iInput == 1 || iInput == 2)
		{
			//as the input for lower and raise are the same put them in one if to display inputs
			int iLeg;
			printf("#= interact with %s =#\n", Gameplay.getName().c_str());
			printf("0) Front left leg\n");
			printf("1) Front right leg\n");
			printf("2) Back left leg\n");
			printf("3) Back right leg\n");
			printf("9) exit\n");
			cin >> iLeg;
			if (iInput == 1) {
				Gameplay.RaiseLeg(iLeg);
				system("pause");
			}
			else {
				Gameplay.LowerLeg(iLeg);
				system("pause");
			}
		}
		else if(iInput==3&&Gameplay.getPetType()==1)
		{
			//makes sure that the pet is a cat and if input is "3"
			Gameplay.Jump();
			system("pause");
		}
		else if (iInput == 4 && Gameplay.getPetType() == 1)
		{
			//makes sure that the pet is a cat and if input is "4"
			Gameplay.WhatIsTheCatDoing();
			system("pause");
		}
		else if (iInput == 9) {
			bInmenu = false;
		}
		else {
			//clear screen if invalid input
			printf("Invalid input\n");
			system("pause");
			system("CLS");
		}
	}
}

/// <getName function>
/// </summary>
/// used to make sure, if pet name is called from a different Class like "Cat", that the data is what is the same throughout the program.
/// It does this by calling the getName function from the GamePlay class and then returns that back the class is being called from.
/// 
/// <returns><a string value for the pet name>

string Menu::getName()
{
	string sPetName=Gameplay.getName();
	return sPetName;
}

/// <getPetType function>
/// </summary>
/// used to make sure, if pet name is called from a different Class like "Cat", that the data is what is the same throughout the program.
/// It does this by calling the getPetType function from the GamePlay class and then returns that back the class is being called from.
/// 
/// <returns><an int value for the pet type>
int Menu::getPetType()
{
	int iPetType = Gameplay.getPetType();
	return iPetType;
}

/// <getCatType function>
/// </summary>
/// used to make sure, if pet name is called from a different Class like "Cat", that the data is what is the same throughout the program.
/// It does this by calling the getCatType function from the GamePlay class and then returns that back the class is being called from.
/// 
/// <returns><an int value for the cat type>
int Menu::getCatType()
{
	int iCatType = Gameplay.getCatType();
	return iCatType;
}