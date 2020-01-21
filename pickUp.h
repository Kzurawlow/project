#pragma once
//! class  pickUp that supports picking up coins from map. 
/*!
*/
#include"container.h"
class pickUp : public container
{
public:
	///coin exists by default
	bool isCoin = true;
	///each coin has value 5
	int coinValue = 5;

	pickUp();
	///function updates rect position to be in the same place that coin is 
	void update();
	///created coin is not destroyed as default
	bool destroy = false;
};