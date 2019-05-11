#include "MAIN_HEADER.h"
#include <cstdlib>
#include <ctime>
#include <string>

/* enum for easier understanding
 */
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
    sf::Image imageMap;      //important things are defined
    sf::Texture mapTexture;
    sf::Sprite map;

    imageMap.loadFromFile("images/" + textue_adr);
    mapTexture.loadFromImage(imageMap);
    map.setTexture(mapTexture);

    for (int i = 0; i < MAP_HEIGTH; i++) // iterate throught sf::String array in MAIN_HEADER.h
    for (int j = 0; j < MAP_WIDTH;  j++) // sprite is set depending on the letter in array
    {
        if(mapTile[i][j] == DARK_SPACE) map.setTextureRect(sf::IntRect(40 * 4, 0, 30, 30));
        if(mapTile[i][j] == BLUE_SPACE) map.setTextureRect(sf::IntRect(40 * 2, 0, 30, 30)); //actually 'b' and 'r' mean the same 
        if(mapTile[i][j] == RED_SPACE ) map.setTextureRect(sf::IntRect(40 * 2, 0, 30, 30));
        if(mapTile[i][j] == SURFACE_1 ) map.setTextureRect(sf::IntRect(0, 0, 30, 30));      // SURFACE_1 and SURFACE_2 too
        if(mapTile[i][j] == SURFACE_2 ) map.setTextureRect(sf::IntRect(0, 0, 30, 30));
        map.setPosition(j * 30, i * 30);						    //change position of the map so it is drawn in a right place
        window.draw(map);								    //draw sprite	
    }
}
