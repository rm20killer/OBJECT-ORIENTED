#include <Pets/Cat.h>
#include <Pets/Cats/Bengal.h>
#include <Pets/Cats/Sphynx.h>
#include <GamePlay.h>

#include <iostream>

GamePlay gameplay;

void Cat::talk()
{
	printf("meow");
	//display "meow"
}

void Cat::jump(int iJump)
{
	if (gameplay.getCatType() == 1)
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
		printf("has jumped %im\n", iJump);
	}
	else
	{
		printf("could not jump that high\n");
	}
}

void Cat::jump()
{
	if (gameplay.getCatType() == 1)
	{
		Bengal userPet;
		iJumpHeight = userPet.GetMaxJump();
	}
	else {
		Sphynx userPet;
		iJumpHeight = userPet.GetMaxJump();
	}
	int iComputerChoice = (rand() % iJumpHeight-1) + 1;
	printf("has jumped %im, ", iComputerChoice);
}

void Cat::WhatIsTheCatDoing()
{
	if (gameplay.getCatType() == 1)
	{
		Bengal userPet;
		printf("%s %s", gameplay.getName().c_str(), userPet.GetRandomResponse().c_str());
	}
	else {
		Sphynx userPet;
		printf("%s %s", gameplay.getName().c_str(), userPet.GetRandomResponse().c_str());
	}
}
