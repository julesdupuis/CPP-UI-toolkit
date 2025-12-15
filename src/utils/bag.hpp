#pragma once

#include <functional>
#include <algorithm>
#include <unordered_set>

template<class type>
class Bag{

private:
    std::unordered_set<type> content;

public:
    // add the element to the bag
    void add(const type& element);

    // remove the element from the bag
    void remove(const type& element);

    // call the function for each element of the bag
    void foreach(const std::function<void(const type& element)>& function) const;

    // get the number of elements in the bag
    int size() const;

};

template<class type>
void Bag<type>::add(const type& element){
    content.insert(element);
}

template<class type>
void Bag<type>::remove(const type& element){
    content.erase(element);
}

template<class type>
void Bag<type>::foreach(const std::function<void(const type&)>& function) const{
    std::for_each(content.cbegin(), content.cend(), function);
}

template<class type>
int Bag<type>::size() const{
    return content.size();
}