#ifndef ONYX_APPLE_HPP
#define ONYX_APPLE_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Item.hpp"

class OnyxApple : public Item {
public:
        OnyxApple(sf::RenderWindow& w, sf::Texture texture);
        virtual void Update();
        virtual int GetScore();
private:
};


#endif  /* ONYX_APPLE_HPP */
