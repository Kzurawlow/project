#include "player.h"
        


player::player()
{
	rect.setSize(Vector2f(30,55));
	rect.setPosition(200, 200);
	rect.setPosition(200,200);
	//configuration tool
	rect.setFillColor(Color::Blue);
	//initial spritesheet fragment
	sprite.setTextureRect(IntRect(0, 0, 65, 65));
	sprite.setPosition(200, 200);
}

//classical update function, as in other classes
void player::update() {
	sprite.setPosition(rect.getPosition().x-17, rect.getPosition().y-5);
	//player1.rect.getPosition().x + 25,player1.rect.getPosition().y + 40
}

void player::updateMovement()
{
	//begin.x/begin.y/width.x/length.y
	//if player press "Up" button, go up
	if (Keyboard::isKeyPressed(Keyboard::Up)) {
		rect.move(0, -movementSpeed);
		sprite.setTextureRect(IntRect(counterwalking, 195, 65, 65));
		direction = 1;
	}
	//if player press "Down" button, go up
	if (Keyboard::isKeyPressed(Keyboard::Down)) {
		rect.move(0, movementSpeed);
		sprite.setTextureRect(IntRect(counterwalking, 0, 65, 65));
		direction = 2;
	}
	//if player press "Left" button, go up
	if (Keyboard::isKeyPressed(Keyboard::Left)) {
		rect.move(-movementSpeed, 0);
		sprite.setTextureRect(IntRect(counterwalking, 65, 65, 65));
		direction = 3;
	}
	//if player press "Right" button, go up
	if (Keyboard::isKeyPressed(Keyboard::Right)) {
		rect.move(movementSpeed, 0);
		sprite.setTextureRect(IntRect(counterwalking, 130, 65, 65));
		direction = 4;
	}
	//animation counter
	counterwalking += 65;
	if (counterwalking == 260) {
		counterwalking = 0;
	}
}

player::~player()
{
}
