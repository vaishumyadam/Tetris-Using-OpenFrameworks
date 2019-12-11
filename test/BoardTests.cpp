//
//  BoardTests.cpp
//  fantastic-finale-tests-vmyadam2 copy
//
//  Created by Vaishnavi Myadam on 12/7/19.
//

#include <stdio.h>
#include "catch.hpp"
#include "Board.hpp"

TEST_CASE("Is line filled method when line is empty") {
    int row_size = 12;
    int col_size = 20;
    int bottom_row_index = 0;
    
    Board test_board;
    Board::init(row_size, col_size);
    REQUIRE_FALSE(test_board.IsLineFilled(bottom_row_index, col_size));
}

TEST_CASE("Is line filled method when line is full") {
    int row_size = 12;
    int col_size = 20;
    int bottom_row_index = 0;
    ofColor not_background_color(254, 250, 254); // baby powder
    
    Board test_board;
    Board::init(12, 20);

    for(int block_index = 0; block_index < col_size; block_index++) {
        Board::blocks[block_index][bottom_row_index].SetShade(not_background_color);
    }
    REQUIRE(test_board.IsLineFilled(bottom_row_index, col_size));
}

TEST_CASE("Testing bottom line deleted properly") {
    int row_size = 12;
    int col_size = 20;
    int bottom_row_index = 0;
    ofColor not_background_color(254, 250, 254); // baby powder
    
    Board test_board;
    Board::init(12, 20);

    for(int block_index = 0; block_index < col_size; block_index++) {
        Board::blocks[block_index][bottom_row_index].SetShade(not_background_color);
    }
    test_board.DeleteLine(row_size, col_size);
    REQUIRE_FALSE(test_board.IsLineFilled(bottom_row_index, col_size));
}
