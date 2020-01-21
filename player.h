#pragma once
#include"container.h"
//! Class contains variables and methods that describes player.
/*!
*/
class player : public container
{
public:
	///player movementSpeed
	float movementSpeed = 4;
	///counter(change png fragments)
	int counterwalking = 0;
	///hero hp
	int hp = 10;
	///initialized direction variable
	int direction = 0; //1=up,2-down, 3-left 4-right
	/// attack damage of player weapon
	int attackDamage = 5;
	///at the begining of game hero has empty wallet
	int wallet = 0;
	///initially hero is alive
	bool alive = true;
	///function updates rect position to be in the same place that hero is 
	void update();
	///function updates movement(checking which key was pressed) and supports player walking animationm with such direction
	void updateMovement();

	player();
	~player();
};

