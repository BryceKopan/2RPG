#include "managers/GameManager.h"

int main(int argc, char **argv)
{   
    GameManager::init();
    GameManager::loadGameData();
    GameManager::gameLoop();
    GameManager::shutdown();
    
    return 0;
}


