#pragma once
#include<string>
#include<vector>

using std::string;
using std::vector;

class Student {
private:
	string sLastName;
	string sFirstName;
	int iBirthDate;
	int iPnum;
	bool bCrimRec;
	vector<string> vsModules;

public:
	Student(); // Default constructor
	Student(string sLastNameIn, string sFirstNameIn, int iBirthDateIn); //Overriden constructor.
	
	void setLastName(string sLastIn);
	void setFirstName(string sFirstIn);

	string getLastName();
	string getFirstName();

	void setBirthDate(int iBirthDateIn);
	void setCrimRec(bool bCrimRecIn);

	void inputModule(string sModulesIn);

	vector<string> getModules();
};
