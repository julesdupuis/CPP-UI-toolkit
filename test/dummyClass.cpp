#include "dummyClass.hpp"

std::ostream& operator<<(std::ostream& stream, const Dummyclass& dummy){
    return stream << dummy.getName();
}