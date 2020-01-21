#include "textDisplay.h"



textDisplay::textDisplay()
{
	text.setFillColor(Color::Red);
	text.setCharacterSize(20);
	text.setString(myString);
}

void textDisplay::update() {
	text.move(0, -movementSpeed);

	counter++;
	if (counter >= lifeTime) {
		destroy = true;
	}
}

textDisplay::~textDisplay()
{
}
