#pragma once

#include <cppunit/TestFixture.h>
#include <cppunit/TestSuite.h>
#include <cppunit/extensions/HelperMacros.h>
#include "../src/utils/bag.hpp"
#include "dummyClass.hpp"

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

template class Bag<Dummyclass>;