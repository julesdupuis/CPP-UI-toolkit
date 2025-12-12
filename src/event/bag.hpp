#pragma once

#include <functional>
#include <unordered_set>

template<class type>
class Bag{

private:
    std::unordered_set<type> content;

public:
    // Bag<type>();
    // ~Bag<type>();

    void add(const type& element);
    void remove(const type& element);

    void foreach(const std::function<void(type element)>& function) const;

};