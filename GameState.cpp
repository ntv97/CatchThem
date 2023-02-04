#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <bits/stdc++.h>
#include "Random.hpp"
#include "GameState.hpp"

const sf::Time GameState::TimePerFrame = sf::seconds(1.f);
sf::Time Timer = sf::Time::Zero;

GameState::GameState(StateStack* stack, sf::RenderWindow &window) : State(stack, window) {
	LoadText();
	LoadBackground();
	RegisteringItems();
	score = 0;
	CreateRandomItems();
}

void GameState::LoadText() {
	auto size = Window.getSize();
	Font.loadFromFile("Fonts/F25_Executive.otf");
	Score.setCharacterSize(30u);
        Score.setFont(Font);
        Score.setPosition(50.f, 30.f);

}

void GameState::LoadBackground() {
	BackgroundTexture.loadFromFile("Backgrounds/Light Sea.jpeg");
	BackgroundSprite.setTexture(BackgroundTexture);
	BasketTexture.loadFromFile("Items/ChocolateBasket.png");
	BasketSprite.setTexture(BasketTexture);

	auto windowSize = Window.getSize();
        BasketSprite.setPosition(windowSize.x/2.f,windowSize.y-150);

	if (!Music.openFromFile("Music/FloralLife.ogg"))
        {
                cout << " Error Opening Msuic File " << endl;
		// exit
        }
	Music.setVolume(80);
	Music.play();
}

void GameState::RegisteringItems() {
	sf::Texture cornTextPtr;
        sf::Texture appleTextPtr;
        sf::Texture candyTextPtr;
        sf::Texture turkeyTextPtr;
        sf::Texture onyxTextPtr;
        sf::Texture breadTextPtr;
        sf::Texture orangeTextPtr;
	sf::Texture boomTextPtr;
        cornTextPtr.loadFromFile("Items/Corn.png");
        appleTextPtr.loadFromFile("Items/Apple.png");
        candyTextPtr.loadFromFile("Items/Fruit Candy.png");
        turkeyTextPtr.loadFromFile("Items/Roasted Turkey.png");
        onyxTextPtr.loadFromFile("Items/Onyx Apple.png");
        breadTextPtr.loadFromFile("Items/Delicious Bread.png");
        orangeTextPtr.loadFromFile("Items/Orange.png");
	boomTextPtr.loadFromFile("Items/Boom.png");

	RegisterItem<Apple>(Item::Apple, Window, appleTextPtr);
        RegisterItem<Corn>(Item::Corn, Window, cornTextPtr);
        RegisterItem<OnyxApple>(Item::OnyxApple, Window, onyxTextPtr);
        RegisterItem<Orange>(Item::Orange, Window, orangeTextPtr);
        RegisterItem<Bread>(Item::Bread, Window, breadTextPtr);
        RegisterItem<Candy>(Item::Candy, Window, candyTextPtr);
        RegisterItem<Turkey>(Item::Turkey, Window, turkeyTextPtr);
	RegisterItem<Boom>(Item::Boom, Window, boomTextPtr);
}

void GameState::Draw() {
	Window.draw(BackgroundSprite);
	Window.draw(BasketSprite);
	for (auto& item: ItemVec)
                item->Draw();

	Window.draw(Score);
}

void GameState::CreateRandomItems() {
	srand(time(0));
	int id = randomInt(0, Item::Length);
	int pos = randomFloat(0, 1550);
	auto item = CreateItem(static_cast<Item::Type>(id));
	item->SetXPosition(pos);
	ItemVec.push_back(std::move(item));

}

bool GameState::Update(sf::Time& dt) {
	Timer += dt;
	if (Timer >= TimePerFrame) {
		CreateRandomItems();
		Timer = sf::Time::Zero;
	}

	auto basketPos = BasketSprite.getGlobalBounds();
	for (auto& item: ItemVec) {
		item->Update();
		auto itemPos = item->GetGlobalBounds();
		if (itemPos.intersects(basketPos)) {
			score += item->GetScore();
			item->SetIsGone(true);
		}
	}

	ItemVec.erase(std::remove_if(ItemVec.begin(), ItemVec.end(), [](std::unique_ptr<Item>& item) {return item->GetIsGone() == true;}), ItemVec.end());

	Score.setString("score: "+to_string(score));

	if (score >= 800) {
		RequestStackPop();
		RequestStackPush(States::Winner);
	} else if (score < 0) {
		RequestStackPop();
                RequestStackPush(States::Loser);
	}
}

bool GameState::HandleEvent(const sf::Event& event) {
	if (event.type == sf::Event::KeyPressed) {
		auto basketPosition = BasketSprite.getPosition();
		if (event.key.code == sf::Keyboard::Left) {
			BasketSprite.setPosition(basketPosition.x-7.f, basketPosition.y);
		} else if (event.key.code == sf::Keyboard::Right) {
			BasketSprite.setPosition(basketPosition.x+7.f, basketPosition.y);
		}
	}
}
