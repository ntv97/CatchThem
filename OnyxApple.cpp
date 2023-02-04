#include "OnyxApple.hpp"


OnyxApple::OnyxApple(sf::RenderWindow& w, sf::Texture texture) : Item(w, texture) {}
void OnyxApple::Update() {
	auto pos = sprite.getPosition();
	sprite.setPosition(pos.x, pos.y+9.f);

}
int OnyxApple::GetScore() { return 100; }
