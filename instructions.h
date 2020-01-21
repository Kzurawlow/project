#pragma once
#include<iostream>
#include<string>
using namespace std;
//! class instructions that prints instructions to the game in the standard input.
/*!
*/
class instructions
{
private:
	///champHp - private parameter with champ hp called in main
	int  champHp;
	/// name  - private parameter with name of hero called in main
	string name;
public:
	instructions();
	/**
	 * A constructor.
	 * @param name - name of hero.
	 * @param champHp - how many hp champ have.
	 */
	instructions(string name, int champHp) : name{ name }, champHp{ champHp }{}

	~instructions();
	///friend ostream operator with instructions to the game(standard output)
	friend ostream&operator<<(ostream&ost, const instructions& instructions) {
		ost << "Instructions to game: \n";
		ost << "Your champ " << instructions.name << " has " << instructions.champHp << " lives" << endl;
		ost << "Use arrows to move the champ in direction, that you choose" << endl;
		ost << "Press 'space' to light the fire to the enemy " << endl;
		ost << "Press 'Y' to increase number of enemies" << endl;
		ost << "To escape from game press 'ESC' button " << endl;
		return ost;
	}
};

