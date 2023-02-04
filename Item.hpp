#ifndef ITEM_HPP
#define ITEM_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace std;

class Item {
public:
        typedef std::unique_ptr<Item> Ptr;
        enum Type {
                Corn,
                Apple,
                OnyxApple,
                Orange,
                Bread,
                Candy,
                Turkey,
		Boom,
                Length,
        };
        Item(sf::RenderWindow& w, sf::Texture texture);
	bool GetIsGone() { return IsGone; }
	void SetIsGone(bool val) { IsGone = val; }
        virtual void Update();
        void SetXPosition(float xPos);
        sf::FloatRect GetGlobalBounds() { return sprite.getGlobalBounds(); }
        virtual int GetScore() = 0;
        void Draw();
        sf::Sprite GetSprite();

private:
        sf::RenderWindow &window;
protected:
	bool IsGone;
        sf::Sprite sprite;
        sf::Texture texture;
};

#endif  /* ITEM_HPP */
