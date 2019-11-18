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

// TODO: do this method
void Board::DeleteLine() {
    
}

void Board::RefreshBoard(int width_size, int length_size) {
    int width_index = 0;
    int length_index = 0;

    while(width_index < width_size) {
        vector<Block> horizontal_blocks;
        while(length_index < length_size) {
            Block to_push_back = Block(ofColor::pink, ofPoint(width_index * kHorizontalBlockLength, length_index * kVerticalBlockLength));
            horizontal_blocks.push_back(to_push_back);
            length_index++;
        }
        current_board_.push_back(horizontal_blocks);
    }
}
