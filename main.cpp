
#include <iostream>
#include <vector>
#include "SpecialVector.h"
#include <cstdlib>
#include <time.h>
#include "menu.h"
//#define NORMAL_MODE
#ifdef NORMAL_MODE
using namespace std;

int main()
{

    SpecialVector b;
    b.insertElem(5);
    b.insertElem(6);
    b.insertElem(7);
    b.insertElem(8);
    b.insertElem(9);
    b.insertElem(10);
cout << b << endl;
cout << b.getRandElem() << endl;
cout << b.getRandElem() << endl;

Menu a;
a.run();
    return 0;
}

#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <vector>
#include "SpecialVector.h"


//Test cases

TEST_CASE("insertElem" , ""){
SpecialVector Test;
SpecialVector Test2;
CHECK(true == Test.isEmpty());
Test.insertElem(1);
CHECK(true == !(Test.isEmpty()));
Test.insertElem(2);
CHECK_THROWS(Test.insertElem(2));
Test.insertElem(3);
Test2.insertElem(1);
Test2.insertElem(2);
Test2.insertElem(3);
CHECK((Test == Test2));
}

TEST_CASE("remElem" , ""){
SpecialVector Test;
CHECK_THROWS(Test.remElem(1));
SpecialVector Test2;
Test.insertElem(1);
CHECK(Test.contains(1) == true);
Test.remElem(1);
CHECK_THROWS(Test.contains(1));
Test.insertElem(1);
Test.insertElem(2);
Test.insertElem(3);
Test2.insertElem(1);
Test2.insertElem(2);
Test.remElem(3);

CHECK((Test == Test2));
}


TEST_CASE("GetRandElem" , ""){
SpecialVector Test;

Test.insertElem(1);
Test.insertElem(2);
Test.insertElem(3);
Test.insertElem(4);
Test.insertElem(5);
Test.insertElem(6);
int a;
int b;
CHECK(Test.contains(a = Test.getRandElem()) == true);
time_t seed;
time(&seed);
srand(seed);
CHECK(Test.contains(b = Test.getRandElem()) == true);
CHECK(a != b);
}
TEST_CASE("isEmpty" , ""){
SpecialVector Test;
CHECK(Test.isEmpty() == true);
Test.insertElem(5);
CHECK(Test.isEmpty() == false);
Test.remElem(5);
CHECK(Test.isEmpty() == true);
}

TEST_CASE("Contains" , ""){
SpecialVector Test;
CHECK_THROWS(Test.contains(5));
Test.insertElem(5);
CHECK(Test.contains(5) == true);
Test.remElem(5);
CHECK_THROWS(Test.contains(5));
Test.insertElem(6);
CHECK(Test.contains(6) == true);
CHECK_THROWS(Test.contains(10));

}
TEST_CASE("NumbersOfEven" , ""){
SpecialVector Test;
CHECK_THROWS(Test.NumOfEven());
Test.insertElem(4);
Test.insertElem(5);
Test.insertElem(6);
CHECK(Test.NumOfEven() == 2);
Test.insertElem(8);
Test.insertElem(10);
CHECK(Test.NumOfEven() == 4);

}

#endif
