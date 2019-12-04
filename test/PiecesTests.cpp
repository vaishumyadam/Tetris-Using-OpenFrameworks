//
//  BoardTests.cpp
//  fantastic-finale-tests-vmyadam2 copy
//
//  Created by Vaishnavi Myadam on 12/2/19.
//

#include <stdio.h>
#include "catch.hpp"
#include "Pieces.hpp"

TEST_CASE("All pieces 2D vector initially empty") {
    Pieces empty;
    REQUIRE(empty.GetAllPieces().empty());
}

TEST_CASE("All pieces created") {
    Pieces pieces;
    pieces.CreateAllPieces();
    int num_standard_tetrominoes = 7;
    
    REQUIRE(pieces.GetAllPieces().size() == num_standard_tetrominoes);
}

TEST_CASE("Random piece returned is valid") {
    Pieces random_pieces;
    random_pieces.CreateAllPieces();
    vector<vector<ofPoint>> pieces = random_pieces.GetAllPieces();
    int standard_tetromino_size = 4;
    
    REQUIRE(random_pieces.GetRandomPiece().size() == standard_tetromino_size);
}
