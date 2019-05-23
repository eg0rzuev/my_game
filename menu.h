#include "MAIN_HEADER.h"

#ifndef MY_GAME_MENU_H
#define MY_GAME_MENU_H

class Menu
{
	public:
		Menu(sf::RenderWindow&, std::string);
		virtual void		show();
	protected:
		enum BUTTON
		{
			WIDTH  = 300,
			HEIGTH = 138,
			START  = 1
		};		
		bool 			isMenu_;
		sf::Texture		startTexture_;
		sf::Sprite		startBtn_;
		sf::RenderWindow&	window_;
		int			button_;
};

class MainMenu: public Menu
{
	public:
		MainMenu(sf::RenderWindow&, std::string, std::string);
		void show() override;
	private:
		enum INFO
		{
			WIDTH  = 463,
			HEIGTH = 157
		};		
		sf::Texture		infoTexture_;
		sf::Sprite		gameInfo_;	
};	

#endif //MY_GAME_MENU_H
