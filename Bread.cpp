#include "Bread.hpp"

Bread::Bread(sf::RenderWindow& w, sf::Texture texture) : Item(w, texture) {}
void Bread::Update() {
	auto pos = sprite.getPosition();
	sprite.setPosition(pos.x, pos.y+3.f);

}
int Bread::GetScore() { return 40; }
