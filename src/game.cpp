#include "game.hpp"
#include "event/eventDispatcher.hpp"
#include "utils/singleton.hpp"

Game::Game(int screenWidth, int screenHeight, std::string windowTitle):
dispatcher(Singleton<EventDispatcher>::instance()),
playerListener(this->player),
button("test button"){
    InitWindow(screenWidth, screenHeight, windowTitle.c_str());

    SetTargetFPS(60);

    SetWindowState(FLAG_WINDOW_RESIZABLE);

    camera.position = (Vector3){ 2.5f, 2.5f, 3.0f };    // Camera position
    camera.target = (Vector3){ 0.0f, 0.0f, 0.7f };      // Camera looking at point
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 65.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;             // Camera projection type

    runTime = 0;

    button.setPos({100, 200});
    button.setSize({200, 100});
}

Game::~Game(){
    // Close window and OpenGL context
    CloseWindow();
}

void Game::run(){
    // user input
    dispatcher.dispatch();

    runTime += GetFrameTime();

    UpdateCamera(&camera, CAMERA_THIRD_PERSON);

    // Draw
    BeginDrawing();

        ClearBackground(LIGHTGRAY);
        DrawText(std::to_string(runTime).c_str(), 10, 10, 10, BLACK);

        const Vector2 playerPos = player.getPos();
        DrawCircle(playerPos.x, playerPos.y, 10, RED);
        DrawText(std::to_string(playerPos.x).c_str(), 10, 20, 10, BLACK);
        DrawText(std::to_string(playerPos.y).c_str(), 10, 30, 10, BLACK);

        button.draw();

    EndDrawing();
}