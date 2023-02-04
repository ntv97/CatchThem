#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace std;

sf::Music music;

int main() {
	// Open it from an audio file
	if (!music.openFromFile("Music/FloralLife.ogg"))
	{
		cout << " Error " << endl;
		return -1;
	    // error...
	}
	//
	// Change some parameters
	//music.setPosition(0, 1, 10); // change its 3D position
	//music.setPitch(2);           // increase the pitch
	music.setVolume(100);         // reduce the volume
	music.setLoop(true);         // make it loop
	// Play it
	music.play();
	while (true) {}

	return 0;
}
