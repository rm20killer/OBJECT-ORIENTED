#pragma once

class SimpleClass
{
	//Private
private:
	int iMyPrivateInteger;
	//public
public:

	SimpleClass();

	SimpleClass(int iValue);

	void setInteger(int inewValue);

	int getInterger();
};