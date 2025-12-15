#include "bagTest.hpp"
#include <cppunit/TestAssert.h>


void BagTest::testAdd(){
    Bag<int> bagInt;

    bagInt.add(12);
    bagInt.add(16);
    bagInt.add(13);
    CPPUNIT_ASSERT_EQUAL(3, bagInt.size());
}

void BagTest::testRemove(){
    Bag<int> bagInt;

    bagInt.add(26);
    bagInt.add(27);

    bagInt.remove(27);
    CPPUNIT_ASSERT_EQUAL(1, bagInt.size());
}

void BagTest::testForeach(){
    Bag<int> bagInt;

    bagInt.add(92);
    bagInt.add(63);
    bagInt.add(5);

    int count = 0;
    bagInt.foreach([&count](int i){
        count += i;
    });
    CPPUNIT_ASSERT_EQUAL(160, count);
}