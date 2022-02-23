#include <Pets/Cats/Bengal.h>

int Bengal::GetMaxJump()
{
    return iJumpHeight;
}

string Bengal::GetRandomResponse()
{
    int iRandomNumber = (rand() % iNumOfResponse);
    string ReturnResponse = asResponse[iRandomNumber];
    return ReturnResponse;
}
