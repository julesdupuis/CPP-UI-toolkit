#pragma once

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "../src/event/activeVariable.hpp"
#include "dummyClass.hpp"

class ActiveVariableTest : public CppUnit::TestFixture{
CPPUNIT_TEST_SUITE(ActiveVariableTest);
    CPPUNIT_TEST(testIntInit);
    CPPUNIT_TEST(testDummyInit);
CPPUNIT_TEST_SUITE_END();

public:
    void testIntInit();
    void testDummyInit();

};
CPPUNIT_TEST_SUITE_REGISTRATION(ActiveVariableTest);

template class ActiveVariable<int>;

template class ActiveVariable<Dummyclass>;