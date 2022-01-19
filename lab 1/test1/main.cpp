#include <iostream>


#include "simpleClass.h"

using namespace std;

int main()
{
	SimpleClass simple1;
	SimpleClass simple2;

	simple1.setInteger(10);
	simple2.setInteger(-50)

	printf("%i, %i", simple1.getInterger(), simple2.getInterger());
	system("pause")
}