#include "doctest.h"
#include "Board.hpp"
using namespace ariel;
#include <string>
using namespace std;

TEST_CASE("post") {
    Board b;
    string s="hello";
    b.post(5,5,Direction::Horizontal,s);
    CHECK(b.read(5,5,Direction::Horizontal,5)=="hello");
    b.post(0,0,Direction::Vertical,s);
    CHECK(b.read(0,0,Direction::Vertical,5)=="hello");

    s="world";
    b.post(5,5,Direction::Horizontal,s);
    CHECK(b.read(5,5,Direction::Horizontal,5)=="world");
    b.post(0,0,Direction::Vertical,s);
    CHECK(b.read(0,0,Direction::Vertical,5)=="world");

    s="abc";
    b.post(5,5,Direction::Horizontal,s);
    CHECK(b.read(5,5,Direction::Horizontal,5)=="abcld");
    b.post(0,0,Direction::Vertical,s);
    CHECK(b.read(0,0,Direction::Vertical,5)=="abcld");
    b.post(0,0,Direction::Horizontal,"w");
    CHECK(b.read(0,0,Direction::Vertical,1)=="w");
    b.post(5,4,Direction::Vertical,s);
    CHECK(b.read(5,5,Direction::Vertical,5)=="bbcld");

    b.post(10,10,Direction::Horizontal,"good");
    b.post(14,10,Direction::Horizontal,"good");
    CHECK(b.read(10,10,Direction::Horizontal,8)=="goodgood");
    b.post(10,6,Direction::Horizontal,"good");
    CHECK(b.read(10,10,Direction::Horizontal,8)=="goodgood");
}

TEST_CASE("read") {
    Board b;
    string s="hello";
    b.post(5,5,Direction::Horizontal,s);
    CHECK(b.read(5,5,Direction::Horizontal,5)=="hello");
    b.post(0,0,Direction::Vertical,s);
    CHECK(b.read(0,0,Direction::Vertical,5)=="hello");

    s="world";
    b.post(5,5,Direction::Horizontal,s);
    CHECK(b.read(5,5,Direction::Horizontal,5)=="world");
    b.post(0,0,Direction::Vertical,s);
    CHECK(b.read(0,0,Direction::Vertical,5)=="world");

    s="abc";
    b.post(5,5,Direction::Horizontal,s);
    CHECK(b.read(5,5,Direction::Horizontal,5)=="abcld");
    b.post(0,0,Direction::Vertical,s);
    CHECK(b.read(0,0,Direction::Vertical,5)=="abcld");
    b.post(0,0,Direction::Horizontal,"w");
    CHECK(b.read(0,0,Direction::Vertical,1)=="w");
    b.post(5,4,Direction::Vertical,s);
    CHECK(b.read(5,5,Direction::Vertical,5)=="bbcld");

    b.post(10,10,Direction::Horizontal,"good");
    b.post(14,10,Direction::Horizontal,"good");
    CHECK(b.read(10,10,Direction::Horizontal,8)=="goodgood");
    b.post(10,6,Direction::Horizontal,"good");
    CHECK(b.read(10,10,Direction::Horizontal,8)=="goodgood");
}
