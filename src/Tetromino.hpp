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
    vector<Block> current_tetromino_; //name
    
    void draw();
    void SlideDown(vector<Block> tetromino);
    
    vector<Block> ShiftLeft();
    vector<Block> ShiftRight();
    vector<Block> ShiftDown();
    
    vector<Block> RotateClockwise();
    vector<Block> RotateCounterClockwise();
};

#endif /* Tetromino_hpp */
