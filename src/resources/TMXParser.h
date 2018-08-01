#ifndef TMX_PARSER_H
#define TMX_PARSER_H

#include <string>

#include <pugixml.hpp>

#include "../gameLogic/GameState.h"

class TMXParser
{
    public: 
        static void parseTMXFile(std::string xmlFilePath);
    private:
        static const std::string debugID;

        static TileMap loadTileMap(pugi::xml_node root);
        static std::unordered_map<int, Tile> loadTileSet
            (pugi::xml_node root, int tileWidth, int tileHeight);
        static void loadObjects(pugi::xml_node root, 
                int mapWidth, int mapHeight, 
                int tileWidth, int tileHeight);
};

#endif
