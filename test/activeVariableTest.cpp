#include "activeVariableTest.hpp"
#include "dummyClass.hpp"
#include <cppunit/TestAssert.h>

void ActiveVariableTest::testIntInit(){
    ActiveVariable<int> activeInt(6);
    CPPUNIT_ASSERT_EQUAL(6, activeInt.get());
    CPPUNIT_ASSERT(6 == activeInt);
    CPPUNIT_ASSERT(activeInt == 6);

    activeInt = 5;
    CPPUNIT_ASSERT_EQUAL(5, activeInt.get());
    CPPUNIT_ASSERT(5 == activeInt);
    CPPUNIT_ASSERT(activeInt == 5);
}

void ActiveVariableTest::testDummyInit(){
    ActiveVariable<Dummyclass> activeDummy(Dummyclass("hello"));
    CPPUNIT_ASSERT_EQUAL(Dummyclass("hello"), activeDummy.get());
    CPPUNIT_ASSERT(Dummyclass("hello") == activeDummy);
    CPPUNIT_ASSERT(activeDummy == Dummyclass("hello"));

    activeDummy = Dummyclass("ABABA");
    CPPUNIT_ASSERT_EQUAL(Dummyclass("ABABA"), activeDummy.get());
    CPPUNIT_ASSERT(Dummyclass("ABABA") == activeDummy);
    CPPUNIT_ASSERT(activeDummy == Dummyclass("ABABA"));
}