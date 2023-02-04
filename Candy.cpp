#include "Candy.hpp"

Candy::Candy(sf::RenderWindow& w, sf::Texture texture) : Item(w, texture) {}
void Candy::Update() {
	auto pos = sprite.getPosition();
	sprite.setPosition(pos.x, pos.y+3.f);

}
int Candy::GetScore() { return 30; }
