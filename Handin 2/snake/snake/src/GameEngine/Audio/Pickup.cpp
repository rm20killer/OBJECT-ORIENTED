#include "..\..\..\include\GameEngine\Audio\Pickup.h"

bool Pickup::LoadAudio()
{
	if (!buffer.loadFromFile("..\..\\..\\assets\\audio\\pickup.wav")) return false;
	sound.setBuffer(buffer);
	sound.setLoop(false);
	return true;
}

void Pickup::playAudio()
{
	sound.play();
}

void Pickup::UpdateAudio(float i)
{

}
