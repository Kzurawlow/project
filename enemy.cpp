#include "enemy.h"

enemy::enemy()
{
	///size of rect, important for collisions checking
	rect.setSize(Vector2f(25, 42));
	///initial rect position == enemy position
	rect.setPosition(400, 150);
	sprite.setPosition(400, 150);
	///for checking
	rect.setFillColor(Color::Blue);
	///initial direction(some fragment of spritesheet)
	sprite.setTextureRect(IntRect(0, 84, 32, 44));
}

void enemy::update() {
	///enemy position == rect position 
	sprite.setPosition(rect.getPosition());
}

void enemy::updateMovement()
{
	///direction = generateRandom(4);
	///begin.x/begin.y/width.x/length.y
	
	if (direction == 1)///up
	{
		rect.move(0, -movementSpeed);
		sprite.setTextureRect(IntRect(counterwalking, 20, 32, 44));
	}
	else if (direction == 2)///down
	{
		///rect(enemy movement animation)
		rect.move(0, movementSpeed);
		sprite.setTextureRect(IntRect(counterwalking, 84, 32, 44));
	}
	else if (direction == 3)///left
	{
		rect.move(-movementSpeed, 0);
		sprite.setTextureRect(IntRect(counterwalking1, 212, 32, 44));
	}
	else if (direction == 4)///right
	{
		rect.move(movementSpeed, 0);
		sprite.setTextureRect(IntRect(counterwalking1,148, 32, 44));
	}
	else
	{
		///no movement(enemy stays in last position, but does not move)
	}
	///transition between fragments, counter usage
	counterwalking += 32;
	if (counterwalking == 160) {
		counterwalking = 0;
	}
	counterwalking1 += 32;
	if (counterwalking1 == 256) {
		counterwalking1 = 0;
	}
	///random directions
	counter++;
	if (counter >= 100) {
		direction = generateRandom(20);
		counter = 0;

	}
}

enemy::~enemy()
{
}
