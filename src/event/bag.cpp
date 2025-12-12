#include "bag.hpp"
#include <algorithm>
#include <functional>

template<class type>
void Bag<type>::add(const type& element){
    content.insert(element);
}

template<class type>
void Bag<type>::remove(const type& element){
    content.erase(element);
}

template<class type>
void Bag<type>::foreach(const std::function<void(type)>& function) const{
    std::for_each(content.cbegin(), content.cend(), function);
}