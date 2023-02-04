#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "State.hpp"
#include "HomeState.hpp"
#include "GameOverState.hpp"
#include "StateStack.hpp"
#include "StateId.hpp"
#include "WinState.hpp"
#include "GameState.hpp"
#include "Item.hpp"

using namespace std;

int main() {
	sf::RenderWindow window(sf::VideoMode(1600, 900), "Catch Them Game");
	StateStack stack(window);
	/*HomeState home(stack, window);
	home.Draw();*/
	stack.RegisterState<HomeState>(States::Home);
	stack.RegisterState<GameOverState>(States::Loser);
	stack.RegisterState<WinState>(States::Winner);
	stack.RegisterState<GameState>(States::Game);
	//GameOverState gameover(&stack, window);
	//gameover.Draw();
	//window.display();
	//auto over = stack.CreateState(States::Loser);
	//auto home = stack.CreateState(States::Home);
	stack.PushState(States::Home);
	//stack.PushState(States::Game);
	//stack.PushState(States::Loser);
	cout << "stack ismepty: " << stack.IsEmpty() << endl;
	while(1) {
		sf::Event event;
		while (window.pollEvent(event))
                {
                        /*if (event.type == sf::Event::KeyPressed) {
                                auto basketPosition = sprite3.getPosition();
                                if (event.key.code == sf::Keyboard::Left) {
                                        sprite3.setPosition(basketPosition.x-1.f, 0.f);
                                }
                        }*/
                        if (event.type == sf::Event::Closed)
                                window.close();
			
			stack.HandleEvent(event);
			stack.Update();
			window.clear();
			stack.Draw();
                }
		window.display();
	}
	return 0;
}
