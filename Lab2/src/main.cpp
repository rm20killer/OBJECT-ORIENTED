#include "student.h"
#include "menu.h"
#include <iostream>
#include <string>


using namespace std;

int main()
{

	MenuClass menu1;
	StudentClass student1;
	student1.Student("test", "last", 260103);
	while (1 != 0){
		menu1.menu();
	}
	//menu1.menu();

	//StudentClass student1;
	//
	//student1.Student("test", "last", 260103);
	//printf("%s %s", student1.getFirstName().c_str(), student1.getLastName().c_str());
	////cout << student1.getFirstName();
	////cout << " ";
	////cout << student1.getLastName();
	//
	//student1.setFirstName("Test2");
	//cout << "\n";
	//cout << student1.getFirstName();
	//cout << " ";
	//cout << student1.getLastName();
	//cout << "\n";
	//cout << student1.getDateOfBirth();
	//cout << "\n";
	//student1.setBirthOfdate(5555555);
	//cout << student1.getReadableDOB().c_str();
	//cout << "\n";
	//system("pause");
}	