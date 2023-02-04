#ifndef CORN_HPP
#define CORN_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Item.hpp"

class Corn : public Item {
public:
        Corn(sf::RenderWindow& w, sf::Texture texture);
        virtual void Update();
        virtual int GetScore();
private:
};

#endif  /* CORN_HPP */
