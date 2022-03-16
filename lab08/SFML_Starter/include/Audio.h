#pragma once
#include <SFML/Audio.hpp>
#include <iostream>
class audio {
public:
	bool LoadAudio();
	void playAudio();
	void UpdateAudio(float i);
private:
	sf::SoundBuffer blopBuffer;
	sf::Sound blopSound;
};