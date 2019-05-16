//
// Created by egor on 4/30/19.
//

#include "subjects.h"
#include <ctime>
Entity::Entity(float x, float y, int health, float width, float heigth, const std::string& imageName):
	x_(x),
	y_(y),
	health_(health),
	width_(width),
	heigth_(heigth),
	alive_(true)
	{
		image_.loadFromFile("images/" + imageName);
		texture_.loadFromImage(image_);
		texture_.setSmooth(true);
		sprite_.setTexture(texture_);
		sprite_.setPosition(x_,y_);
	}

float Entity::getX()
{
	return sprite_.getPosition().x;
}	

float Entity::getY()
{
	return sprite_.getPosition().y;
}

Spaceship::Spaceship(float x, float y, int health, float width, float height, const std::string& imageName): 
	Entity(x, y, health, width, height, imageName),
	prevTime_(0)
	{
		sprite_.setScale(width_/image_.getSize().x, heigth_/image_.getSize().y);
		isShoot_ = false;
	}

Bullet::Bullet(float x, float y, int health, float width, float height, const std::string& imageName, const sf::RenderWindow& window): 
	Entity(x, y, health, width, height, imageName),
        window_(window),	
	dir_(sf::Mouse::getPosition(window_).x - x_, sf::Mouse::getPosition(window_).y - y_)
	{
		sprite_.setScale(width_/image_.getSize().x, heigth_/image_.getSize().y);
		sprite_.rotate(dir_.getAngle());
	}

Asteroid::Asteroid(float x, float y, int health, float width, float height, const std::string& imageName, const Spaceship& spcshp): 
	Entity(x, y, health, width, height, imageName),	
	dir_(spcshp.getX()- x_, spcshp.getY() - y_)
	{
		sprite_.setScale(width_/image_.getSize().x, heigth_/image_.getSize().y);
		sprite_.rotate(dir_.getAngle());
	}


void Spaceship::update(float time)
{
	control();
}

void Spaceship::control()
{
	time_t timeCurr = clock();
	if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && (float)(timeCurr - prevTime_)/CLOCKS_PER_SEC > 0.3)
    	{
		isShoot_ = true;
		prevTime_ = timeCurr;
    	}
	/*if((float)(timeCurr - prevTime_)/CLOCKS_PER_SEC < 0.3)
		isShoot_ = false;*/
}

const float Spaceship::getX() const
{
	return x_;
}

const float Spaceship::getY() const
{
	return y_;
}

void Bullet::update(float time)
{
	//if(p.isShoot_ == true)
	sprite_.move(BULLET_SPEED * time * dir_.getCos(), BULLET_SPEED * time * dir_.getSin());
}

void Asteroid::update(float time)
{
	sprite_.move(ASTEROID_SPEED * time * dir_.getCos(), ASTEROID_SPEED * time * dir_.getSin());
}

Vector_2d<float> Asteroid::getDir()
{
	return dir_;
}
/*
float Asteroid::getWidth()
{
	return width_;
}

float Asteroid::getHeigth()
{
	return heigth_;
}*/

bool checkCol(Entity* bullet, Entity* asteroid)
{
	Vector_2d<float> AB(asteroid -> width_ * asteroid -> getDir().getCos(), asteroid -> width_ * asteroid -> getDir().getSin());
	Vector_2d<float> AC(-asteroid -> heigth_ * asteroid -> getDir().getSin(), asteroid -> heigth_ * asteroid -> getDir().getCos());
	Vector_2d<float> Abullet(bullet -> getX() - asteroid -> getX(), bullet -> getY() - asteroid -> getY());
	if(Abullet * AB >= 0 && (Abullet * AB)/AB.abs() <= AB.abs() && Abullet * AC >= 0 && (Abullet * AC)/AC.abs() <= AC.abs())
		return true;
	return false;
}	
