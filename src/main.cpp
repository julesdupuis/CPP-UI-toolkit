#include "game.hpp"
#include "raylib.h"

int main(void){
    Game game;

    // Main game loop
    // Detect window close button or ESC key
    while (!WindowShouldClose()){
        game.run();
    }

    return 0;
}
