#include "menu.h"
#include "student.h"
#include <iostream>
#include <fstream>

using namespace std;

void MenuClass::menu()
{
	StudentClass student1;

	bool validInpyt = false;
	while (validInpyt == false) {
		int iIn;
		printf("STUDENT DATA BASE\n");
		printf("1) ACCESS DATABASE\n");
		printf("2) CHANGE DATABAES\n");
		printf("0) EXIT\n");
		cin >> iIn;
		//then cervert it into ASCII
		if (iIn == 0) //0
		{
			system("exit");
			validInpyt = true;
		}
		else if (iIn == 1) //1
		{
			printf("Student 1: %s %s %s \n", student1.getFirstName().c_str(), student1.getLastName().c_str(), student1.getReadableDOB().c_str());
			validInpyt = true;
		}
		else if (iIn == 2) //2
		{
			validInpyt = true;
			printf("CHANING DATABASE\n");
			printf("1) Change First Name\n");
			printf("2) Change Last Name\n");
			printf("3) Change Birth of date\n");
			printf("0) EXIT\n");
			int iInput;
			cin >> iInput;
			if (iInput == 1) {
				printf("Entre new First Name\n");
				string FirstNameIn;
				cin >> FirstNameIn;
				student1.setFirstName(FirstNameIn);
			}
			if (iInput == 2) {
				printf("Entre new Last Name\n");
				string LastnameIn;
				cin >> LastnameIn;
				student1.setLastName(LastnameIn);
			}
			if (iInput == 3) {
				printf("Entre new Date of birth\n");
				int BirthOfDateIn;
				cin >> BirthOfDateIn;
				student1.setBirthOfdate(BirthOfDateIn);
			}
		}
		else {
			printf("invalid input \n");
			system("pause");
		}
	}
}