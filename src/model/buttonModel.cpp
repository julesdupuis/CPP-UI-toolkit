#include "buttonModel.hpp"

void ButtonModel::subscribePress(Listener& listener){
    actionPress.subscribe(listener);
}

void ButtonModel::unsubscribePress(Listener& listener){
    actionPress.unsubscribe(listener);
}

void ButtonModel::firePressEvent() const{
    actionPress.fireEvent();
}

void ButtonModel::subscribeRelease(Listener& listener){
    actionRelease.subscribe(listener);
}

void ButtonModel::unsubscribeRelease(Listener& listener){
    actionRelease.unsubscribe(listener);
}

void ButtonModel::fireReleaseEvent() const{
    actionRelease.fireEvent();
}

void ButtonModel::subscribeReleaseOutside(Listener& listener){
    actionReleaseOutside.subscribe(listener);
}

void ButtonModel::unsubscribeReleaseOutside(Listener& listener){
    actionReleaseOutside.unsubscribe(listener);
}

void ButtonModel::fireReleaseOutsideEvent() const{
    actionReleaseOutside.fireEvent();
}

void ButtonModel::subscribeHoverIn(Listener& listener){
    actionHoverIn.subscribe(listener);
}

void ButtonModel::unsubscribeHoverIn(Listener& listener){
    actionHoverIn.unsubscribe(listener);
}

void ButtonModel::fireHoverInEvent() const{
    actionHoverIn.fireEvent();
}

void ButtonModel::subscribeHoverOut(Listener& listener){
    actionHoverOut.subscribe(listener);
}

void ButtonModel::unsubscribeHoverOut(Listener& listener){
    actionHoverOut.unsubscribe(listener);
}

void ButtonModel::fireHoverOutEvent() const{
    actionHoverOut.fireEvent();
}

void ButtonModel::subscribePressedEntering(Listener& listener){
    actionPressedEntering.subscribe(listener);
}

void ButtonModel::unsubscribePressedEntering(Listener& listener){
    actionPressedEntering.unsubscribe(listener);
}

void ButtonModel::firePressedEnteringEvent() const{
    actionPressedEntering.fireEvent();
}

void ButtonModel::subscribePressedLeaving(Listener& listener){
    actionPressedLeaving.subscribe(listener);
}

void ButtonModel::unsubscribePressedLeaving(Listener& listener){
    actionPressedLeaving.unsubscribe(listener);
}

void ButtonModel::firePressedLeavingEvent() const{
    actionPressedLeaving.fireEvent();
}