#pragma once

#include "../event/observable.hpp"
#include <string>

class Action : public Observable{

private:
    std::string name;

public:
    std::string getName() const;
    void setName(std::string name);

};