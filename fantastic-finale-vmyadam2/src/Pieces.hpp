//
//  Pieces.hpp
//  fantastic-finale-vmyadam2
//
//  Created by Vaishnavi Myadam on 11/18/19.
//
#include "ofMain.h"
#ifndef Pieces_hpp
#define Pieces_hpp

#include <stdio.h>

#endif /* Pieces_hpp */

class Pieces {
private:
    static vector<vector<ofPoint>> all_pieces;
public:
    void CreateAllPieces();
    static vector<ofPoint> GetRandomPiece();
};
