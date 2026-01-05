#include "component/button.hpp"
#include "component/window.hpp"
#include "layout/borderLayout.hpp"
#include "player.hpp"
#include "raylib.h"

#if defined(PLATFORM_DESKTOP)
    #define GLSL_VERSION            330
#else   // PLATFORM_ANDROID, PLATFORM_WEB -> Not supported at this moment
    #define GLSL_VERSION            100
#endif

int main(void){
    // EventDispatcher dispatcher;
    // Singleton<EventDispatcher>::create(dispatcher);

    BorderLayout borderLayout;
    Window window(borderLayout);

    Player player;
    PlayerListener playerListener(player);

    float runTime = 0;

    Button button;
    button.setPos({100, 200});
    button.setSize({200, 100});
    button.setText("test button");

    window.init();

    // Main game loop
    // Detect window close button or ESC key
    while (!WindowShouldClose()){
        // user input

        runTime += GetFrameTime();

        // Draw
        BeginDrawing();

            ClearBackground(LIGHTGRAY);
            DrawText(std::to_string(runTime).c_str(), 10, 10, 10, BLACK);

            const Vector2 playerPos = player.getPos();
            DrawCircle(playerPos.x, playerPos.y, 10, RED);
            DrawText(std::to_string(playerPos.x).c_str(), 10, 20, 10, BLACK);
            DrawText(std::to_string(playerPos.y).c_str(), 10, 30, 10, BLACK);

            // TODO label, timer

            button.draw();

        EndDrawing();
    }

    return 0;
}
