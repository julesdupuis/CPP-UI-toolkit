#pragma once

#include "../event/observable.hpp"

class ButtonModel{

private:
    Observable actionPress;
    Observable actionRelease;
    Observable actionReleaseOutside;
    Observable actionHoverIn;
    Observable actionHoverOut;
    Observable actionPressedEntering;
    Observable actionPressedLeaving;

public:
    void subscribePress(Listener& listener);
    void unsubscribePress(Listener& listener);
    void firePressEvent() const;

    void subscribeRelease(Listener& listener);
    void unsubscribeRelease(Listener& listener);
    void fireReleaseEvent() const;

    void subscribeReleaseOutside(Listener& listener);
    void unsubscribeReleaseOutside(Listener& listener);
    void fireReleaseOutsideEvent() const;

    void subscribeHoverIn(Listener& listener);
    void unsubscribeHoverIn(Listener& listener);
    void fireHoverInEvent() const;

    void subscribeHoverOut(Listener& listener);
    void unsubscribeHoverOut(Listener& listener);
    void fireHoverOutEvent() const;

    void subscribePressedEntering(Listener& listener);
    void unsubscribePressedEntering(Listener& listener);
    void firePressedEnteringEvent() const;

    void subscribePressedLeaving(Listener& listener);
    void unsubscribePressedLeaving(Listener& listener);
    void firePressedLeavingEvent() const;

};