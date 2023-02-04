#include "Game.hpp"
#include "State.hpp"
#include "HomeState.hpp"
#include "GameOverState.hpp"
#include "StateStack.hpp"
#include "StateId.hpp"
#include "WinState.hpp"
#include "GameState.hpp"


const sf::Time Game::TimePerFrame = sf::seconds(1.f/60.f);

Game::Game() : Window(sf::VideoMode(1600, 900), "Catch Them!", sf::Style::Close), Stack(Window) {
	RegisterStates();
	Stack.PushState(States::Home);
}

void Game::run() {
	sf::Clock clock;
	sf::Time TimeSinceLastUpdate = sf::Time::Zero;

	while (Window.isOpen())
	{
		sf::Time dt = clock.restart();
		TimeSinceLastUpdate += dt;
		while (TimeSinceLastUpdate > TimePerFrame)
		{
			TimeSinceLastUpdate -= TimePerFrame;

			ProcessInput();
			Update(dt);

			if (Stack.IsEmpty())
				Window.close();
		}

		Render();
	}
}

void Game::ProcessInput() {
	sf::Event event;
	while (Window.pollEvent(event))
	{
		Stack.HandleEvent(event);

		if (event.type == sf::Event::Closed)
			Window.close();
	}
}

void Game::Update(sf::Time& dt) {
	Window.clear();
	Stack.Update(dt);
}

void Game::Render() {
	Window.clear();
	Stack.Draw();
	Window.setView(Window.getDefaultView());
	Window.display();
}

void Game::RegisterStates() {
	Stack.RegisterState<HomeState>(States::Home);
	Stack.RegisterState<GameState>(States::Game);
        Stack.RegisterState<GameOverState>(States::Loser);
        Stack.RegisterState<WinState>(States::Winner);
}
