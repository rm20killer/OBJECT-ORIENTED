#pragma once
//outdoor cat

#include <Pets/Cat.h>

class Bengal :public Cat
{
protected:
	int iJumpHeight = 10;
	static const int iNumOfResponse = 7;
	string asResponse[iNumOfResponse] = {
		"is walking around outside.\n", //0
		"is chasing a bird.\n", //1
		"is purring at you to go outside.\n", //2
		"is outside looking for food.\n", //3
		"is at the garden sitting on the outdoor table. \n", //4
		"is fast asleep on your lap, you cant get up anymore.\n", //5
		"has stole a pizza from a stranger outside.\n", //6
	};
public:
	int GetMaxJump();
	string GetRandomResponse();
};