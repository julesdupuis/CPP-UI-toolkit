#pragma once

#include <stdexcept>

// class to provide global access to an object
template<class type>
class GlobalAccessor{

private:
    static type* object;
    static bool initialised;
    GlobalAccessor();

public:
    static void create(type& object);
    static type& instance();

};

template<class type>
bool GlobalAccessor<type>::initialised = false;

template<class type>
type* GlobalAccessor<type>::object = nullptr;

template<class type>
GlobalAccessor<type>::GlobalAccessor(){
    // hidden constructor
}

template<class type>
void GlobalAccessor<type>::create(type& object){
    if(!initialised){
        GlobalAccessor<type>::object = &object;
        GlobalAccessor<type>::initialised = true;
    }
}

template<class type>
type& GlobalAccessor<type>::instance(){
    if(!initialised){
        throw std::logic_error("GlobalAccessor must be initialised");
    }
    return *object;
}