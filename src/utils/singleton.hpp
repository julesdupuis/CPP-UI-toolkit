#pragma once

#include <stdexcept>

// class to provide global access to an object
template<class type>
class Singleton{

private:
    static type* object;
    static bool initialised;
    Singleton();

public:
    static void create(type& object);
    static type& instance();

};

template<class type>
bool Singleton<type>::initialised = false;

template<class type>
type* Singleton<type>::object = nullptr;

template<class type>
Singleton<type>::Singleton(){
    // hidden constructor
}

template<class type>
void Singleton<type>::create(type& object){
    if(!initialised){
        Singleton<type>::object = &object;
        Singleton<type>::initialised = true;
    }
}

template<class type>
type& Singleton<type>::instance(){
    if(!initialised){
        throw std::logic_error("Singleton must be initialised");
    }
    return *object;
}