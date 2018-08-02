#include "TMXParser.h"

#include "../gameLogic/gameObject/NPC.h"
#include "../managers/ResourceManager.h"

#include "../core/characters/displacer/DisplacerBeast.h"

const std::string TMXParser::debugID = "[TMXParser] ";

void TMXParser::parseTMXFile(std::string xmlFilePath)
{

    //Load XML Doc
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(xmlFilePath.c_str());

    printf("%sDocument loading - %s\n", debugID.c_str(), result.description());

    pugi::xml_node root = doc.document_element();

    //Load TileMap
    TileMap tileMap = loadTileMap(root);

    //Load TileSet
    tileMap.tileSet = loadTileSet(root, 
            tileMap.tileWidth, tileMap.tileHeight);

    //Load Objects
    loadObjects(root, tileMap.mapWidth, tileMap.mapHeight, 
            tileMap.tileWidth, tileMap.tileHeight);

    GameState* gameState = GameState::instance;
    gameState->tileMap = tileMap;
    printf("%sTMX parsing finished\n", debugID.c_str());
}

TileMap TMXParser::loadTileMap(pugi::xml_node root)
{
    //Loading Map Meta Data
    int mapWidth = root.attribute("width").as_int();
    int mapHeight = root.attribute("height").as_int();
    int tileWidth = root.attribute("tilewidth").as_int();
    int tileHeight = root.attribute("tileheight").as_int();

    if(tileWidth != tileHeight)
    {
        printf("%sWarning: Tiles aren't square\n", debugID.c_str());
    }

    printf("%sLoading %d x %d map\n", debugID.c_str(), 
            mapWidth, mapHeight);

    TileMap tileMap(mapWidth, mapHeight, tileWidth, tileHeight);

    //Loading Map Data
    pugi::xml_node currentNode = root.child("layer").child("data").child("tile");

    int t;

    for(int y = 0; y < tileMap.mapHeight; y++)
    {
        for(int x = 0; x < tileMap.mapWidth; x++)
        {
            t = currentNode.attribute("gid").as_int();

            if(t == 0)//All empty spots are set to tile 0
            {
                printf("%sWarning: Map has empty tile\n", 
                        debugID.c_str()); 
            }
            
            tileMap.map[x][y] = t;

            currentNode = currentNode.next_sibling();
        }
    }

    return tileMap;
}

std::unordered_map<int, Tile> TMXParser::loadTileSet(
        pugi::xml_node root, int tileWidth, int tileHeight)
{
    std::unordered_map<int, Tile> tileSet;

    pugi::xml_node currentNode = root.child("tileset");

    while(std::string(currentNode.name()) == "tileset")
    {
        int firstID = currentNode.attribute("firstgid").as_int();
        std::string tileSetFilePath = "res/TestMap/";
        tileSetFilePath += currentNode.attribute("source").value();

        pugi::xml_document doc;
        pugi::xml_parse_result result = doc.load_file(
                tileSetFilePath.c_str());

        printf("%sDocument loading - %s\n", 
                debugID.c_str(), result.description());

        pugi::xml_node root = doc.document_element();

        int columns = root.attribute("columns").as_int();
        int tileCount = root.attribute("tilecount").as_int();
        std::string pngFilePath = "res/TestMap/";
        pngFilePath += root.first_child().attribute("source").value();

        for(int i = 0; i < tileCount; i++)
        {
            int tileID = i + firstID;
            int spriteX = (i % columns) * tileWidth;
            int spriteY = (i / columns) * tileHeight;

            Sprite sprite(pngFilePath, Point(spriteX, spriteY),
                    tileWidth, tileHeight);
            Tile tile(false, sprite);
            tileSet[tileID] = tile;
        }

        currentNode = currentNode.next_sibling();
    }

    return tileSet;
}

void TMXParser::loadObjects(pugi::xml_node root, 
        int mapWidth, int mapHeight, int tileWidth, int tileHeight)
{
    GameState* gameState = GameState::instance;
    
    Sprite sprite = Sprite("res/dungeon1.png", Point(96, 192), 32, 32);
    Point location = Point(90, 90); 
    gameState->player = new DisplacerBeast(location, sprite);
    gameState->aliveObjects.push_back(gameState->player);
    /*Sprite sprite;
      Point location;

      int t;
      pugi::xml_node currentNode = root.child("layer").next_sibling().child("data").child("tile");
      for(int y = 0; y < mapHeight; y++)
      {
      for(int x = 0; x < mapWidth; x++)
      {
      t = currentNode.attribute("gid").as_int();

      switch(t)
      {
      case 0:
      break;

      case 64:
      sprite = Sprite("res/dungeon1.png", Point(96, 192), 32, 32);
      location = Point(x * tileWidth + 16, y * tileHeight + 16); 
      gameState->player = new DisplacerBeast(location, sprite);
      gameState->aliveObjects.push_back(gameState->player);
      break;

      case 63:
      sprite = Sprite("res/dungeon1.png", Point(64, 192), 32, 32);
      location = Point(x * tileWidth + 16, y * tileHeight + 16); 
      gameState->aliveObjects.push_back(new NPC(location, true, sprite, 100, 100)); 
      break;    

defualt:
printf("%sLogic object: %i has not been implemented\n", debugID.c_str(), t); 
break;
}

currentNode = currentNode.next_sibling();
}
}*/ 
    }
