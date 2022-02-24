#pragma once
//indoor cat

#include <Pets/Cat.h>

class Sphynx:public Cat
//makes "Sphynx" a inheritance of Cat
{
protected:
	int iJumpHeight = 3;
	static const int iNumOfResponse = 8;
	//array length
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
	//uses the array length to set the number of values of the array
public:
	int GetMaxJump();
	string GetRandomResponse();
	//void jump(int iJump);
	//void jump();
};