#include "MAIN_HEADER.h"
#include <cstdlib>
#include <ctime>
#include <string>

enum TEXTURE_PIECES
{
	DARK_SPACE = ' ',
	RED_SPACE  = 'r',
	BLUE_SPACE = 'b',
	SURFACE_1  = 'p',
	SURFACE_2  = 'm'
};

void drawBackGround(const std::string& textue_adr, sf::RenderWindow& window)
{
    sf::Image imageMap;
    sf::Texture mapTexture;
    sf::Sprite map;

    imageMap.loadFromFile("images/" + textue_adr);
    mapTexture.loadFromImage(imageMap);
    map.setTexture(mapTexture);

    for (int i = 0; i < MAP_HEIGTH; i++)
    for (int j = 0; j < MAP_WIDTH;  j++)
    {
        if(mapTile[i][j] == DARK_SPACE) map.setTextureRect(sf::IntRect(40 * 4, 0, 30, 30));
        if(mapTile[i][j] == BLUE_SPACE) map.setTextureRect(sf::IntRect(40 * 2, 0, 30, 30));
        if(mapTile[i][j] == RED_SPACE ) map.setTextureRect(sf::IntRect(40 * 2, 0, 30, 30));
        if(mapTile[i][j] == SURFACE_1 ) map.setTextureRect(sf::IntRect(0, 0, 30, 30));
        if(mapTile[i][j] == SURFACE_2 ) map.setTextureRect(sf::IntRect(0, 0, 30, 30));
        map.setPosition(j * 30, i * 30);
        window.draw(map);
    }
}
