#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "State.hpp"
#include <map>

// Items
#include "Item.hpp"
#include "Corn.hpp"
#include "Apple.hpp"
#include "OnyxApple.hpp"
#include "Orange.hpp"
#include "Bread.hpp"
#include "Candy.hpp"
#include "Turkey.hpp"
#include "Boom.hpp"

class GameState : public State {
public:
	GameState(StateStack* stack, sf::RenderWindow &window);
	template <typename T>
	void RegisterItem(int id, sf::RenderWindow& w, sf::Texture texture)
	{
		ItemFactory[id] = [&w, texture] ()
		{
			return Item::Ptr(new T(w, texture));
		};
	}
	Item::Ptr CreateItem(Item::Type id) {
		auto ptr = ItemFactory.find(id);
		if (ptr == ItemFactory.end()) return NULL;
		return std::move(ptr->second());
	}
	void RegisteringItems();
	void CreateRandomItems();
	virtual void LoadText();
        virtual void LoadBackground();
	virtual void Draw();
        virtual bool Update(sf::Time& dt);
        virtual bool HandleEvent(const sf::Event& event);
private:
	sf::Font Font;
	sf::Text Score;
	sf::Texture BasketTexture;
	sf::Sprite BasketSprite;
	static const sf::Time   TimePerFrame;
	int score;
	std::map<int, std::function<Item::Ptr()>> ItemFactory;
	vector<std::unique_ptr<Item>> ItemVec;
};

#endif /* GAME_STATE_HPP */
