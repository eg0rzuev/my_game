#include <iostream>
#include <SFML/Graphics.hpp>
#include "MAIN_HEADER.h"
#include "objects.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1196, MAP_HEIGTH * SQUARE_SIZE), "Game");

    NatureObj mountains(0, 250, 1200, 202, "mountains.png");
    NatureObj moon(900, 100, 150, 100, "planet_1.png");
    NatureObj rock1(800, 500, 25, 20, "rock1.png");
    NatureObj rock2(500, 550, 20, 20, "rock2.png");
    NatureObj rock3(300, 470, 25, 25, "rock3.png");
    NatureObj rock4(1000, 600, 25, 25, "rock3.png");
    NatureObj rock5(1100, 450, 20, 20, "rock2.png");
    NatureObj rock6(700, 575, 25, 25, "rock2.png");
    NatureObj rock7(600, 460, 20, 25, "rock1.png");
    NatureObj rock8(950, 560, 20, 22, "rock2.png");
    Star star(100.f,100.f, 7);
    Star star1(500.f,300.f, 4);
    Star star2(700.f,200.f, 5);
    Star star3(600.f,250.f, 8);
    Star star4(954.f,346.f, 6);
    Star star5(400.f,277.f, 9);
    Smoke smoke(200.f, 400.f);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        drawBackGround("map_t.png", window);
        star.draw(window);
	star1.draw(window);
	star2.draw(window);
	star3.draw(window);
	star4.draw(window);
	star5.draw(window);
	mountains.draw(window);
	moon.draw(window);
	rock1.draw(window);
	rock2.draw(window);
	rock3.draw(window);
	rock4.draw(window);
	rock5.draw(window);
	rock6.draw(window);
	rock7.draw(window);
	rock8.draw(window);
	smoke.draw(window);
	window.display();
	
    }

    return 0;
}
