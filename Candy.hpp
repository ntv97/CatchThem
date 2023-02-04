#ifndef CANDY_HPP
#define CANDY_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Item.hpp"

class Candy : public Item {
public:
        Candy(sf::RenderWindow& w, sf::Texture texture);
        virtual void Update();
        virtual int GetScore();
private:
};


#endif  /* CANDY_HPP */
