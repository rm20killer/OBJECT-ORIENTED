#include <Pets/Cats/Sphynx.h>

int Sphynx::GetMaxJump()
{
    return iJumpHeight;
}

string Sphynx::GetRandomResponse()
{
    int iRandomNumber = (rand() % iNumOfResponse);
    string ReturnResponse = asResponse[iRandomNumber];
    return ReturnResponse;
}
