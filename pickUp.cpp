#include "pickUp.h"

//this funtion is not needed now
pickUp::pickUp()
{
	//rect.setSize(Vector2f(32, 32));
	//rect.setPosition(400, 200);
	//rect.setFillColor(Color::Blue);
	//sprite.setTextureRect(IntRect(0, 0, 32, 32));
	//sprite.setPosition(400, 200);
}
//update function, as in enemy and projectille class
void pickUp::update() {
	sprite.setPosition(rect.getPosition());
}

