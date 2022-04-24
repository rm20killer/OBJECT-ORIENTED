#pragma once
#include <SFML/Audio.hpp>
#include <iostream>
class Hit {
public:
	bool LoadAudio();
	void playAudio();
	void UpdateAudio(float i);
private:
	sf::SoundBuffer buffer;
	sf::Sound sound;
};