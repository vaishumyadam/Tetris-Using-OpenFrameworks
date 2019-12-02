//
//  Tetromino.hpp
//  fantastic-finale-vmyadam2
//
//  Created by Vaishnavi Myadam on 11/17/19.
//

#ifndef Tetromino_hpp
#define Tetromino_hpp
#include "ofMain.h"
#include <stdio.h>
#include "Pieces.hpp"
#include "Block.hpp"
#include "Board.hpp"
using std::vector;

class Tetromino {
public:
    int num_slide_down = 0;
    vector<Block> blocks;

    Tetromino();
    void draw();
    void reset();
    
    void SetTetromino(vector<Block> changed_blocks);
    void SlideDown(vector<Block> tetromino);
    
    vector<Block> ShiftLeft();
    vector<Block> ShiftRight();
    vector<Block> ShiftDown();
    
    pair<int, int> GetOrigins(vector<Block> changed_tetromino);

    vector<Block> RotateClockwise();
    vector<Block> RotateCounterClockwise();
};

#endif /* Tetromino_hpp */
