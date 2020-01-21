#pragma once
//! class  projectille that supports animation of shooting to enemy.
/*!
*/
#include"container.h"
class projectile : public container
{
public:
	///movement speed of projectile that is fired by hero
	float movementSpeed = 15;
	/// attack damage that deals protectile that hits enemy
	int attackDamage = 1;
	///initialized direction variable 
	int direction = 0; //1=up,2-down, 3-left 4-right
	///projectile is alive when fired
	bool destroy = false;
	projectile();
	///function update that updates directions of shooted bullet
	void update();
	~projectile();
};

