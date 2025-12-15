#include "bagTest.hpp"
#include <cppunit/TestAssert.h>
#include <string>

std::ostream& operator<<(std::ostream& stream, const Dummyclass& dummy){
    return stream << dummy.getName();
}

void BagTest::testIntInit(){
    Bag<int> bagA({5,7,74,12});
    Bag<int> bagB({5,7,74,12});
    CPPUNIT_ASSERT(&bagA != &bagB);
    CPPUNIT_ASSERT_EQUAL(bagA, bagB);

    Bag<int> bagC({5,7,74,12, 34});
    CPPUNIT_ASSERT(!(bagA == bagC));
}

void BagTest::testIntAdd(){
    Bag<int> bagInt;

    bagInt.add(12);
    bagInt.add(16);
    bagInt.add(13);
    CPPUNIT_ASSERT_EQUAL(3, bagInt.size());

    Bag<int> bagExpect({12, 16, 13});
    CPPUNIT_ASSERT_EQUAL(bagExpect, bagInt);
}

void BagTest::testIntRemove(){
    Bag<int> bagInt({26, 27});

    bagInt.remove(27);
    CPPUNIT_ASSERT_EQUAL(1, bagInt.size());

    Bag<int> bagExpect({26});
    CPPUNIT_ASSERT_EQUAL(bagExpect, bagInt);
}

void BagTest::testIntForeach(){
    Bag<int> bagInt({92, 63, 5});

    int count = 0;
    bagInt.foreach([&count](int i){
        count += i;
    });
    CPPUNIT_ASSERT_EQUAL(160, count);
}

void BagTest::testDummyInit(){
    Bag<Dummyclass> bagA({Dummyclass("dummy1"), Dummyclass("dummy2")});
    Bag<Dummyclass> bagB({Dummyclass("dummy1"), Dummyclass("dummy2")});
    CPPUNIT_ASSERT(&bagA != &bagB);
    CPPUNIT_ASSERT_EQUAL(bagA, bagB);

    Bag<Dummyclass> bagC({Dummyclass("salut"), Dummyclass("hello")});
    CPPUNIT_ASSERT(!(bagA == bagC));
}

void BagTest::testDummyAdd(){
    Bag<Dummyclass> bagDummy;

    bagDummy.add(Dummyclass("hello"));
    bagDummy.add(Dummyclass("13"));
    bagDummy.add(Dummyclass("26"));
    CPPUNIT_ASSERT_EQUAL(3, bagDummy.size());

    Bag<Dummyclass> bagExpect({Dummyclass("hello"), Dummyclass("13"), Dummyclass("26")});
    CPPUNIT_ASSERT_EQUAL(bagExpect, bagDummy);
}

void BagTest::testDummyRemove(){
    Bag<Dummyclass> bagDummy({Dummyclass("26"), Dummyclass("27")});

    bagDummy.remove(Dummyclass("27"));
    CPPUNIT_ASSERT_EQUAL(1, bagDummy.size());

    Bag<Dummyclass> bagExpect({Dummyclass("26")});
    CPPUNIT_ASSERT_EQUAL(bagExpect, bagDummy);
}

void BagTest::testDummyForeach(){
    Bag<Dummyclass> bagDummy({Dummyclass("92"), Dummyclass("63"), Dummyclass("5")});

    int count = 0;
    bagDummy.foreach([&count](const Dummyclass& dummy){
        count += std::stoi(dummy.getName());
    });
    CPPUNIT_ASSERT_EQUAL(160, count);
}