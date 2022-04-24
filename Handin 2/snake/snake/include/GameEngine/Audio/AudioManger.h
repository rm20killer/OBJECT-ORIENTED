#pragma once
#include <SFML/Audio.hpp>
#include <iostream>
class audioSanke {
public:
	bool LoadAllAudio();
	void playAudio(int SoundNum);
private:
	sf::SoundBuffer buffer;
	sf::Sound seound;
};