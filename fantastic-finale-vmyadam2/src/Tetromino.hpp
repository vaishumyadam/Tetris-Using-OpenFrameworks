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

#endif /* Tetromino_hpp */

class Tetromino {
public:
    vector<Block> current_tetromino_;
    
    void draw();
    void SlideDown(vector<Block> tetromino);
    
    vector<Block> ShiftLeft();
    vector<Block> ShiftRight();
    vector<Block> ShiftDown();
    
    vector<Block> RotateClockwise();
    vector<Block> RotateCounterClockwise();
}
