#include <Pets/Cats/Bengal.h>

/// <GetMaxJump function>
/// </summary>
///	return value
/// <returns><int value of iJumpHeight>
int Bengal::GetMaxJump()
{
    return iJumpHeight;
}
/// <GetRandomResponse function>
/// </summary>
/// Gets a random number with the amount the max being the number of values in the array
/// using the number grab the value
/// <returns><string value>
string Bengal::GetRandomResponse()
{
    int iRandomNumber = (rand() % iNumOfResponse);
    string ReturnResponse = asResponse[iRandomNumber];
    return ReturnResponse;
}
/*
void Bengal::jump(int iJump)
{
	if (iJumpHeight >= iJump)
	{
		printf("has jumped %im\n", iJump);
	}
	else
	{
		printf("could not jump that high\n");
	}
}
void Bengal::jump()
{
	int iComputerChoice = (rand() % iJumpHeight - 1) + 1;
	printf("has jumped %im, ", iComputerChoice);
}
*/