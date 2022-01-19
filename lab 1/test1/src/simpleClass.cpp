#include "simpleClass.h"

SimpleClass::SimpleClass() {
	iMyPrivateInteger = 0;
}

SimpleClass::SimpleClass(int iValue) {
	iMyPrivateInteger = iValue;
}

void SimpleClass::setInteger(int iNewValue) {
	iMyPrivateInteger = iNewValue;
}

int SimpleClass::getInterger() {
	return iMyPrivateInteger;
}