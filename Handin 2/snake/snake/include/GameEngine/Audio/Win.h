#pragma once
#include <SFML/Audio.hpp>
#include <iostream>
class Win {
public:
	bool LoadAudio();
	void playAudio();
	void UpdateAudio(float i);
private:
	sf::SoundBuffer buffer;
	sf::Sound sound;
};