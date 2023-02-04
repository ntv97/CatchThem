#ifndef APPLE_HPP
#define APPLE_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Item.hpp"

class Apple : public Item {
public:
        Apple(sf::RenderWindow& w, sf::Texture texture);
        virtual void Update();
        virtual int GetScore();
private:
};

#endif  /* APPLE_HPP */
