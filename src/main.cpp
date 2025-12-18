#include "event/eventDispatcher.hpp"
#include "game.hpp"
#include "raylib.h"
#include "utils/singleton.hpp"

int main(void){
    EventDispatcher dispatcher;
    Singleton<EventDispatcher>::create(dispatcher);
    Game game;

    // Main game loop
    // Detect window close button or ESC key
    while (!WindowShouldClose()){
        game.run();
    }

    return 0;
}
