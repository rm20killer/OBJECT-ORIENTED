#include "..\..\..\include\GameEngine\Audio\Death.h"

bool Death::LoadAudio()
{
	if (!buffer.loadFromFile("..\..\\..\\assets\\audio\\death.wav")) return false;
	sound.setBuffer(buffer);
	sound.setLoop(false);
	return true;
}

void Death::playAudio()
{
	sound.play();
}

void Death::UpdateAudio(float i)
{

}
