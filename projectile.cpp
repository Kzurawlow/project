#include "projectile.h"



projectile::projectile()
{
	rect.setSize(Vector2f(25, 30));
	rect.setPosition(400, 200);
	rect.setFillColor(Color::Blue);
}

void projectile::update() {

	///different sizes, when projectile goes in different directions
	///no counter need, projectile always looks the same(for 1 direction)
	if (direction == 1) {//up
		rect.setSize(Vector2f(25, 30));
		rect.move(0, -movementSpeed);
		sprite.setTextureRect(IntRect(205, 137, 30, 35));
	}
	if (direction == 2) {//down
		rect.setSize(Vector2f(25, 30));
		rect.move(0, movementSpeed);
		sprite.setTextureRect(IntRect(205,395, 30, 45));
	}
	if (direction == 3) {//left
		rect.setSize(Vector2f(35, 25));
		rect.move(-movementSpeed, 0);
		sprite.setTextureRect(IntRect(0, 18, 35, 32));
	}
	if (direction == 4) {//right
		rect.setSize(Vector2f(35, 25));
		rect.move(movementSpeed, 0);
		sprite.setTextureRect(IntRect(25, 270, 40, 32));
	}

	//sprite set at rect coordinates
	sprite.setPosition(rect.getPosition());
}



projectile::~projectile()
{
}
