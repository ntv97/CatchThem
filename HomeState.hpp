#ifndef HOME_STATE_HPP
#define HOME_STATE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "State.hpp"

class HomeState : public State {
public:
	HomeState(StateStack* stack, sf::RenderWindow &window);
	virtual void LoadText();
        virtual void LoadBackground();
	virtual void Draw();
        virtual bool Update(sf::Time& dt);
        virtual bool HandleEvent(const sf::Event& event);
private:
	sf::Font TitleFont, SelectFont;
	sf::Text TitleText, PlayText, ExitText;
	bool PlaySelected;
};

#endif
