#include <Pets/Cat.h>
#include <Pets/Cats/Bengal.h>
#include <Pets/Cats/Sphynx.h>
#include <GamePlay.h>
#include <menu.h>
#include <iostream>

Menu menu;

void Cat::talk()
{
	printf("meow");
	//display "meow"
}
/// <jump function><param: Jump Hight>
/// </summary>
/// grabs cat type from gameplay class but uses the menu so the value is the same as the set up value.
/// Grabs max hight from the child class than check if the max hight is lower or the same as the value user gave
/// 
void Cat::jump(int iJump)
{
	int iCatType = menu.getCatType();
	if (iCatType == 1)
	{
		Bengal userPet;
		iJumpHeight = userPet.GetMaxJump();
	}
	else {
		Sphynx userPet;
		iJumpHeight = userPet.GetMaxJump();
	}
	if (iJumpHeight >= iJump)
	{
		printf("has jumped %i feet\n", iJump);
	}
	else
	{
		printf("could not jump that high\n");
	}
}
/// <jump function>
/// </summary>
/// grabs cat type from gameplay class but uses the menu so the value is the same as the set up value.
/// Grabs max hight from the child class and use that for the max number the random number gen can make
void Cat::jump()
{
	int iCatType = menu.getCatType();
	if (iCatType == 1)
	{
		Bengal userPet;
		iJumpHeight = userPet.GetMaxJump();
	}
	else {
		Sphynx userPet;
		iJumpHeight = userPet.GetMaxJump();
	}
	int iComputerChoice = (rand() % iJumpHeight - 1) + 1; // generates a random number
	printf("has jumped %i feet, ", iComputerChoice);
}
/// <WhatIsTheCatDoing function>
/// </summary>
///	calls value from menu and child and display it.
///
void Cat::WhatIsTheCatDoing()
{
	int iCatType = menu.getCatType();
	if (iCatType == 1)
	{
		Bengal userPet;
		printf("%s %s", menu.getName().c_str(), userPet.GetRandomResponse().c_str());
	}
	else {
		Sphynx userPet;
		printf("%s %s", menu.getName().c_str(), userPet.GetRandomResponse().c_str());
	}
}
