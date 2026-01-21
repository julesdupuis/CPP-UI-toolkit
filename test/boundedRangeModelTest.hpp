#pragma once

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

class BoundedRangeModelTest : public CppUnit::TestFixture{
CPPUNIT_TEST_SUITE(BoundedRangeModelTest);
    CPPUNIT_TEST(testSetters);
    CPPUNIT_TEST(testRatioNegative);
    CPPUNIT_TEST(testRatioPositive);
    CPPUNIT_TEST(testRatioMix);
CPPUNIT_TEST_SUITE_END();

public:
    void testSetters();
    void testRatioNegative();
    void testRatioPositive();
    void testRatioMix();

};
CPPUNIT_TEST_SUITE_REGISTRATION(BoundedRangeModelTest);