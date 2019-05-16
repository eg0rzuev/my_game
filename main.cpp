//#include <iostream>
//#include <list>
//#include <SFML/Graphics.hpp>
#include "MAIN_HEADER.h"
//#include "objects.h"
//#include "subjects.h"

/*
 * main.cpp file, here is where program works
 *
 * sf and std namespaces are used 
 * so there is no "using namespace std" which may be confusing
 *
 * !!!!basic sfml things are not explained!!!!
 *
 * files are:
 * 	MAIN_HEADER.h
 * 	objects.h objects.cpp
 * 	textures.cpp
 *	todo subjects.cpp subjects.h
 */

int main() {
    	sf::RenderWindow window(sf::VideoMode(MAP_WIDTH * SQUARE_SIZE , MAP_HEIGTH * SQUARE_SIZE), "Game", sf::Style::Close);
	sf::Clock clock;
	srand(time(nullptr));

	std::list<Entity*> 			entities;
	std::list<Entity*>			asteroids;
	std::vector<BackgrObj*>			bckgrObj;

	std::list<Entity*>::iterator 		entIt;
	std::list<Entity*>::iterator 		astIt;
	std::vector<BackgrObj*>::iterator 	objIt;

	/* here objects from background are initilised
	 * their description is given in objects.h objects.cpp
	 *
	 */	

	Spaceship spaceship(50, 350, 5, 200, 200, "spaceship.png");
	
	for(int i = 0; i < 8; i++)
	{
		bckgrObj.push_back(NEW NatureObj(300 + rand()%801,  500 + rand()%100, 20   + rand()%6, 
						  20 + rand()%6, "rock" + std::to_string(1 + rand()%3) + ".png"));
		bckgrObj.push_back(NEW Star(100 + rand()%900, 100 +rand()%301, 3 + rand()%10));		       	
	}	

	for(int i = 0; i < 5; i++)
	{
		asteroids.push_back(NEW Asteroid(1100 + rand()%50, rand()%600, 1, 80, 80, "asteroid.png", spaceship));
	}

	bckgrObj.push_back(NEW NatureObj(0, 250, 1200, 202, "mountains.png"));
	bckgrObj.push_back(NEW NatureObj(900, 100, 150, 100, "planet_1.png"));
	bckgrObj.push_back(NEW Smoke	(230, 440));
	

	while (window.isOpen())
    	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
	        	sf::Event event;
        	while (window.pollEvent(event))
        	{
            		if (event.type == sf::Event::Closed)
               			window.close();
			if(spaceship.isShoot_)
			{
				spaceship.isShoot_ = false;
				entities.push_back(NEW Bullet(spaceship.getX() + 100, spaceship.getY(), 1, 10, 10, "bullet.png", window));
			}	
       		}
        	window.clear();
		drawBackGround("map_t.png", window);

		// here everything is drawn in window
		//
		// !!!
		// todo this is too large and new classes with some methods are required
		// !!!
		
        	for(objIt = bckgrObj.begin(); objIt != bckgrObj.end(); objIt++)
		{
			(*objIt) -> draw(window);
		}
		for(astIt = asteroids.begin(); astIt != asteroids.end(); astIt++)
		{
			(*astIt) -> update(time);
			window.draw((*astIt) -> sprite_);
			
		}
		spaceship.update(time);
		window.draw(spaceship.sprite_);
		for(entIt = entities.begin(); entIt != entities.end(); entIt++)
		{
			(*entIt) -> update(time);
				window.draw((*entIt) -> sprite_);
		}
		
		for(entIt = entities.begin(); entIt != entities.end(); entIt++)
		for(astIt = asteroids.begin(); astIt != asteroids.end(); astIt++)
		{
			if(checkCol((*entIt), (*astIt)))
			{

				(*astIt) -> alive_ = false;
				(*entIt) -> alive_ = false;
			}
		}
		for(entIt = entities.begin(); entIt != entities.end();)
		{
			Entity* b = *entIt;
			if(!b -> alive_)
			{
				entIt = entities.erase(entIt);
				DELETE(b);
			}
			else entIt ++;	
		}
		for(astIt = asteroids.begin(); astIt != asteroids.end();)
		{
			Entity* b = *astIt;
			if(!b -> alive_)
			{
				astIt = asteroids.erase(astIt);
				DELETE(b);
			}
			else astIt ++;	
		}
		window.display();	
    }

    return 0;
}
