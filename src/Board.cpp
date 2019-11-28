//
//  Board.cpp
//  fantastic-finale-vmyadam2
//
//  Created by Vaishnavi Myadam on 11/17/19.
//

#include "Board.hpp"

vector<vector<Block>> Board::blocks;
const int Board::kBoardHeight = 500;
const int Board::kBoardWidth = 500;

void Board::init(int row_size, int column_size) {
    int row_index = 0;
    int col_index = 0;

    while(col_index < column_size) {
        vector<Block> horizontal_blocks;
        while(row_index < row_size) {
        horizontal_blocks.push_back(Block(ofPoint(col_index * Block::kBlockWidth, row_index * Block::kBlockHeight), ofColor::pink));
            row_index++;
        }
        blocks.push_back(horizontal_blocks);
        col_index++;
    }
}

void Board::draw() {
    for(int col_index = 0; col_index < blocks.size(); col_index++) {
        for(int row_index = 0; row_index < blocks[col_index].size(); row_index++) {
            blocks[col_index][row_index].draw();
        }
    }
}

bool Board::IsLineFilled(int length_index, int width_size) {
    bool has_tetromino = true;
    for(int width_index = 0; width_index < width_size; width_index++) {
        if(blocks[width_index][length_index].GetShade() == ofColor::pink) {
            has_tetromino = false;
        }
    }
    return has_tetromino;
}

void Board::AllBlocksMoveDown(int length_index, int width_size) {
    for(int current_length_index = length_index; current_length_index > -1; current_length_index--) {
        for(int width_index = 0; width_index < width_size; width_index++) {
            if(current_length_index < 1) {
                blocks[width_index][0].SetShade(ofColor::pink);
            } else {
                blocks[width_index][current_length_index].SetShade(blocks[width_index][current_length_index - 1].GetShade());
            }
        }
    }
}

// renamed because I was getting confused
void Board::DeleteLine(int row_size, int column_size) {
    // Iterating backwards because we are deleting lines from the bottom
    for(int row_index = row_size - 1; row_index > -1; row_index--) {
        if(Board::IsLineFilled(row_index, column_size)) {
            Board::AllBlocksMoveDown(row_index, column_size);
            row_index++; // Because we are deleting a line (skips twice)
        }
    }
}
