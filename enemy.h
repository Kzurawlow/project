#pragma once
#include"container.h"
#include"random.h"
//! class enemy that inherits from class container.
/*!
In this class we can find operations on enemy with rect and enemies parameters
*/
class enemy : public container
{
	///enemy movement speed(when walking)
	float movementSpeed = 2;
public:
	///counter left/right
	int counterwalking = 0;
	///counter up / down
	int counterwalking1 = 0;
	///random funtion counter
	int counter = 0;
	///3 hits kill enemy
	int hp = 3;
	///created enemy is alive
	bool alive = true;
	///initialized direction variable
	float direction = 0; //1=up,2-down, 3-left 4-right
	///if enemy hits champion, champion hp decreases by 1
	int attackDamage = 1;
	///function updates rect position to be in the same place that enemy is 
	void update();
	///function updates movement and supports enemy walking animation
	void updateMovement();
	enemy();
	~enemy();
};


