#include "window.hpp"
#include "../utils/globalAccessor.hpp"
#include "../event/inputListener.hpp"

Window::Window(LayoutManager& layoutManager):
Panel(layoutManager){
    GlobalAccessor<EventDispatcher>::create(dispatcher);

    // default size
    Vector2 size = {800, 450};
    setSize(size);
    InitWindow(size.x, size.y, title.c_str());

    SetTargetFPS(60);

    SetWindowState(FLAG_WINDOW_RESIZABLE);
}

Window::~Window(){
    CloseWindow();
}

void Window::setTitle(std::string title){
    this->title = title;
    SetWindowTitle(title.c_str());
}

void Window::run(){
    fit();
    setSize({static_cast<float>(GetScreenWidth()), static_cast<float>(GetScreenHeight())});
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

void Window::draw() const{
    ClearBackground(getBackgroundColor());
    Container::draw();
}

void Window::toStr(std::ostream& stream) const{
    stream<<"Window : ";
    Container::toStr(stream);
}