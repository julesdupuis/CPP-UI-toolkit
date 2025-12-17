#pragma once

#include "event.hpp"
#include "listener.hpp"
#include "observable.hpp"
#include <ostream>

template<class type>
class ActiveVariable : private Observable{

private:
    type variable;

public:
    ActiveVariable(type value);

    ActiveVariable<type>& operator=(const type& var);
    ActiveVariable<type>& operator=(type&& var);

    bool operator==(const ActiveVariable<type>& other) const;
    bool operator==(const type& other) const;

    friend std::ostream& operator<<(std::ostream& stream, const ActiveVariable<type>& activeVariable);

    const type& get() const;

    void addListener(Listener& listener);
    void removeListener(Listener& listener);
};

template<class type>
ActiveVariable<type>::ActiveVariable(type value):variable(value){

}

template<class type>
ActiveVariable<type>& ActiveVariable<type>::operator=(const type& var){
    if(variable == var){
        return *this;
    }
    variable = var;
    Event e;
    fireEvent(e);

    return *this;
}

template<class type>
ActiveVariable<type>& ActiveVariable<type>::operator=(type&& var){
    if(variable == var){
        return *this;
    }
    variable = var;
    Event e;
    fireEvent(e);

    return *this;
}

template<class type>
bool ActiveVariable<type>::operator==(const ActiveVariable<type>& other) const{
    return variable == other.variable;
}

template<class type>
bool ActiveVariable<type>::operator==(const type& other) const{
    return variable == other;
}

template<class type>
bool operator==(const type& left, const ActiveVariable<type>& right){
    return right == left;
}

template<class type>
std::ostream& operator<<(std::ostream& stream, const ActiveVariable<type>& activeVariable){
    stream << activeVariable.variable;
    return stream;
}

template<class type>
const type& ActiveVariable<type>::get() const{
    return variable;
}

template<class type>
void ActiveVariable<type>::addListener(Listener& listener){
    subscribe(listener);
}

template<class type>
void ActiveVariable<type>::removeListener(Listener& listener){
    unsubscribe(listener);
}