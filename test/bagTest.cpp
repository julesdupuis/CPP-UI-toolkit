#include "bagTest.hpp"
#include <cppunit/TestAssert.h>

void BagTest::testInit(){
    Bag<int> bagA({5,7,74,12});
    Bag<int> bagB({5,7,74,12});
    CPPUNIT_ASSERT(&bagA != &bagB);
    CPPUNIT_ASSERT_EQUAL(bagA, bagB);
    
    Bag<int> bagC({5,7,74,12, 34});
    CPPUNIT_ASSERT(!(bagA == bagC));
}

void BagTest::testAdd(){
    Bag<int> bagInt;

    bagInt.add(12);
    bagInt.add(16);
    bagInt.add(13);
    CPPUNIT_ASSERT_EQUAL(3, bagInt.size());

    Bag<int> bagExpect({12, 16, 13});
    CPPUNIT_ASSERT_EQUAL(bagExpect, bagInt);
}

void BagTest::testRemove(){
    Bag<int> bagInt({26, 27});

    bagInt.remove(27);
    CPPUNIT_ASSERT_EQUAL(1, bagInt.size());

    Bag<int> bagExpect({26});
    CPPUNIT_ASSERT_EQUAL(bagExpect, bagInt);
}

void BagTest::testForeach(){
    Bag<int> bagInt({92, 63, 5});

    int count = 0;
    bagInt.foreach([&count](int i){
        count += i;
    });
    CPPUNIT_ASSERT_EQUAL(160, count);
}