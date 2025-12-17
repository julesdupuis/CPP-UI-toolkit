#pragma once

#include <ostream>
#include <string>

class Dummyclass{

private:
    std::string name;

public:
    Dummyclass(std::string name):name(name){

    }

    const std::string& getName() const{
        return name;
    }

    bool operator==(const Dummyclass& other) const{
        return this->name == other.name;
    }

};

std::ostream& operator<<(std::ostream& stream, const Dummyclass& dummy);

namespace std {
    template<>
    struct hash<Dummyclass>{
        size_t operator()(const Dummyclass& object) const{
            return std::hash<std::string>{}(object.getName());
        }
    };
}