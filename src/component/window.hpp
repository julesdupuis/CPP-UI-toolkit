#pragma once

#include "../event/eventDispatcher.hpp"
#include "panel.hpp"
#include <string>

#if defined(PLATFORM_DESKTOP)
    #define GLSL_VERSION            330
#else   // PLATFORM_ANDROID, PLATFORM_WEB -> Not supported at this moment
    #define GLSL_VERSION            100
#endif

class Window : public Panel{

private:
    EventDispatcher dispatcher;

    std::string title;

public:
    Window(LayoutManager& layoutManager);
    ~Window();

    void setTitle(std::string title);

    void run();

    virtual void draw() const override;
    virtual void toStr(std::ostream& stream) const override;
};