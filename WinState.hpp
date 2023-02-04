#ifndef WIN_STATE_HPP
#define WIN_STATE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "State.hpp"

class WinState : public State {
public:
	WinState(StateStack* stack, sf::RenderWindow &window);
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
