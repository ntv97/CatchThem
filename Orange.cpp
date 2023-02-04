#include "Orange.hpp"

Orange::Orange(sf::RenderWindow& w, sf::Texture texture) : Item(w, texture) {}
void Orange::Update() {
	auto pos = sprite.getPosition();
	sprite.setPosition(pos.x, pos.y+2.f);

}
int Orange::GetScore() { return 5; }

