#include "..\..\..\include\GameEngine\Audio\Hit.h"

bool Hit::LoadAudio()
{
	if (!buffer.loadFromFile("..\..\\..\\assets\\audio\\Hit.wav")) return false;
	sound.setBuffer(buffer);
	sound.setLoop(false);
	return true;
}

void Hit::playAudio()
{
	sound.play();
}

void Hit::UpdateAudio(float i)
{

}
