#include "component/button.hpp"
#include "component/window.hpp"
#include "layout/borderLayout.hpp"
#include "player.hpp"

int main(void){
    BorderLayout borderLayout;
    Window window(borderLayout);

    Player player;
    PlayerListener playerListener(player);

    float runTime = 0;

    Button button;
    button.setText("test button");
    button.fit();

    window.add(button, static_cast<int>(BorderLayout::Constraints::RIGHT));

    // TODO label, timer, slider, scrollPane
    window.init();

    // while (!WindowShouldClose()){
    //     // user input

    //     runTime += GetFrameTime();

    //     // Draw
    //     BeginDrawing();

    //         ClearBackground(LIGHTGRAY);
    //         DrawText(std::to_string(runTime).c_str(), 10, 10, 10, BLACK);

    //         const Vector2 playerPos = player.getPos();
    //         DrawCircle(playerPos.x, playerPos.y, 10, RED);
    //         DrawText(std::to_string(playerPos.x).c_str(), 10, 20, 10, BLACK);
    //         DrawText(std::to_string(playerPos.y).c_str(), 10, 30, 10, BLACK);

    //     EndDrawing();
    // }

    return 0;
}
