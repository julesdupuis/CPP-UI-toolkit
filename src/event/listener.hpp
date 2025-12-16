#pragma once

#include "event.hpp"
#include <cstddef>
#include <functional>

class Listener{

public:
    virtual void onEvent(Event& e) const=0;

    virtual bool operator==(const Listener& other) const{
        return this==&other;
    }

};

namespace std {
    template<>
    struct hash<Listener>{
        size_t operator()(const Listener& listener) const{
            // a listener is hashed using it's address
            return std::hash<const Listener*>{}(&listener);
        }
    };
}