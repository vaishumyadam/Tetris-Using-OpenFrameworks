//
//  Pieces.cpp
//  fantastic-finale-vmyadam2
//
//  Created by Vaishnavi Myadam on 11/18/19.
//

#include "Pieces.hpp"
// https://www.colinfahey.com/tetris/tetris_diagram_pieces_orientations_new.jpg
// Idea for coordinates of the pieces came from this (Java link): https://dzone.com/articles/creating-tetris-program-part-t
void Pieces::CreateAllPieces() {
   
    // why doesn't this have push front
    
    vector<ofPoint> O;
    vector<ofPoint> I;
    vector<ofPoint> S;
    vector<ofPoint> J;
    vector<ofPoint> L;
    vector<ofPoint> T;
    vector<ofPoint> Z;

    O.push_back(ofPoint(0, 0));
    O.push_back(ofPoint(0, Block::kBlockHeight));
    O.push_back(ofPoint(Block::kBlockWidth, 0));
    O.push_back(ofPoint(Block::kBlockWidth, Block::kBlockHeight));
    
    I.push_back(ofPoint(0, 0));
    I.push_back(ofPoint(0, Block::kBlockHeight));
    I.push_back(ofPoint(0, Block::kBlockHeight * 2));
    I.push_back(ofPoint(0, Block::kBlockHeight * 3));
    
    S.push_back(ofPoint(0, Block::kBlockHeight));
    S.push_back(ofPoint(Block::kBlockWidth, Block::kBlockHeight));
    S.push_back(ofPoint(Block::kBlockWidth, 0));
    S.push_back(ofPoint(Block::kBlockWidth * 2, 0));

    J.push_back(ofPoint(Block::kBlockWidth, 0));
    J.push_back(ofPoint(Block::kBlockWidth, Block::kBlockHeight));
    J.push_back(ofPoint(Block::kBlockWidth, Block::kBlockHeight * 2));
    J.push_back(ofPoint(0, Block::kBlockHeight * 2));

    L.push_back(ofPoint(0, 0));
    L.push_back(ofPoint(0, Block::kBlockHeight));
    L.push_back(ofPoint(0, Block::kBlockHeight * 2));
    L.push_back(ofPoint(Block::kBlockWidth, Block::kBlockHeight * 2));

    T.push_back(ofPoint(0, Block::kBlockHeight));
    T.push_back(ofPoint(Block::kBlockWidth, 0));
    T.push_back(ofPoint(Block::kBlockWidth, Block::kBlockHeight));
    T.push_back(ofPoint(Block::kBlockWidth * 2, Block::kBlockHeight));

    Z.push_back(ofPoint(0, 0));
    Z.push_back(ofPoint(Block::kBlockWidth, 0));
    Z.push_back(ofPoint(Block::kBlockWidth, Block::kBlockHeight));
    Z.push_back(ofPoint(Block::kBlockWidth * 2, Block::kBlockHeight));
    
    all_pieces.push_back(O);
    all_pieces.push_back(I);
    all_pieces.push_back(S);
    all_pieces.push_back(J);
    all_pieces.push_back(L);
    all_pieces.push_back(T);
    all_pieces.push_back(Z);
}

vector<ofPoint> Pieces::GetRandomPiece() {
    return all_pieces[(int)ofRandom(0, all_pieces.size() - 1)];
}

vector<vector<ofPoint>> Pieces::GetAllPieces() {
    return all_pieces;
}
