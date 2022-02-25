// Name: Roshan Manojkumar, P2657789
// A program that used class, method overloading and inheritance.
// This program is a simple pet sim. Where the user can lower/raise the pets leg, if user select cat they can also make the pet jump (which uses method overloading) & check what the cat is doing.

//#################################################################################################################//
//                                                 Using C++ Core Guildlines                                       //
//                                 http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines                     //
//                                              And IMAT1907 Naming Standards				                       //
//https://vle.dmu.ac.uk/webapps/blackboard/execute/content/file?cmd=view&content_id=_5286974_1&course_id=_592078_1 //
//#################################################################################################################//


#include <iostream>
#include "GamePlay.h"
#include "Menu.h"
using namespace std;
int main()
{
	printf("For method overloading and subclass is in the pet Cat (option 2 in pet selection menu) \n");
	system("pause");
	system("CLS");
	GamePlay gameplay;
	Menu menu;
	int iPlaying = menu.MainMenu();
	//get the return value from the MainMenu function from the menu class
	if (iPlaying == 1) 
	{
		menu.intract();
		//enter the intract screen if playing is true
	}
	else if (iPlaying == 0) 
	{
		//exit
		system("pause");
		return 0;
	}
}
