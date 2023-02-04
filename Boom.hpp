#ifndef BOOM_HPP
#define BOOM_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Item.hpp"

class Boom : public Item {
public:
        Boom(sf::RenderWindow& w, sf::Texture texture);
        virtual void Update();
        virtual int GetScore();
private:
};


#endif  /* BOOM_HPP */
