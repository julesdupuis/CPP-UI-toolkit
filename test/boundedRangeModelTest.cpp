#include "boundedRangeModelTest.hpp"
#include "../src/model/boundedRangeModel.hpp"
#include <cppunit/TestAssert.h>

void BoundedRangeModelTest::testSetters(){
    BoundedRangeModel model;

    CPPUNIT_ASSERT_EQUAL(0, model.getMinValue());
    CPPUNIT_ASSERT_EQUAL(100, model.getMaxValue());
    CPPUNIT_ASSERT_EQUAL(50, model.getCurrentValue());

    model.setMinValue(-500);
    CPPUNIT_ASSERT_EQUAL(-500, model.getMinValue());
    model.setMaxValue(-257);
    CPPUNIT_ASSERT_EQUAL(-257, model.getMaxValue());
    model.setCurrentValue(-478);
    CPPUNIT_ASSERT_EQUAL(-478, model.getCurrentValue());
}

void BoundedRangeModelTest::testRatioNegative(){
    BoundedRangeModel model;

    CPPUNIT_ASSERT_EQUAL(0.5f, model.getRatio());

    model.setMinValue(-500);
    model.setMaxValue(-100);

    model.setCurrentValue(-300);
    CPPUNIT_ASSERT_EQUAL(0.5f, model.getRatio());

    model.setCurrentValue(-400);
    CPPUNIT_ASSERT_EQUAL(0.25f, model.getRatio());

    model.setRatio(0.75f);
    CPPUNIT_ASSERT_EQUAL(-200, model.getCurrentValue());

    model.setRatio(0.9f);
    CPPUNIT_ASSERT_EQUAL(-140, model.getCurrentValue());
}

void BoundedRangeModelTest::testRatioPositive(){
    BoundedRangeModel model;

    CPPUNIT_ASSERT_EQUAL(0.5f, model.getRatio());

    model.setMinValue(100);
    model.setMaxValue(900);

    model.setCurrentValue(500);
    CPPUNIT_ASSERT_EQUAL(0.5f, model.getRatio());

    model.setCurrentValue(300);
    CPPUNIT_ASSERT_EQUAL(0.25f, model.getRatio());

    model.setCurrentValue(180);
    CPPUNIT_ASSERT_EQUAL(0.1f, model.getRatio());

    model.setRatio(0.75f);
    CPPUNIT_ASSERT_EQUAL(700, model.getCurrentValue());

    model.setRatio(0.9f);
    CPPUNIT_ASSERT_EQUAL(820, model.getCurrentValue());
}

void BoundedRangeModelTest::testRatioMix(){
    BoundedRangeModel model;

    CPPUNIT_ASSERT_EQUAL(0.5f, model.getRatio());

    model.setMinValue(-200);
    model.setMaxValue(200);

    model.setCurrentValue(0);
    CPPUNIT_ASSERT_EQUAL(0.5f, model.getRatio());

    model.setCurrentValue(-100);
    CPPUNIT_ASSERT_EQUAL(0.25f, model.getRatio());

    model.setCurrentValue(-160);
    CPPUNIT_ASSERT_EQUAL(0.1f, model.getRatio());

    model.setRatio(0.75f);
    CPPUNIT_ASSERT_EQUAL(100, model.getCurrentValue());

    model.setRatio(0.9f);
    CPPUNIT_ASSERT_EQUAL(160, model.getCurrentValue());
}