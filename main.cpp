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
 *	subjects.cpp subjects.h
 *	menu.cpp menu.h
 *
 *	images/...
 *
 */

int main(int argc, char* argv[]) { 

	int myRank = 0;
	int size = 0;
	srand(time(nullptr));

	/* here objects from background are initilised
	 * their description is given in objects.h objects.cpp
	 *
	 */	

/*	MPI_Status status;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &myRank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);*/

//	if(myRank == 0)
//	{

	//std::ofstream fout("Log.txt");	
	std::list<Entity*> 			entities;
	std::list<Entity*>			asteroids;
	std::vector<BackgrObj*>			bckgrObj;

	std::list<Entity*>::iterator 		entIt;
	std::list<Entity*>::iterator 		astIt;
	std::vector<BackgrObj*>::iterator 	objIt;

	Spaceship spaceship(50, 350, 5, 200, 200, "spaceship.png");

	for(int i = 0; i < 8; i++)
	{	
		bckgrObj.push_back(NEW NatureObj(200 + rand()%801,  500 + rand()%100, 20   + rand()%6, 
						  20 + rand()%6, "rock" + std::to_string(1 + rand()%3) + ".png"));
		bckgrObj.push_back(NEW Star(100 + rand()%900, 100 +rand()%301, 3 + rand()%10));		       	
	}	
	
/*	int randInt = rand()%2;

	for(int i = 0; i < randInt; i++)
	{
		asteroids.push_back(NEW Asteroid(1100 + rand()%50, rand()%600, 1, 80, 80, "asteroid.png", spaceship));

	}*/


	sf::RenderWindow window(sf::VideoMode(MAP_WIDTH * SQUARE_SIZE , MAP_HEIGTH * SQUARE_SIZE), "Game", sf::Style::Close);
	sf::Clock clock;
	Menu menu(window, "back.png");
	MainMenu mainMenu(window, "start.png", "info.png");
	
	bckgrObj.push_back(NEW NatureObj(0, 250, 1200, 202, "mountains.png"));
	bckgrObj.push_back(NEW NatureObj(900, 100, 150, 100, "planet_1.png"));
	bckgrObj.push_back(NEW Smoke	(230, 440));
	
	mainMenu.show();
	clock.restart();
	while (window.isOpen())
    	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
	        sf::Event event;

        	while (window.pollEvent(event))
        	{
            		if(event.type == sf::Event::Closed)
               			window.close();
			if(spaceship.isShoot_)
			{
				spaceship.isShoot_ = false;
				entities.push_back(NEW Bullet(spaceship.Entity::getX() + spaceship.width_/2, spaceship.Entity::getY(),
			        1, 10, 10, "bullet.png", window));
			}
			if(event.type == sf::Event::KeyPressed)
			{
				if(event.key.code == sf::Keyboard::Escape)
				{
					menu.show();
					clock.restart();
				}
			}			
       		}

        	window.clear();
		drawBackGround("map_t.png", window);

		// here everything is drawn in window
		//

	        for(objIt = bckgrObj.begin(); objIt != bckgrObj.end(); objIt++)
		{
			(*objIt) -> draw(window);
		}

		spaceship.update(time);
		window.draw(spaceship.sprite_);

		for(astIt = asteroids.begin(); astIt != asteroids.end(); astIt++)
		{
			(*astIt) -> update(time);
			window.draw((*astIt) -> sprite_);
			
		}

		for(entIt = entities.begin(); entIt != entities.end(); entIt++)
		{
			(*entIt) -> update(time);
			window.draw((*entIt) -> sprite_);
		}
		
		for(astIt = asteroids.begin(); astIt != asteroids.end(); astIt++)
		for(entIt = entities.begin(); entIt != entities.end(); entIt++)
		{

			if(checkCol((*entIt), (*astIt)) || (*astIt) -> getX() < 0)
			{
				std::string result("asteroid destroyed!");
				//MPI_Send(result.c_str(), result.size(), MPI_CHAR, 1, 0, MPI_COMM_WORLD);		
				//int message = 333;
				//MPI_Send(&message, sizeof(int), MPI_INT, 1, 0, MPI_COMM_WORLD);		
				(*astIt) -> alive_ = false;
				(*entIt) -> alive_ = false;
			}
			if((*entIt) -> getX() < 0 || (*entIt) -> getX() > 1250)
				(*entIt) -> alive_ = false;
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
			else astIt++;	
		}
		if(asteroids.begin() == asteroids.end())
		{
			for(int i = 0; i < 5 + rand()%6; i++)
			{
				asteroids.push_back(NEW Asteroid(1100 + rand()%50, rand()%600, 1, 80, 80, "asteroid.png", spaceship));
			}
		}
		window.display();	
    	}

	
    	return 0;
}
