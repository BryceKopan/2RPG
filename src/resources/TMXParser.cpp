#include "TMXParser.h"

#include <pugixml.hpp>

#include "../core/GameState.h"
#include "../gameLogic/CONSTANTS.h"
#include "../gameLogic/gameObject/NPC.h"
#include "../managers/ResourceManager.h"

const std::string TMXParser::debugID = "[TMXParser] ";

void TMXParser::parseTMXFile(std::string xmlFilePath)
{
    GameState* gameState = GameState::instance;

    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(xmlFilePath.c_str());

    printf("%sDocument loading - %s\n", debugID.c_str(), result.description());

    pugi::xml_node root = doc.document_element();

    if(root.attribute("width").as_int() != CHUNK_SIZE || 
            root.attribute("height").as_int() != CHUNK_SIZE)
    {
        printf("%sTMX map is not 64 x 64\n", debugID.c_str());
    }

    int tileWidth = root.attribute("tilewidth").as_int();
    int tileHeight = root.attribute("tileheight").as_int();

    if(tileWidth != tileHeight)
    {
        printf("%sWarning: Tiles aren't square\n", debugID.c_str());
    }

    gameState->tileMap.tileWidth = tileWidth;
    gameState->tileMap.tileHeight = tileHeight;

    pugi::xml_node currentNode = root.child("tileset");

    int tileSetSize = currentNode.attribute("tilecount").as_int();

    currentNode = currentNode.child("image");

    std::string pngFilePath = currentNode.attribute("source").value();

    int spriteSheetWidth = currentNode.attribute("width").as_int() / 
        tileWidth;

    currentNode = currentNode.next_sibling("tile");

    bool collidable;

    for(int i = 0; i < tileSetSize; i++)
    {
        collidable = currentNode.child("properties").child("property").attribute("value").as_int();

        int spriteID = currentNode.attribute("id").as_int();
        int spriteX = (spriteID % spriteSheetWidth) * tileWidth;
        int spriteY = (spriteID / spriteSheetWidth) * tileHeight;

        Sprite sprite(
                pngFilePath, spriteX, spriteY, tileWidth, tileHeight);

        Tile tile(collidable, sprite);
        gameState->tileMap.tileSet[spriteID] = tile;

        currentNode = currentNode.next_sibling("tile");
    }

    currentNode = root.child("layer").child("data").child("tile");

    int t;

    for(int y = 0; y < CHUNK_SIZE; y++)
    {
        for(int x = 0; x < CHUNK_SIZE; x++)
        {
            t = currentNode.attribute("gid").as_int();

            if(t == 0)//All empty spots are set to tile 0
            {
                gameState->tileMap.map[x][y] = 31;
            }
            else
            {
                gameState->tileMap.map[x][y] = t - 1;
            }

            currentNode = currentNode.next_sibling();
        }
    }

    currentNode = root.child("layer").next_sibling().child("data").child("tile");

    Sprite sprite;

    for(int y = 0; y < CHUNK_SIZE; y++)
    {
        for(int x = 0; x < CHUNK_SIZE; x++)
        {
            t = currentNode.attribute("gid").as_int();

            switch(t)
            {
                case 0:
                    break;

                case 64:
                    sprite = Sprite("res/dungeon1.png", 96, 192, 32, 32);
                    gameState->player = 
                        new Player(x * tileWidth, y * tileHeight, 
                                sprite);
                    gameState->aliveObjects.push_back(gameState->player);
                    break;

                case 63:
                    sprite = Sprite("res/dungeon1.png", 64, 192, 32, 32);
                    gameState->aliveObjects.push_back(
                            new NPC(x * tileWidth, y * tileHeight, 
                                true, sprite, 100, 100)); 
                    break;    

                defualt:
                    printf("%sLogic object: %i has not been implemented\n", debugID.c_str(), t); 
                    break;
            }

            currentNode = currentNode.next_sibling();
        }
    }

    printf("%sTMX parsing finished\n", debugID.c_str());
}
