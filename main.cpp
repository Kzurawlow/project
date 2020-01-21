#include<SFML\Graphics.hpp>
#include<SFML\Audio.hpp>
#include<SFML\Audio\Music.hpp>
#include<SFML\System\FileInputStream.hpp>
#include<SFML\System\InputStream.hpp>
#include<SFML\System.hpp>
#include<iostream>
using namespace sf;
using namespace std;
#include"player.h"
#include"container.h"
#include"projectile.h"
#include"enemy.h"
#include"random.h"
#include"textDisplay.h"
#include"pickUp.h"
#include"instructions.h"

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>





int main() {
	///stream overloaded operator
	instructions instructions{"Dino",10};
	cout << instructions;

	///clocks defined below
	Clock clock;
	Clock clock2;
	Clock clock3;

	///window size and name
	RenderWindow Window(VideoMode(1000,800), "RPG Game");

	///fps limit
	Window.setFramerateLimit(60);
	///////////////////////////////////////////////////////////
	Texture textureEnemy;
	if (!textureEnemy.loadFromFile("nobgenemy.png")) {
		return EXIT_FAILURE;
	}
	///////////////////////////////////////////////////////////
	///texture coin
	Texture textureCoin;
	if (!textureCoin.loadFromFile("coin_small_nobg.png")) {
		return EXIT_FAILURE;
	}
	//////////////////////////////////////////////////////////////
	///texture ammo
	Texture textureFireBall;
	if (!textureFireBall.loadFromFile("ammo.png")) {
		return EXIT_FAILURE;
	}
	//////////////////////////////////////////////////////////////
	Texture texturePlayer;
	if (!texturePlayer.loadFromFile("nobg.png")) {
		return EXIT_FAILURE;
	}
	////////////////////////////////////////////////////
	
	Font font;
	if (!font.loadFromFile("Digireu_.ttf")) {
	return EXIT_FAILURE;
	}

	Text text("Wallet: ", font, 25);
	text.setCharacterSize(25);
	text.setFillColor(Color::Yellow);
	text.setPosition(0, 0);

	Text text1("You die: ", font, 25);
	text1.setCharacterSize(35);
	text1.setFillColor(Color::Red);
	text1.setPosition(100, 380);

	Text text2("hp: ", font, 25);
	text2.setCharacterSize(25);
	text2.setFillColor(Color::Yellow);
	text2.setPosition(300, 0);

	///pointer used by virtual functions
	container* cptr;
	
	///player class object
	class player player1;
	cptr = &player1;
	player1.sprite.setTexture(texturePlayer);
	player1.rect.setFillColor(Color::Red);//

	///projectile object
	vector<projectile>::const_iterator iter;
	vector<projectile> projectileArray;
	class projectile projectile1;
	projectile1.sprite.setTexture(textureFireBall);
	///do not show all spritesheet
	projectile1.sprite.setTextureRect(IntRect(0, 0, 0, 0));

	///enemy object
	vector<enemy>::const_iterator iter4;
	vector<enemy> enemyArray;

	class enemy enemy1;

	enemy1.sprite.setTexture(textureEnemy);
	///the initial position of the first enemy
	enemy1.rect.setPosition(400, 200);
	enemyArray.push_back(enemy1);

	///textDisplay vector array
	vector<textDisplay>::const_iterator iter8;
	vector<textDisplay> textDisplayArray;

	///textDisplay object
	class textDisplay textDisplay1;
	textDisplay1.text.setFont(font);

	///pickup vector array
	vector<pickUp>::const_iterator iter11;
	vector<pickUp> pickUpArray;

	///pickUp object
	class pickUp pickUp1;
	pickUp1.sprite.setTexture(textureCoin);
	pickUp1.rect.setPosition(500, 500);
	pickUp1.rect.setSize(Vector2f(32, 32));
	pickUp1.rect.setFillColor(Color::Blue);
	pickUpArray.push_back(pickUp1);

	///game displaying loop
	while (Window.isOpen()) {
		Event event;
		while (Window.pollEvent(event)) {
			/// Request for closing the window
			if (event.type == sf::Event::Closed) {
				Window.close();
			}
			/// The escape key was pressed
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) {
				Window.close();
			}
		}
		Window.clear();
		int counter = 0;
		///clock
		///the time difference from the last restart to the present.
		Time elapsed1 = clock.getElapsedTime();
		Time elapsed2 = clock2.getElapsedTime();
		Time elapsed3 = clock3.getElapsedTime();
		
		
		///player collision with pickUp items
		int counter0;
		counter0 = 0;
		for (iter11 = pickUpArray.begin(); iter11 != pickUpArray.end(); iter11++) {
			if (player1.rect.getGlobalBounds().intersects(pickUpArray[counter0].rect.getGlobalBounds())) {

				if (pickUpArray[counter0].isCoin==true) {
					{
						player1.wallet += pickUpArray[counter0].coinValue;
					}
				}
				pickUpArray[counter0].destroy = true; 
			}
			counter0++;
		}
	

		if (elapsed2.asSeconds() >= 0.5) 
		{
			clock2.restart();
			///enemy collides with player(player lose hp)
			for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
			{
				if (player1.rect.getGlobalBounds().intersects(enemyArray[counter].rect.getGlobalBounds()))
				{
					textDisplay1.text.setString(to_string(enemyArray[counter].attackDamage));
					textDisplay1.text.setPosition(player1.rect.getPosition().x + player1.rect.getSize().x / 2, player1.rect.getPosition().y - player1.rect.getSize().y / 2);
					textDisplayArray.push_back(textDisplay1);

					player1.hp -= enemyArray[counter].attackDamage;
				}
				counter++;
				if (player1.hp <= 0) {
					sf::sleep(sf::seconds(1));
					text1.setString("You have no lives\nPress esc to close the window");
					Window.draw(text1);
					
				}
			}
		}
		text2.setString("Player hp: " + to_string(player1.hp));

		///projectile colides with enemy
		counter = 0;
		for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
		{
			int counter2 = 0;
			for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++) 
			{
				///checking if projectille rect hit enemy rect
				if (projectileArray[counter].rect.getGlobalBounds().intersects(enemyArray[counter2].rect.getGlobalBounds()))
				{
					projectileArray[counter].destroy = true;
					///hp that enemy lose
					textDisplay1.text.setString(to_string(projectileArray[counter].attackDamage));
					///from the middle point of rect(enemy)
					textDisplay1.text.setPosition(enemyArray[counter2].rect.getPosition().x +enemyArray[counter2].rect.getSize().x/2, enemyArray[counter2].rect.getPosition().y-enemyArray[counter2].rect.getSize().y/2);
					textDisplayArray.push_back(textDisplay1);

					enemyArray[counter2].hp--;
					if (enemyArray[counter2].hp<=0) {
						enemyArray[counter2].alive = false;
					}
				}
				counter2++;
			}
			counter++;
		}
		///delete dead enemy
		counter = 0;
		for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++) 
		{
			if (enemyArray[counter].alive==false) {
				cout << "enemy has been slain" << endl;
				//create coins 
				if (generateRandom(4) == 1) {
					pickUp1.rect.setPosition(enemyArray[counter].rect.getPosition());
					pickUpArray.push_back(pickUp1);
				}
				enemyArray.erase(iter4);
				break;
			}
			counter++;
		}
		///delete Projectile that hits something
		counter = 0;
		for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++) {
			if (projectileArray[counter].destroy==true) {
				//cout << " projectile just hit an enemy" << endl;//just for checking
				projectileArray.erase(iter); break;
			}
			counter++;
		}
		///delete text 
		counter = 0;
		for (iter8 = textDisplayArray.begin(); iter8 != textDisplayArray.end(); iter8++) {
			if (textDisplayArray[counter].destroy==true) {
				textDisplayArray.erase(iter8);
				break;
			}
			counter++;
		}

		///delete taken money
		counter = 0;
		for (iter11 = pickUpArray.begin(); iter11 != pickUpArray.end(); iter11++) {
			if (pickUpArray[counter].destroy == true) {
				pickUpArray.erase(iter11);
				break;
			}
			counter++;
		}
		///create more enemies in random places
		if (Keyboard::isKeyPressed(Keyboard::Y)) {
			enemy1.rect.setPosition(generateRandom(Window.getSize().x), generateRandom(Window.getSize().y));
			enemyArray.push_back(enemy1);
		}
		///fire projectile 
		///clock to avoid constant lane of projectilles
		if (elapsed1.asSeconds() >= 0.1) {
			clock.restart();
			//fire projectille
			if (Keyboard::isKeyPressed(Keyboard::Space)) {
				projectile1.rect.setPosition(player1.rect.getPosition().x ,player1.rect.getPosition().y+20);//
				projectile1.direction = player1.direction;
				projectileArray.push_back(projectile1);
			}
		}
		///draw pickUp money  
		counter = 0;
		for (iter11 = pickUpArray.begin(); iter11 != pickUpArray.end(); iter11++) {
			pickUpArray[counter].update();//update coins
			//Window.draw(pickUpArray[counter].rect);//configuration tool
			Window.draw(pickUpArray[counter].sprite);

			counter++;
		}

		///draw projectile
		counter = 0;
		for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++) {
			projectileArray[counter].update();
			//Window.draw(projectileArray[counter].rect);//configuration tool
			Window.draw(projectileArray[counter].sprite);

			counter++;
		}
		///draw enemies
		counter = 0;
		for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++) {\
			///update enemy
			enemyArray[counter].update();
			///update enemy movement
			enemyArray[counter].updateMovement();
			//Window.draw(enemyArray[counter].rect);//configuration tool
			Window.draw(enemyArray[counter].sprite);

			counter++;
		}
		
		//virtual function calling
		cptr->update();
		cptr->updateMovement();

		//Draw player sprite
		Window.draw(player1.sprite);
		//Window.draw(player1.rect);//configuration tool

		//draw text
		counter = 0;
		for (iter8 = textDisplayArray.begin(); iter8 != textDisplayArray.end(); iter8++) {
			textDisplayArray[counter].update();
			Window.draw(textDisplayArray[counter].text);
			counter ++ ;
		}

		//how rich am i 
		text.setString("Wallet: " + to_string(player1.wallet));
		//lives of enemy
		Window.draw(text);
		//lives of champ
		Window.draw(text2);
		_CrtDumpMemoryLeaks();
		//update the window
		Window.display();
	}
	
}
