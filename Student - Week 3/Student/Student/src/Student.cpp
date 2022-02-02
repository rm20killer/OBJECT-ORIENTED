#include"Student.h" //If this is not recognised, you need to make the path relative to the directory that you are using by moving the link one directory up.
#include<iostream>


Student::Student() {}; //Default constructor.
Student::Student(string sLastNameIn, string sFirstNameIn, int iBirthDateIn) {
	sLastName = sLastNameIn;
	sFirstName = sFirstNameIn;
	iBirthDate = iBirthDateIn;
}

string Student::getFirstName() {
	return sFirstName;
};

string Student::getLastName() {
	return sLastName;
};

void Student::setLastName(string sLastIn) {
	sLastName = sLastIn;
};
void Student::setFirstName(string sFirstIn) {
	sFirstName = sFirstIn;
};

void Student::setBirthDate(int iBirthDateIn) {
	int iNumDigits = std::to_string(iBirthDateIn).length(); //More efficient ways of finding length of int input, but this is for readable code.
	
	if (iNumDigits == 5) {
		iBirthDate = iBirthDateIn;
	}
	else {
		std::cout << "Error in the input!" << std::endl;
	}
};
void Student::setCrimRec(bool bCrimRecIn) {
	bCrimRec = bCrimRecIn;
};

void Student::inputModule(string sModuleIn) {
	vsModules.push_back(sModuleIn);
};

vector<string> Student::getModules() {
	return vsModules;
};

