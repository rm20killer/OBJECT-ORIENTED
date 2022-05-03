#pragma once
class Engine
{
public:
	void run();
private:
	//#varibles#//
	//window varibles//
	int ScreenWidth = 800;
	int ScreenHeight = 650;
	//Scene handing varibles//
	bool bPlaying = false;
	bool bInMenu = true;
	bool bPlayed = false;
	bool bWin = false;
	//game varibles//
	int difficulty = 1;
};