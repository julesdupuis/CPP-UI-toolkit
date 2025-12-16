#include "game.hpp"
#include <raylib.h>
#include <string>

Game::Game(int screenWidth, int screenHeight, std::string windowTitle)
:screenWidth(screenWidth),screenHeight(screenHeight){
    InitWindow(screenWidth, screenHeight, windowTitle.c_str());

    SetTargetFPS(60);

    SetWindowState(FLAG_WINDOW_RESIZABLE);

    camera.position = (Vector3){ 2.5f, 2.5f, 3.0f };    // Camera position
    camera.target = (Vector3){ 0.0f, 0.0f, 0.7f };      // Camera looking at point
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 65.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;             // Camera projection type

    runTime = 0;
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

    EndDrawing();
}