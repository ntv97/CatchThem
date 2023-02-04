#include <iostream>
#include "GameOverState.hpp"

GameOverState::GameOverState(StateStack* stack, sf::RenderWindow &window) : State(stack, window) {
	LoadText();
	LoadBackground();
}

void GameOverState::LoadText() {
	MessageFont.loadFromFile("Fonts/Sketch 3D.otf");
        SelectFont.loadFromFile("Fonts/Sunrise International Demo.otf");
        MessageText.setFont(MessageFont);
        HomeText.setFont(SelectFont);
        ExitText.setFont(SelectFont);

	auto size = Window.getSize();
        MessageText.setPosition(size.x/2.f-230, 150.f);
        HomeText.setPosition(size.x/2.f-30, 300.f);
        ExitText.setPosition(size.x/2.f-30, 360.f);
        MessageText.setCharacterSize(90u);
        HomeText.setCharacterSize(40u);
        ExitText.setCharacterSize(40u);
        MessageText.setString("Game Over!");
        HomeText.setString("Home Page");
        ExitText.setString("Exit");

	HomeSelected = true;
	HomeText.setColor(sf::Color::Black);
	MessageText.setColor(sf::Color(255,255,204));
}

void GameOverState::LoadBackground() {
	BackgroundTexture.loadFromFile("Backgrounds/Kerning City.jpeg");
	BackgroundSprite.setTexture(BackgroundTexture);
	if (!Music.openFromFile("Music/JungleBook-KerningSwamp.ogg"))
        {
                cout << " Error Opening Msuic File " << endl;
		// exit
        }
	Music.setVolume(80);
	Music.play();
}

void GameOverState::Draw() {
	Window.draw(BackgroundSprite);
	Window.draw(HomeText);
	Window.draw(MessageText);
	Window.draw(ExitText);
}

bool GameOverState::Update(sf::Time& dt) {
	if (!HomeSelected) {
		HomeText.setColor(sf::Color::White);
		ExitText.setColor(sf::Color::Black);
	} else {
		ExitText.setColor(sf::Color::White);
                HomeText.setColor(sf::Color::Black);
	}

}

bool GameOverState::HandleEvent(const sf::Event& event) {
	if (event.type == sf::Event::KeyPressed) {
		if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::Down) {
			HomeSelected = !HomeSelected;
		} else if (event.key.code == sf::Keyboard::Return) {
			if (HomeSelected) {
				cout << "Home ";
				RequestStackPop();
                                RequestStackPush(States::Home);
			} else {
				cout << "Exit ";
				Window.close();
			}
			cout << "Selected" << endl;
		}
	}
}
