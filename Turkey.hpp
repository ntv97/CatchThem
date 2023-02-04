#ifndef TURKEY_HPP
#define TURKEY_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Item.hpp"

class Turkey : public Item {
public:
        Turkey(sf::RenderWindow& w, sf::Texture texture);
        virtual void Update();
        virtual int GetScore();
private:
};


#endif  /* TURKEY_HPP */
