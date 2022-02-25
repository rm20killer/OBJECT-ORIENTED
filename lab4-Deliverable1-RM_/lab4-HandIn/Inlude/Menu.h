#pragma once
#include <iostream>
using namespace std;
class Menu
{
private:
	bool bInMainMenu;
public:
	int MainMenu();
	void intract();
	string getName();
	int getPetType();
	int getCatType();
};