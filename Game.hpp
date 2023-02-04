#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "StateStack.hpp"

class Game {
public:
	Game();
	void run();

private:
	void ProcessInput();
	void Update(sf::Time& dt);
	void Render();
	void RegisterStates();
private:
	static const sf::Time	TimePerFrame;
	sf::RenderWindow	Window;
	StateStack		Stack;
};


#endif  /* GAME_HPP */
