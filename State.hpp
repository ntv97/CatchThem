#ifndef STATE_HPP
#define STATE_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "StateId.hpp"

using namespace std;

class StateStack;

class State {
public:
	typedef std::unique_ptr<State> StatePtr;
	State(StateStack* stack, sf::RenderWindow &window);
	virtual void LoadText() = 0;
        virtual void LoadBackground() = 0;
	virtual void Draw() = 0;
	virtual bool Update(sf::Time& dt) = 0;
	virtual bool HandleEvent(const sf::Event& event) = 0;
	~State();
protected:
	void	RequestStackPush(States::Id id);
	void	RequestStackPop();
	void	RequestStateClear();
	sf::RenderWindow &Window;
	sf::Sprite	BackgroundSprite;
	sf::Texture	BackgroundTexture;
	sf::Music	Music;

private:
	StateStack*	Stack;
};

#endif  /* STATE_HPP */
