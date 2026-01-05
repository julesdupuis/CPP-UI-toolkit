#pragma once

#include "../event/eventDispatcher.hpp"
#include "panel.hpp"
#include <string>

class Window : public Panel{

private:
    EventDispatcher dispatcher;

    Vector2 size = {800, 450};
    std::string title;

public:
    Window(LayoutManager& layoutManager);
    ~Window();

    void setScreenSize(Vector2 size);
    void setTitle(std::string title);

    void init();

};