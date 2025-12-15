#pragma once

#include <functional>
#include <algorithm>
#include <initializer_list>
#include <ostream>
#include <unordered_set>

template<class type>
class Bag{

private:
    std::unordered_set<type> content;

public:
    Bag();
    Bag(std::initializer_list<type> elements);

    // add the element to the bag
    void add(const type& element);

    // remove the element from the bag
    void remove(const type& element);

    // call the function for each element of the bag
    void foreach(const std::function<void(const type& element)>& function) const;

    // get the number of elements in the bag
    int size() const;

    bool operator==(const Bag<type>& other) const;

};

template<class type>
Bag<type>::Bag():content(){

}

template<class type>
Bag<type>::Bag(std::initializer_list<type> elements):content(elements){

}

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

template<class type>
bool Bag<type>::operator==(const Bag<type>& other) const{
    return this->content==other.content;
}

template<class type>
std::ostream& operator<<(std::ostream& stream, const Bag<type>& bag){
    stream << "[";
    bag.foreach([&stream](const type& element){
        stream << element << " ";
    });
    stream << "]";
    return stream;
}
