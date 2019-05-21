//
// Created by egor on 4/30/19.
//

#ifndef MY_GAME_SUBJECTS_H
#define MY_GAME_SUBJECTS_H

#include <SFML/Audio.hpp>
#include "MAIN_HEADER.h"
#include "vector_2d.hpp"
#define BULLET_SPEED 0.0004
#define ASTEROID_SPEED 0.0002
class Entity
{
	public:
		Entity(float x, float y, int health, float width, float height, const std::string& imageName);
    		virtual void 				update(float time) = 0;
		sf::Sprite				sprite_; 
		sf::Texture				texture_;
		virtual const float			getX() const;
		virtual const float			getY() const ;
		virtual Vector_2d<float> 		getDir(){}
    		float 					x_;
    		float 					y_;
		float 					width_;
		float					heigth_;
		int 					health_;
		bool 					alive_;
		sf::Image				image_;
};

class Spaceship: public Entity
{
	public:
		Spaceship		(float x, float y, int health, float width, float heigth, const std::string& imageName);
		void 			update(float time) override;
		bool 			isShoot_;
		const float		getX() const override;
		const float		getY() const override;
	private:
		void 			shoot();
		time_t 			prevTime_;
		void 			control();	
};	

class Bullet: public Entity
{
	public:
		Bullet(float x, float y, int health, float width, float heigth, const std::string& imageName, const sf::RenderWindow&);	
		//void update(float time, Spaceship) /*override*/;
		void update(float time) override;
	private:
		const sf::RenderWindow& window_;
		Vector_2d<float> dir_;

			
};

class Asteroid: public Entity
{
	public:
		Asteroid(float x, float y, int health, float width, float height, const std::string& imageName, const Spaceship&);
		void update(float time) override;
		Vector_2d<float> getDir() override;
	private:
		Vector_2d<float> dir_;
};	

bool checkCol(Entity*, Entity*);

#endif //MY_GAME_SUBJECTS_H
