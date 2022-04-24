#include "..\..\..\include\GameEngine\Audio\click.h"

bool Click::LoadAudio()
{
	if (!buffer.loadFromFile("..\..\\..\\assets\\audio\\click.wav")) return false;
	sound.setBuffer(buffer);
	sound.setLoop(false);
	return true;
}

void Click::playAudio()
{
	sound.play();
}

void Click::UpdateAudio(float i)
{

}
