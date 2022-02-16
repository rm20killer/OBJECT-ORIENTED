// Name: Roshan Manojkumar, P2657789

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


//
bool bPlaying;
int main()
{
	GamePlay gameplay;
	Menu menu;
	int iPlaying = menu.MainMenu();
	//Gameplay.startup();

	if (iPlaying == 1 ) {
		bPlaying = true;
		menu.intract();
	}
	else {
		bPlaying = false;
	}
	//while (playing) {
	//}
	if (bPlaying == false) {
		system("pause");
		return 0;
	}
}
