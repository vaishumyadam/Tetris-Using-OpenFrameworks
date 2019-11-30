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
    
    void Change(vector<Block> changed_blocks);
    void SlideDown(vector<Block> tetromino);
    
    vector<Block> ShiftLeft();
    vector<Block> ShiftRight();
    vector<Block> ShiftDown();
    
    vector<Block> RotateClockwise();
    vector<Block> RotateCounterClockwise();
    
    bool isTouchingLeft(vector<Block> blocks);
    bool isTouchingRight(vector<Block> blocks);
    bool isTouchingBottom(vector<Block> blocks);
};

#endif /* Tetromino_hpp */
