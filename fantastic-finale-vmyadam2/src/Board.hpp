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
    static const ofColor background_color_ = ofColor::pink;
    static const int kHorizontalBoardLength = 500;
    static const int kVerticalBoardLength = 500;
    static vector<vector<Block>> current_board_;

    static void RefreshBoard(int width_size, int length_size);
    ~Board(); // TODO: How to do this one
    static void draw();
    
    static void DeleteLine(int length_size, int width_size);
    bool IsLineFilled(int length_index, int width_size);
    void AllBlocksMoveDown(int length_index, int width_size);
};
