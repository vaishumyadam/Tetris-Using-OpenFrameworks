//
//  Board.cpp
//  fantastic-finale-vmyadam2
//
//  Created by Vaishnavi Myadam on 11/17/19.
//

#include "Board.hpp"

void Board::draw() {
    for(int col_index = 0; col_index < current_board_.size(); col_index++) {
        for(int row_index = 0; row_index < current_board_.size(); row_index++) {
            current_board_[col_index][row_index].draw();
        }
    }
}

void Board::init() {
    int width_index = 0;
    int length_index = 0;

    while(width_index < kBoardLength) {
        vector<Block> horizontal_blocks;
        while(length_index < kBoardLength) {
            Block to_push_back = Block(ofColor::pink, ofPoint(width_index * Block::kHorizontalBlockLength, length_index * Block::kVerticalBlockLength));
            horizontal_blocks.push_back(to_push_back);
            length_index++;
        }
        current_board_.push_back(horizontal_blocks);
    }
}

/*
bool Board::IsLineFilled(int length_index, int width_size) {
    bool has_tetromino = true;
    for(int width_index = 0; width_index < width_size; width_index++) {
        if(current_board[width_index][length_index] == background_color_) {
            has_tetromino = false;
        }
    }
    return has_tetromino;
}

void Board::AllBlocksMoveDown(int length_index, int width_size) {
    for(int current_length_index = length_index; current_length_index > -1; current_length_index--) {
        for(int width_index = 0; width_index < width_size; width_index++) {
            if(current_length_index < 1) {
                current_board_[width_index][0].shade = background_color_;
            } else {
                current_board_[width_index][current_length_index].shade = current_board_[width_index][current_length_index - 1].fill;
            }
        }
    }
}

void Board::DeleteLine(int length_size, int width_size) {
    // Iterating backwards because we are deleting lines from the bottom
    for(int length_index = length_size - 1; length_index > -1; length_index--) {
        if(IsLineFilled(length_index, width_size)) {
            AllBlocksMoveDown(length_index, width_size);
            length_index++; // Because we are deleting a line (skips twice)
        }
    }
}
*/
