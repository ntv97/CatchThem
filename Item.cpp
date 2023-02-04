#include "Item.hpp"

Item::Item(sf::RenderWindow& w, sf::Texture texture) : window(w) {
	this->texture = texture;
	sprite.setTexture(this->texture);
	IsGone = false;
	srand(time(0));
}

void Item::Update() {
	auto size = window.getSize();	
	auto pos = sprite.getPosition();
	if (pos.y >= size.y) IsGone = true;
}

void Item::SetXPosition(float xPos) {
	sprite.setPosition(xPos, 10.f);
}

void Item::Draw() {
	window.draw(sprite);
}

sf::Sprite Item::GetSprite() {
	return sprite;
}

