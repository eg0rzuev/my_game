//
//

/*
 * header with all required libraries
 */

#ifndef MY_GAME_MAIN_HEADER_H
#define MY_GAME_MAIN_HEADER_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <ctime>

enum map_params
{
    MAP_HEIGTH = 21,
    MAP_WIDTH  = 40,
    SQUARE_SIZE = 30
};

const sf::String mapTile[MAP_HEIGTH] ={
        " rrrrrrrrrrrrr                          ",
        "  brrrrrrrrb       r           r        ",
        "    brrrrrrrrrb             r           ",
        "       brrrrrrrb                        ",
        "  r       brrrrrrrrrrrrb         r      ",
        "              brrrrrrrb                 ",
        "                  brrrrrb               ",
        "     r           brrrrrrrb           r  ",
        "                   bbrrrrrrbb           ",
        "        r       b    bbrrrrrrr          ",
        "            r             brrrrrb       ",
        "                             brrrrr     ",
        "         r                     brrrrr   ",
        "                                 brrrbb ",
        "ppmmmmmppppppppppppppppppppppppppppppppp",
        "pppppppppppppppppppppppppmmmmmmmpppppppp",
        "ppppmmmmmmmmmmpppppppppppppppppppppmpppp",
        "pppppppppppppppppppppppppmpmmmmmpppppppp",
        "pppppppppppppmmmmmmmmmmmmpmppppppppppppp",
        "pppppppppppppppppppppppppppppppppppppppp",
        "pppmmmmmmmmpmppppppppppppppppppppppppppp"
};

void drawBackGround(const std::string& pathToTexture, sf::RenderWindow& window);

#endif //MY_GAME_MAIN_HEADER_H
