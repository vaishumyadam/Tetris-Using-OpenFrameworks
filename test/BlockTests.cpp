//
//  BlockTests.cpp
//  fantastic-finale-tests-vmyadam2 copy
//
//  Created by Vaishnavi Myadam on 12/2/19.
//

#include <stdio.h>
#include "catch.hpp"
#include "Block.hpp"

TEST_CASE("Testing block constructor x coordinate") {
    Block block(ofPoint(0,0), ofColor::white, ofColor::black);
    REQUIRE(block.GetX() == 0);
}

TEST_CASE("Testing block constructor y coordinate") {
    Block block(ofPoint(0,0), ofColor::white, ofColor::black);
    REQUIRE(block.GetY() == 0);
}

TEST_CASE("Testing block constructor shade") {
    Block block(ofPoint(0,0), ofColor::white, ofColor::black);
    REQUIRE(block.GetShade() == ofColor::white);
}

TEST_CASE("Testing block constructor x border") {
    Block block(ofPoint(0,0), ofColor::white, ofColor::black);
    REQUIRE(block.GetBorder() == ofColor::black);
}
