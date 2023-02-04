#include <iostream>
#include "WinState.hpp"

WinState::WinState(StateStack* stack, sf::RenderWindow &window) : State(stack, window) {
	LoadText();
	LoadBackground();
}

void WinState::LoadText() {
	MessageFont.loadFromFile("Fonts/Sketch 3D.otf");
        SelectFont.loadFromFile("Fonts/Sunrise International Demo.otf");
        MessageText.setFont(MessageFont);
        HomeText.setFont(SelectFont);
        ExitText.setFont(SelectFont);

	auto size = Window.getSize();
        MessageText.setPosition(270.f, 150.f);
        HomeText.setPosition(size.x/2.f-30, 300.f);
        ExitText.setPosition(size.x/2.f-30, 360.f);
        MessageText.setCharacterSize(90u);
        HomeText.setCharacterSize(40u);
        ExitText.setCharacterSize(40u);
        MessageText.setString("Congratulations Winner!!");
        HomeText.setString("Home Page");
        ExitText.setString("Exit");

	HomeSelected = true;
	HomeText.setColor(sf::Color(255,220,231));
	MessageText.setColor(sf::Color(255,255,204));
}

void WinState::LoadBackground() {
	BackgroundTexture.loadFromFile("Backgrounds/Cherry Blossom.jpeg");
	BackgroundSprite.setTexture(BackgroundTexture);
	if (!Music.openFromFile("Music/WhenTheMorningComes-Ellinia.ogg"))
        {
                cout << " Error Opening Msuic File " << endl;
		// exit
        }
	Music.setVolume(80);
	Music.play();
}

void WinState::Draw() {
	Window.draw(BackgroundSprite);
	Window.draw(HomeText);
	Window.draw(MessageText);
	Window.draw(ExitText);
}

bool WinState::Update(sf::Time& dt) {
	if (!HomeSelected) {
		HomeText.setColor(sf::Color::White);
		ExitText.setColor(sf::Color(255,220,231));
	} else {
		ExitText.setColor(sf::Color::White);
                HomeText.setColor(sf::Color(255,220,231));
	}

}

bool WinState::HandleEvent(const sf::Event& event) {
	if (event.type == sf::Event::KeyPressed) {
		if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::Down) {
			HomeSelected = !HomeSelected;
		} else if (event.key.code == sf::Keyboard::Return) {
			if (HomeSelected) {
				RequestStackPop();
                                RequestStackPush(States::Home);
				cout << "Home ";
			} else {
				cout << "Exit ";
				Window.close();
			}
			cout << "Selected" << endl;
		}
	}
}
