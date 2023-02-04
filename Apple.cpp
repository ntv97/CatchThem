#include "Apple.hpp"

Apple::Apple(sf::RenderWindow& w, sf::Texture texture) : Item(w, texture) {}
void Apple::Update() {
	auto pos = sprite.getPosition();
	sprite.setPosition(pos.x, pos.y+3.f);

}
int Apple::GetScore() { return 10; }

