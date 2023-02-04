#ifndef ORANGE_HPP
#define ORANGE_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Item.hpp"

class Orange : public Item {
public:
        Orange(sf::RenderWindow& w, sf::Texture texture);
        virtual void Update();
        virtual int GetScore();
private:
};

#endif  /* ORANGE_HPP */
