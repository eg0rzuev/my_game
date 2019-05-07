//
// Created by egor on 4/30/19.
//

#ifndef MY_GAME_SUBJECTS_H
#define MY_GAME_SUBJECTS_H


#include <SFML/Audio.hpp>

class Subjects
{
	public:
    		virtual void shoot() = 0;
	protected:
    		int X_;
    		int Y_;
    		int health_;
		sf::Image image_;
};

class Spaceship: public Subjects
{

}	

#endif //MY_GAME_SUBJECTS_H
