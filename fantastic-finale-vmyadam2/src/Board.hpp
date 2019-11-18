//
//  Board.hpp
//  fantastic-finale-vmyadam2
//
//  Created by Vaishnavi Myadam on 11/17/19.
//

#ifndef Board_hpp
#define Board_hpp
#include "ofMain.h"
#include <stdio.h>

#endif /* Board_hpp */

class Board {
    static const int kHorizontalGridLength;
    static const int kVerticalGridLength;
    static vector<vector<Block>> current_grid_;

    static void init(int horizontal_length, int vertical_length);
    ~Board(); // TODO: How to do this one
    
    static void draw();
    static void DeleteLine(int rows, int cols);
}
