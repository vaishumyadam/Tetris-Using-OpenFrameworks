//
//  TetrominoTests.cpp
//  fantastic-finale-tests-vmyadam2 copy
//
//  Created by Vaishnavi Myadam on 12/2/19.
//

#include <stdio.h>
#include "catch.hpp"
#include "Tetromino.hpp"

TEST_CASE("Testing set and reset") {
    Tetromino tetromino_class;
    
    Block one(ofPoint(1,2), ofColor::white, ofColor::black);
    Block two(ofPoint(2,3), ofColor::white, ofColor::black);
    Block three(ofPoint(4,5), ofColor::white, ofColor::black);
    Block four(ofPoint(6,7), ofColor::white, ofColor::black);
    
    vector<Block> set;
    set.push_back(one);
    set.push_back(two);
    set.push_back(three);
    set.push_back(four);

    tetromino_class.SetBlocks(set);
    tetromino_class.reset();
    int one_block_size = 4;
    
    REQUIRE(tetromino_class.GetBlocks().size() == one_block_size);
}

TEST_CASE("Testing shift left x coordinates") {
    Tetromino tetromino_class;
    
    Block one(ofPoint(25,100), ofColor::white, ofColor::black);
    Block two(ofPoint(25,75), ofColor::white, ofColor::black);
    Block three(ofPoint(25,50), ofColor::white, ofColor::black);
    Block four(ofPoint(25,25), ofColor::white, ofColor::black);
    
    vector<Block> original;
    original.push_back(one);
    original.push_back(two);
    original.push_back(three);
    original.push_back(four);

    tetromino_class.SetBlocks(original);
    
    vector<Block> changed = original;
    int block_width = 25;
    
    for(int vector_index = 0; vector_index < changed.size(); vector_index++) {
        changed[vector_index].SetX(changed[vector_index].GetX() - block_width);
    }
    
    vector<Block> result = tetromino_class.ShiftLeft();
    
    for(int result_index = 0; result_index < result.size(); result_index++) {
        REQUIRE(result[result_index].GetX() == changed[result_index].GetX());
    }
}

TEST_CASE("Testing shift left y coordinates") {
    Tetromino tetromino_class;
    
    Block one(ofPoint(25,100), ofColor::white, ofColor::black);
    Block two(ofPoint(25,75), ofColor::white, ofColor::black);
    Block three(ofPoint(25,50), ofColor::white, ofColor::black);
    Block four(ofPoint(25,25), ofColor::white, ofColor::black);
    
    vector<Block> original;
    original.push_back(one);
    original.push_back(two);
    original.push_back(three);
    original.push_back(four);

    tetromino_class.SetBlocks(original);
    
    vector<Block> changed = original;
    int block_width = 25;
    
    for(int vector_index = 0; vector_index < changed.size(); vector_index++) {
        changed[vector_index].SetX(changed[vector_index].GetX() - block_width);
    }
    
    vector<Block> result = tetromino_class.ShiftLeft();
    
    for(int result_index = 0; result_index < result.size(); result_index++) {
        REQUIRE(result[result_index].GetY() == changed[result_index].GetY());
    }
}

TEST_CASE("Testing shift right x coordinates") {
    Tetromino tetromino_class;
    
    Block one(ofPoint(25,100), ofColor::white, ofColor::black);
    Block two(ofPoint(25,75), ofColor::white, ofColor::black);
    Block three(ofPoint(25,50), ofColor::white, ofColor::black);
    Block four(ofPoint(25,25), ofColor::white, ofColor::black);
    
    vector<Block> original;
    original.push_back(one);
    original.push_back(two);
    original.push_back(three);
    original.push_back(four);

    tetromino_class.SetBlocks(original);
    
    vector<Block> changed = original;
    int block_width = 25;
    
    for(int vector_index = 0; vector_index < changed.size(); vector_index++) {
        changed[vector_index].SetX(changed[vector_index].GetX() + block_width);
    }
    
    vector<Block> result = tetromino_class.ShiftRight();
    
    for(int result_index = 0; result_index < result.size(); result_index++) {
        REQUIRE(result[result_index].GetX() == changed[result_index].GetX());
    }
}

TEST_CASE("Testing shift right y coordinates") {
    Tetromino tetromino_class;
    
    Block one(ofPoint(25,100), ofColor::white, ofColor::black);
    Block two(ofPoint(25,75), ofColor::white, ofColor::black);
    Block three(ofPoint(25,50), ofColor::white, ofColor::black);
    Block four(ofPoint(25,25), ofColor::white, ofColor::black);
    
    vector<Block> original;
    original.push_back(one);
    original.push_back(two);
    original.push_back(three);
    original.push_back(four);

    tetromino_class.SetBlocks(original);
    
    vector<Block> changed = original;
    int block_width = 25;
    
    for(int vector_index = 0; vector_index < changed.size(); vector_index++) {
        changed[vector_index].SetX(changed[vector_index].GetX() - block_width);
    }
    
    vector<Block> result = tetromino_class.ShiftRight();
    
    for(int result_index = 0; result_index < result.size(); result_index++) {
        REQUIRE(result[result_index].GetY() == changed[result_index].GetY());
    }
}

TEST_CASE("Testing shift down y coordinates") {
    Tetromino tetromino_class;
    
    Block one(ofPoint(25,100), ofColor::white, ofColor::black);
    Block two(ofPoint(25,75), ofColor::white, ofColor::black);
    Block three(ofPoint(25,50), ofColor::white, ofColor::black);
    Block four(ofPoint(25,25), ofColor::white, ofColor::black);
    
    vector<Block> original;
    original.push_back(one);
    original.push_back(two);
    original.push_back(three);
    original.push_back(four);

    tetromino_class.SetBlocks(original);
    
    vector<Block> changed = original;
    int block_height = 25;
    
    for(int vector_index = 0; vector_index < changed.size(); vector_index++) {
        changed[vector_index].SetY(changed[vector_index].GetY() + block_height);
    }
    
    vector<Block> result = tetromino_class.ShiftDown();
    
    for(int result_index = 0; result_index < result.size(); result_index++) {
        REQUIRE(result[result_index].GetY() == changed[result_index].GetY());
    }
}

TEST_CASE("Testing shift down x coordinates") {
    Tetromino tetromino_class;
    
    Block one(ofPoint(25,100), ofColor::white, ofColor::black);
    Block two(ofPoint(25,75), ofColor::white, ofColor::black);
    Block three(ofPoint(25,50), ofColor::white, ofColor::black);
    Block four(ofPoint(25,25), ofColor::white, ofColor::black);
    
    vector<Block> original;
    original.push_back(one);
    original.push_back(two);
    original.push_back(three);
    original.push_back(four);

    tetromino_class.SetBlocks(original);
    
    vector<Block> changed = original;
    int block_height = 25;
    
    for(int vector_index = 0; vector_index < changed.size(); vector_index++) {
        changed[vector_index].SetY(changed[vector_index].GetY() + block_height);
    }
    
    vector<Block> result = tetromino_class.ShiftDown();
    
    for(int result_index = 0; result_index < result.size(); result_index++) {
        REQUIRE(result[result_index].GetX() == changed[result_index].GetX());
    }
}
