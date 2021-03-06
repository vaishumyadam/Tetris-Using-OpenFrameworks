//
//  Pieces.hpp
//  fantastic-finale-vmyadam2
//
//  Created by Vaishnavi Myadam on 11/18/19.
//

#ifndef Pieces_hpp
#define Pieces_hpp
#include <stdio.h>
#include "ofMain.h"
#include "Block.hpp"

class Pieces {
 private:
    static vector<vector<ofPoint>> all_pieces;
 public:
    static void CreateAllPieces();
    static vector<vector<ofPoint>> GetAllPieces();
    static vector<ofPoint> GetRandomPiece();
};

#endif /* Pieces_hpp */
