#include "Boom.hpp"

Boom::Boom(sf::RenderWindow& w, sf::Texture texture) : Item(w, texture) {}
void Boom::Update() {
        auto pos = sprite.getPosition();
        sprite.setPosition(pos.x, pos.y+3.f);

}

int Boom::GetScore() { return -100; }
