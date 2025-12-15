#pragma once
#include <cppunit/TestFixture.h>
#include <cppunit/TestSuite.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cstddef>
#include <functional>
#include <ostream>
#include <string>
#include "../src/utils/bag.hpp"


class BagTest : public CppUnit::TestFixture{
CPPUNIT_TEST_SUITE(BagTest);
    CPPUNIT_TEST(testIntInit);
    CPPUNIT_TEST(testIntAdd);
    CPPUNIT_TEST(testIntRemove);
    CPPUNIT_TEST(testIntForeach);

    CPPUNIT_TEST(testDummyInit);
    CPPUNIT_TEST(testDummyAdd);
    CPPUNIT_TEST(testDummyRemove);
    CPPUNIT_TEST(testDummyForeach);
CPPUNIT_TEST_SUITE_END();

public:
    void testIntInit();
    void testIntAdd();
    void testIntRemove();
    void testIntForeach();

    void testDummyInit();
    void testDummyAdd();
    void testDummyRemove();
    void testDummyForeach();

};
CPPUNIT_TEST_SUITE_REGISTRATION(BagTest);

template class Bag<int>;

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

template class Bag<Dummyclass>;