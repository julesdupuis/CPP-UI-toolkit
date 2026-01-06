#include "window.hpp"
#include "../utils/singleton.hpp"
#include "../event/inputListener.hpp"
#include <raylib.h>

Window::Window(LayoutManager& layoutManager):
Panel(layoutManager){
    Singleton<EventDispatcher>::create(dispatcher);

    // default size
    setSize({800, 450});
}

Window::~Window(){
    CloseWindow();
}

void Window::setTitle(std::string title){
    this->title = title;
}

void Window::init(){
    Vector2 size = getSize();
    InitWindow(size.x, size.y, title.c_str());

    SetTargetFPS(60);

    SetWindowState(FLAG_WINDOW_RESIZABLE);

    layout();

    InputListener resizeListener(
        [](){return IsWindowResized();},
        [this](){
            setSize({static_cast<float>(GetScreenWidth()), static_cast<float>(GetScreenHeight())});
            layout();
        }
    );

    // Main game loop
    // Detect window close button or ESC key
    while(!WindowShouldClose()){
        // user input
        dispatcher.dispatch();

        // drawing
        BeginDrawing();
            draw();
        EndDrawing();
    }

}