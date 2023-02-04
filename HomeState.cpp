#include <iostream>
#include "StateId.hpp"
#include "HomeState.hpp"

HomeState::HomeState(StateStack* stack, sf::RenderWindow &window) : State(stack, window) {
	LoadText();
	LoadBackground();
}

void HomeState::LoadText() {
	TitleFont.loadFromFile("Fonts/Sketch 3D.otf");
        SelectFont.loadFromFile("Fonts/Sunrise International Demo.otf");
        TitleText.setFont(TitleFont);
        PlayText.setFont(SelectFont);
        ExitText.setFont(SelectFont);
        TitleText.setPosition(800.f, 150.f);
        PlayText.setPosition(990.f, 300.f);
        ExitText.setPosition(990.f, 360.f);
        TitleText.setCharacterSize(80u);
        PlayText.setCharacterSize(40u);
        ExitText.setCharacterSize(40u);
        TitleText.setString("Catch Them!");
        PlayText.setString("Play");
        ExitText.setString("Exit");

	PlaySelected = true;
	PlayText.setColor(sf::Color(255,204,204));
}

void HomeState::LoadBackground() {
	BackgroundTexture.loadFromFile("Backgrounds/Maple Island (current version).jpeg");
	BackgroundSprite.setTexture(BackgroundTexture);
	if (!Music.openFromFile("Music/Log-In.ogg"))
        {
                cout << " Error Opening Msuic File " << endl;
		// exit
        }
	Music.setVolume(80);
	Music.play();
}

void HomeState::Draw() {
	Window.draw(BackgroundSprite);
	Window.draw(PlayText);
	Window.draw(TitleText);
	Window.draw(ExitText);
}

bool HomeState::Update(sf::Time& dt) {
	if (!PlaySelected) {
		PlayText.setColor(sf::Color::White);
		ExitText.setColor(sf::Color(255,204,204));
	} else {
		ExitText.setColor(sf::Color::White);
                PlayText.setColor(sf::Color(255,204,204));
	}

}

bool HomeState::HandleEvent(const sf::Event& event) {
	if (event.type == sf::Event::KeyPressed) {
		if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::Down) {
			PlaySelected = !PlaySelected;
		} else if (event.key.code == sf::Keyboard::Return) {
			if (PlaySelected) {
				RequestStackPop();
				RequestStackPush(States::Game);
				cout << "Play ";
			} else {
				cout << "Exit ";
				Window.close();
			}
			cout << "Selected" << endl;
		}
	}
}
