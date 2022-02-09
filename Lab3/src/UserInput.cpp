#include "UserInput.h"

#include <iostream>
#include <string>

#include "Cat.h"
#include "dog.h"

using namespace std;

void Userinput::startup()
{
	printf("Enter pet name \n");
	cin >> sPetName;
	printf("\n What type of pet do you want? \n");
	printf("1) Dog \n");
	printf("2) Cat \n");
	cin >> iPetType;
	printf("%s said '", sPetName.c_str());
	if(iPetType==1)
	{
		Dog userPet;
		userPet.talk();
	}
	else if(iPetType==2)
	{
		Cat userPet;
		userPet.talk();
	}
	printf("'\n");
}

void Userinput::intract()
{
	{
		if (iPetType == 1)
		{
			Dog userPet;
		}
		else if (iPetType == 2)
		{
			Cat userPet;
		}
		userPet.raiseLeg(1);
	}

}