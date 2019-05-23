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
#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <list>
#include <vector>
#include "objects.h"
#include "subjects.h"
#include "vector_2d.hpp"
#include "menu.h"
#include <stdio.h>
#include <string.h>
//#include "mpi.h"

/* map_params describe map sizes
 */
enum map_params
{
    MAP_HEIGTH = 21,
    MAP_WIDTH  = 40,
    SQUARE_SIZE = 30,
    GROUND_HEIGTH = 7
};

#define NEW    new   (__func__, __LINE__)

#define DELETE_BR(p)                                                                                \
    do{                                                                                             \
        fout << "Delete[] called in function " << __func__ << ", line is " << __LINE__ << " \n";    \
        delete[] p					                                       ;    \
    }while(0)	

#define DELETE(p)                                                                                 \
    do{                                                                                           \
        fout << "Delete called in function " << __func__ << ", line is " << __LINE__ << " \n";    \
        delete p					                                     ;    \
    }while(0)											   
       

/* this sf::String array describes how map look like
 * i.e. ' ' symbol is for dark space
 * 	r   is for different space texure
 * 	I'm not quite sure whether this has to be in this header file
 */

static std::ofstream fout("Log.txt");
//static std::ofstream ast_stat("asteroids.txt");

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

/* function declaration
 * description is given in textures.cpp
 */
void drawBackGround(const std::string& pathToTexture, sf::RenderWindow& window);

//operators overload in operators.cpp
void* operator new     (size_t size, const char* func, int line);
void* operator new[]   (size_t size, const char* func, int line);
void  operator delete  (void* p) noexcept;
void  operator delete[](void* p) noexcept;

#endif //MY_GAME_MAIN_HEADER_H
