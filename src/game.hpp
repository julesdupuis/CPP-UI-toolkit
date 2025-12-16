#pragma once

#include "event/eventDispatcher.hpp"
#include "player.hpp"
#include <raylib.h>
#include <string>

#if defined(PLATFORM_DESKTOP)
    #define GLSL_VERSION            330
#else   // PLATFORM_ANDROID, PLATFORM_WEB -> Not supported at this moment
    #define GLSL_VERSION            100
#endif

class Game{

private:
    EventDispatcher dispatcher;

    Camera camera;
    float runTime;

    Player player;
    PlayerListener PlayerListener;

public:
    // Game();
    Game(int screenWidth = 800, int screenHeight = 450, std::string windowTitle = "");
    ~Game();

    void run();

};