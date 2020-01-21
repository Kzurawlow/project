#pragma once
#include<SFML\Graphics.hpp>
#include<SFML\System.hpp>
#include<iostream>
using namespace sf;
using namespace std;

//! main class "container", which is inherited by other functions.
/*!
Almost every function uses rect(rectangle) and sprite.
*/
class container
{
public:

	///rect - The rectangle that almost all function with movement are operating on
	RectangleShape rect;
	///sprite - loading sprites
	Sprite sprite;
	///text - loading texts
	Text text;
	///function update() - virtual function update rects
	virtual void update() {

	}
	///function updateMovement() - virtual function that updates movement of rects
	virtual void updateMovement() {

	}
	container();
	~container();
};

