#include "../include/Audio.h"

bool audio::LoadAudio()
{
	if (!blopBuffer.loadFromFile(".\\assets\\audio\\beep.flac")) return 0;
	blopSound.setBuffer(blopBuffer);
	blopSound.setLoop(true);
}

void audio::playAudio()
{
	blopSound.play();
}

void audio::UpdateAudio(float i)
{
	blopSound.setPitch(1.0f + (i*0.01));
}
