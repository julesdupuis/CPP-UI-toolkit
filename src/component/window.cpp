#include "window.hpp"
#include "../utils/singleton.hpp"
#include "panel.hpp"
#include <raylib.h>

Window::Window(LayoutManager& layoutManager):
Panel(layoutManager){
    Singleton<EventDispatcher>::create(dispatcher);
}

Window::~Window(){
    CloseWindow();
}

void Window::setScreenSize(Vector2 size){
    this->size = size;
}

void Window::setTitle(std::string title){
    this->title = title;
}

void Window::init(){
    InitWindow(size.x, size.y, title.c_str());

    SetTargetFPS(60);

    SetWindowState(FLAG_WINDOW_RESIZABLE);

    while(!WindowShouldClose()){
        dispatcher.dispatch();
    }

}