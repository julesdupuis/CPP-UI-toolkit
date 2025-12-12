#pragma once
#include <cppunit/TestFixture.h>
#include <cppunit/TestSuite.h>
#include <cppunit/extensions/HelperMacros.h>


class BagTest : public CppUnit::TestFixture{
CPPUNIT_TEST_SUITE(BagTest);
CPPUNIT_TEST(testAdd);
CPPUNIT_TEST(testRemove);
CPPUNIT_TEST_SUITE_END();

public:
    void testAdd();
    void testRemove();

};
CPPUNIT_TEST_SUITE_REGISTRATION(BagTest);