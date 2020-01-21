#pragma once
//! class textDisplay that supports hp decreasing of player/enemy.
/*!
*/

#include"container.h"
class textDisplay: public container
{
public:
	///just initialized string
	string myString = "default";
	/// speed of hp that player/enemy lose goes vertically up with speed 1 
    float movementSpeed = 1;
	textDisplay();
	~textDisplay();
	///counts how long player/enemy hp should go vertically 
	int counter = 0;
	///lifetime
	int lifeTime = 100;
	///destroyed, but when lifeTime ends
	bool destroy = false;
	/// function operates the text(hp lose of enemy/hero) display with usage of variables defines above
	void update();
};

