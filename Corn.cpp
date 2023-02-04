#include "Corn.hpp"

Corn::Corn(sf::RenderWindow& w, sf::Texture texture) : Item(w, texture) {}
void Corn::Update() {
	auto pos = sprite.getPosition();
	sprite.setPosition(pos.x, pos.y+5.f);

}
int Corn::GetScore() { return 50; }
