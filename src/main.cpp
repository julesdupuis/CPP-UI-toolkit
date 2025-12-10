#include "raylib.h"

#include <cstdio>
#include <string>

#if defined(PLATFORM_DESKTOP)
    #define GLSL_VERSION            330
#else   // PLATFORM_ANDROID, PLATFORM_WEB -> Not supported at this moment
    #define GLSL_VERSION            100
#endif

int main(void){
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Signed distance fields model visualizer");
    
    // Set our game to run at 60 frames-per-second
    SetTargetFPS(60);
    
    // Limit cursor to relative movement inside the window
    DisableCursor();

    SetWindowState(FLAG_WINDOW_RESIZABLE);

    Camera camera = { {0} };
    camera.position = (Vector3){ 2.5f, 2.5f, 3.0f };    // Camera position
    camera.target = (Vector3){ 0.0f, 0.0f, 0.7f };      // Camera looking at point
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 65.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;             // Camera projection type

    // Load raymarching shader
    // NOTE: Defining 0 (NULL) for vertex shader forces usage of internal default vertex shader
    std::string currentFilePath = "raymarching.fs";
    Shader shader = LoadShader(0, TextFormat((const char*)currentFilePath.data(), GLSL_VERSION));
    long fileModTime = GetFileModTime(currentFilePath.data());

    // Get shader locations for required uniforms
    int viewEyeLoc = GetShaderLocation(shader, "viewEye");
    int viewCenterLoc = GetShaderLocation(shader, "viewCenter");
    int runTimeLoc = GetShaderLocation(shader, "runTime");
    int resolutionLoc = GetShaderLocation(shader, "resolution");

    float resolution[2] = { (float)screenWidth, (float)screenHeight };
    SetShaderValue(shader, resolutionLoc, resolution, SHADER_UNIFORM_VEC2);

    float runTime = 0.0f;
    char *runTimeText = new char[20];

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // user input
        if (IsKeyDown(KEY_SPACE)) {
            camera.position.y += 10 * GetFrameTime();
        }
        if (IsKeyDown(KEY_LEFT_CONTROL)) {
            camera.position.y -= 10 * GetFrameTime();
        }

        // Update
        if (GetFileModTime(currentFilePath.data()) > fileModTime) {
            fileModTime = GetFileModTime(currentFilePath.data());
            shader = LoadShader(0, TextFormat((const char*)currentFilePath.data(), GLSL_VERSION));
        }

        float deltaTime = GetFrameTime();
        runTime += deltaTime;

        UpdateCamera(&camera, CAMERA_THIRD_PERSON);

        float cameraPos[3] = { camera.position.x, camera.position.y, camera.position.z };
        float cameraTarget[3] = { camera.target.x, camera.target.y, camera.target.z };

        // Set shader required uniform values
        SetShaderValue(shader, viewEyeLoc, cameraPos, SHADER_UNIFORM_VEC3);
        SetShaderValue(shader, viewCenterLoc, cameraTarget, SHADER_UNIFORM_VEC3);
        SetShaderValue(shader, runTimeLoc, &runTime, SHADER_UNIFORM_FLOAT);

        // Check if screen is resized
        if (IsWindowResized())
        {
            resolution[0] = (float)GetScreenWidth();
            resolution[1] = (float)GetScreenHeight();
            SetShaderValue(shader, resolutionLoc, resolution, SHADER_UNIFORM_VEC2);
        }

        // Draw
        BeginDrawing();

            ClearBackground(DARKGRAY);

            // We only draw a white full-screen rectangle,
            // frame is generated in shader using raymarching
            BeginShaderMode(shader);
                DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), WHITE);
            EndShaderMode();

            sprintf(runTimeText,"%f",runTime);
            DrawText(runTimeText,10,10,10,BLACK);

        EndDrawing();
    }

    // De-Initialization
    delete [] runTimeText;

    UnloadShader(shader);           // Unload shader
    CloseWindow();        // Close window and OpenGL context

    return 0;
}
