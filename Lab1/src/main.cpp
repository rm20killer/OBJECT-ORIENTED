#include <iostream>


#include "simpleClass.h"
#include "simpleMaths.h"

using namespace std;

int main()
{
	SimpleClass simple1;
	SimpleClass simple2;
	SimpleMaths maths;
	simple1.setInteger(10);
	simple2.setInteger(-50);

	printf("%i, %i \n", simple1.getInterger(), simple2.getInterger());
	system("pause");
	printf("%i + %i = %i \n", simple1.getInterger(), simple2.getInterger(),maths.Add(simple1.getInterger(), simple2.getInterger()));
	printf("%i - %i = %i \n", simple1.getInterger(), simple2.getInterger(), maths.Takeaway(simple1.getInterger(), simple2.getInterger()));
	printf("%i * %i = %i \n", simple1.getInterger(), simple2.getInterger(), maths.Multi(simple1.getInterger(), simple2.getInterger()));
	printf("%i / %i = %f \n", simple1.getInterger(), simple2.getInterger(), maths.Divide(simple1.getInterger(), simple2.getInterger()));
}