#include "Player.h"

void Player::setPosition(int px, int py) {
	x = px; y = py;
}

void Player::move(int dx, int dy) {
	x += dx;
	y += dy;
}

void Player::draw(Renderer& r) {
	r.drawAt(x, y, '@');
}