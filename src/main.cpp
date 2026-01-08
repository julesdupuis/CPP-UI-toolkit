#include "component/button.hpp"
#include "component/label.hpp"
#include "component/window.hpp"
#include "event/frameListener.hpp"
#include "layout/borderLayout.hpp"
#include "player.hpp"
#include "model/textModel.hpp"
#include <raylib.h>
#include <string>

int main(void){
    BorderLayout borderLayout;
    Window window(borderLayout);

    Player player;
    PlayerListener playerListener(player);

    float runTime = 0;
    Label runTimeLabel(TextModel(std::to_string(runTime)));
    window.add(runTimeLabel, static_cast<int>(BorderLayout::Constraints::CENTER));

    FrameListener runTimeListener([&runTime, &runTimeLabel](){
        runTime += GetFrameTime();
        runTimeLabel.getText().setText(std::to_string(runTime));
    });

    Button button;
    button.setText("test button");
    button.fit();

    window.add(button, static_cast<int>(BorderLayout::Constraints::RIGHT));

    // TODO timer, slider, scrollPane
    window.run();

    // while (!WindowShouldClose()){
    //     // Draw
    //     BeginDrawing();

    //         const Vector2 playerPos = player.getPos();
    //         DrawCircle(playerPos.x, playerPos.y, 10, RED);
    //         DrawText(std::to_string(playerPos.x).c_str(), 10, 20, 10, BLACK);
    //         DrawText(std::to_string(playerPos.y).c_str(), 10, 30, 10, BLACK);

    //     EndDrawing();
    // }

    return 0;
}
