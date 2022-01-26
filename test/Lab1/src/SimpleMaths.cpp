#include "SimpleMaths.h"

int SimpleMaths::Add(int iValue1, int iValue2) {
	int iResult = iValue1 + iValue2;
	return iResult;
}

int SimpleMaths::Takeaway(int iValue1, int iValue2) {
	int iResult = iValue1 - iValue2;
	return iResult;
}

int SimpleMaths::Multi(int iValue1, int iValue2) {
	int iResult=0;
	if (iValue1 < 0) {
		iValue1 = iValue1 * -1;
	}
	if (iValue2 < 0) {
		iValue1 = iValue1 * -1;
	}
	for (int x = 0; x < iValue2; x++) {
		iResult = iResult+iValue1;
	}
	return iResult;
}

float SimpleMaths::Divide(int iValue1, int iValue2) {
	float fValue1 = float(iValue1);
	float fValue2 = float(iValue2);
	if (fValue1 < 0) {
		fValue1 = fValue1 * -1;
	}
	if (fValue2 < 0) {
		fValue2 = fValue2 * -1;
	}
	float iResult = float(fValue1 / fValue2);
	return iResult;
}