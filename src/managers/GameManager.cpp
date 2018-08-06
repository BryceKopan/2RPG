#include "GameManager.h"

#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <numeric>

#include "InputManager.h"
#include "LogicManager.h"
#include "DrawManager.h"
#include "../resources/TMXParser.h"
#include "../gameLogic/GameState.h"

#include "../util/Util.h"

bool GameManager::isRunning = true;
ALLEGRO_EVENT_QUEUE* GameManager::eventQueue;
ALLEGRO_TIMER* GameManager::timer;
ALLEGRO_DISPLAY* GameManager::display;

//TODO move
double GameManager::lastTime;
std::vector<double> GameManager::deltaFrameTimes;

void abortGame(const char* message)
{
    printf("%s \n", message);
    exit(1);
}    

void GameManager::init()
{
    if(!al_init())
        abortGame("Failed to initialize allegro");

    if(!al_init_primitives_addon())
        abortGame("Failed to initialize primitives addon");

    if(!al_init_image_addon())
        abortGame("Failed to initialize image addon");

    if(!al_init_font_addon())
        abortGame("Failed to initialize font addon");

    if(!al_init_ttf_addon())
        abortGame("Failed to initialize ttf addon");

    if(!al_install_keyboard())
        abortGame("Failed to install keyboard");

    if(!al_install_mouse())
        abortGame("Failed to install mouse");

    timer = al_create_timer(1.0 / FPS);
    if (!timer)
        abortGame("Failed to create timer");

    al_set_new_display_flags(ALLEGRO_WINDOWED);
    display = al_create_display(SCREEN_WIDTH, SCREEN_HEIGHT);
    if (!display)
        abortGame("Failed to create display"); 

    eventQueue = al_create_event_queue();
    if (!eventQueue)
        abortGame("Failed to create event queue");

    al_register_event_source(eventQueue, al_get_display_event_source(display));
    al_register_event_source(eventQueue, al_get_keyboard_event_source());
    al_register_event_source(eventQueue, al_get_mouse_event_source());
    al_register_event_source(eventQueue, al_get_timer_event_source(timer)); 

    //al_set_new_bitmap_flags(ALLEGRO_VIDEO_BITMAP);

    GameState::instance = new GameState();
}

void GameManager::loadGameData()
{
    TMXParser::parseTMXFile("res/TestMap/JacobMap.tmx");
} 

void GameManager::gameLoop()
{
    bool redraw = true;
    al_start_timer(timer);
    lastTime = Util::getPreciseSecondTime();

    while(isRunning)
    {
        ALLEGRO_EVENT event;
        al_wait_for_event(eventQueue, &event);

        if (event.type == ALLEGRO_EVENT_TIMER) 
        {
            LogicManager::update();
            redraw = true;
        }
        else if (event.type == ALLEGRO_EVENT_KEY_DOWN ||
                event.type == ALLEGRO_EVENT_KEY_UP ||
                event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN ||
                event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP ||
                event.type == ALLEGRO_EVENT_MOUSE_AXES)
        {
            InputManager::Process(event);
        }
        else if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            isRunning = false;
        }

        if (redraw && al_is_event_queue_empty(eventQueue))
        {
            updateAvgDeltaFrameTime();

            redraw = false;
            al_clear_to_color(al_map_rgb(0, 0, 0));

            DrawManager::draw();

            al_flip_display();
        }
    }
}

void GameManager::shutdown()
{
    if (timer)
        al_destroy_timer(timer);

    if (display)
        al_destroy_display(display);

    if (eventQueue)
        al_destroy_event_queue(eventQueue);
}

void GameManager::updateAvgDeltaFrameTime()
{
    GameState* gameState = GameState::instance;

    double currentTime = Util::getPreciseSecondTime();

    deltaFrameTimes.push_back(currentTime - lastTime);
    lastTime = currentTime;

    if(deltaFrameTimes.size() > 10)
        deltaFrameTimes.erase(deltaFrameTimes.begin());

    gameState->avgDeltaFrameTime = 
        std::accumulate(deltaFrameTimes.begin(), 
                deltaFrameTimes.end(), 0.0) / deltaFrameTimes.size();
}
