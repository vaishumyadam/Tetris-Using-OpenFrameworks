//
//  Board.hpp
//  fantastic-finale-vmyadam2
//
//  Created by Vaishnavi Myadam on 11/17/19.
//

#ifndef Board_hpp
#define Board_hpp
#include "ofMain.h"
#include "Block.hpp"
#include <stdio.h>
#include "Tetromino.hpp"
#include "Pieces.hpp"

class Board {
public:
    static const int kBoardLength = 20;
    static vector<vector<Block>> current_board_;

    static void init();
    ~Board(); // TODO: Do I have to do this one?
    
    static void draw();
    static void DeleteLine(int length_size, int width_size);
    bool IsLineFilled(int length_index, int width_size);
    void AllBlocksMoveDown(int length_index, int width_size);
};

#endif /* Board_hpp */
