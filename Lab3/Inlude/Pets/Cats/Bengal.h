#pragma once
//outdoor cat

#include <Pets/Cat.h>

class Bengal :public Cat
{
public:
	int iMaxJump = 50;
private:
	void jump();
	void jump(int iJumpHeight);
};