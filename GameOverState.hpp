#ifndef GAMEOVER_STATE_HPP
#define GAMEOVER_STATE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "State.hpp"

class GameOverState : public State {
public:
	GameOverState(StateStack* stack, sf::RenderWindow &window);
	virtual void LoadText();
        virtual void LoadBackground();
	virtual void Draw();
        virtual bool Update(sf::Time& dt);
        virtual bool HandleEvent(const sf::Event& event);
private:
	sf::Font MessageFont, SelectFont;
	sf::Text MessageText, HomeText, ExitText;
	bool HomeSelected;
};

#endif
