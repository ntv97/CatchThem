#ifndef BREAD_HPP
#define BREAD_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Item.hpp"

class Bread : public Item {
public:
        Bread(sf::RenderWindow& w, sf::Texture texture);
        virtual void Update();
        virtual int GetScore();
private:
};


#endif  /* BREAD_HPP */
