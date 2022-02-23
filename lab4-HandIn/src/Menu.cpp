#include "menu.h"
#include "GamePlay.h"
#include <iostream>

using namespace std;


GamePlay Gameplay;

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
		if (iInput == 9)
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

void Menu::intract()
{
	bool bInmenu = true;
	while (bInmenu) {
		system("CLS");
		int iInput;
		printf("#= interact with %s =#\n", Gameplay.getName().c_str());
		printf("1) Raise leg\n");
		printf("2) Lower leg\n");
		if (Gameplay.getPetType() == 1) {
			printf("3) jump\n");
			printf("4) check on %s \n", Gameplay.getName().c_str());
		}
		printf("9) exit\n");
		cin >> iInput;
		if (iInput == 1 || iInput == 2)
		{
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
			Gameplay.Jump();
			system("pause");
		}
		else if (iInput == 4 && Gameplay.getPetType() == 1)
		{
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