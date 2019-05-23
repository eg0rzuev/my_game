#include "menu.h"

Menu::Menu(sf::RenderWindow& window, std::string startIm):
	isMenu_(true),
	button_(0),
	window_(window)
	{	
		startTexture_.loadFromFile("images/" + startIm);
		startBtn_.setTexture(startTexture_);
		startBtn_.setPosition(window.getSize().x/2 - BUTTON::WIDTH/2, window.getSize().y/2 - BUTTON::HEIGTH/2);
	}

MainMenu::MainMenu(sf::RenderWindow& window, std::string startIm, std::string infoIm):
	Menu(window, startIm)
	{
		//startTexture_.loadFromFile("images/" + startIm);
		infoTexture_.loadFromFile("images/" + infoIm);
		//startBtn_.setTexture(startTexture_);
		gameInfo_.setTexture(infoTexture_);
		gameInfo_.setPosition(window.getSize().x/2 - INFO::WIDTH/2 , (MAP_HEIGTH - GROUND_HEIGTH) * SQUARE_SIZE);
		//startBtn_.setPosition(window.getSize().x/2 - BUTTON::WIDTH/2, window.getSize().y * 0.75 - BUTTON::HEIGTH/2);
	}

void Menu::show()
{
	isMenu_ = true;
	sf::Vector2<int> mousePos = {0,0};
	sf::Event event;

	while(isMenu_)
	{
		button_ = 0;
		mousePos = sf::Mouse::getPosition(window_);
		
		while(window_.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
				window_.close();
			if(event.type == sf::Event::KeyPressed)
			{
				if(event.key.code == sf::Keyboard::Escape)
				{
					isMenu_ = false;
				}
			}	
		}
			

		if(sf::IntRect(startBtn_.getPosition().x,startBtn_.getPosition().y,BUTTON::WIDTH,BUTTON::HEIGTH).contains(mousePos))
			button_ = BUTTON::START;

		if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if(button_ == BUTTON::START)
				isMenu_ = false;
		}
		
		//drawBackGround("map_t.png", window_);
		window_.draw(startBtn_);	
		window_.display();
	}
}

void MainMenu::show()
{
	isMenu_ = true;
	sf::Vector2<int> mousePos = {0,0};
	sf::Event event;
	while(isMenu_)
	{
		button_ = 0;
		mousePos = sf::Mouse::getPosition(window_);
		
		while(window_.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
				window_.close();
			if(event.type == sf::Event::KeyPressed)
			{
				if(event.key.code == sf::Keyboard::Escape)
				{
					isMenu_ = false;
				}
			}	
		}
			

		if(sf::IntRect(startBtn_.getPosition().x,startBtn_.getPosition().y,BUTTON::WIDTH,BUTTON::HEIGTH).contains(mousePos))
			button_ = BUTTON::START;

		if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if(button_ == BUTTON::START)
				isMenu_ = false;
		}
		
		drawBackGround("map_t.png", window_);
		window_.draw(gameInfo_);
		window_.draw(startBtn_);	
		window_.display();
	}
}
