#include "..\..\..\include\GameEngine\Audio\Win.h"

bool Win::LoadAudio()
{
	if (!buffer.loadFromFile("..\..\\..\\assets\\audio\\Win.wav")) return false;
	sound.setBuffer(buffer);
	sound.setLoop(false);
	return true;
}

void Win::playAudio()
{
	sound.play();
}

void Win::UpdateAudio(float i)
{

}
