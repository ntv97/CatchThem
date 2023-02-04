#include "Turkey.hpp"

Turkey::Turkey(sf::RenderWindow& w, sf::Texture texture) : Item(w, texture) {}
void Turkey::Update() {
	auto pos = sprite.getPosition();
	sprite.setPosition(pos.x, pos.y+5.f);

}
int Turkey::GetScore() { return 50; }

