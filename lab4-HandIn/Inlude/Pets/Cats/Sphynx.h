#pragma once
//indoor cat

#include <Pets/Cat.h>

class Sphynx:public Cat
{
protected:
	int iJumpHeight = 6;
	static const int iNumOfResponse = 8;
	string asResponse[iNumOfResponse] = {
		"is layed on your bed.\n", //0
		"has pulled some wires out of your computer.\n", //1
		"is laying on your desk.\n", //2
		"is meowing at you for food.\n", //3
		"is at the windowing looking outside.\n", //4
		"is fast asleep on your lap, you cant get up anymore.\n", //5
		"has jumped on the window and knocked off a vase.\n", //6
		"is purring at you to play.\n", //7
	};
public:
	int GetMaxJump();
	string GetRandomResponse();
};