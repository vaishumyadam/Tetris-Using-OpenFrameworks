//
//  Tetromino.cpp
//  fantastic-finale-vmyadam2
//
//  Created by Vaishnavi Myadam on 11/17/19.
//

#include "Tetromino.hpp"

vector<vector<ofPoint>> Pieces::all_pieces;

Tetromino::Tetromino() {
    reset();
}

void Tetromino::draw() {
    for(int block_index = 0; block_index < blocks.size(); block_index++) {
        blocks[block_index].draw();
    }
}

void Tetromino::reset() {
    blocks.clear();
    Pieces::CreateAllPieces();
    vector<ofPoint> piece = Pieces::GetRandomPiece();
    ofColor pieces_colors[7] = {
        ofColor(254, 250, 254), // baby powder
        ofColor(255, 240, 250), // floral white
        ofColor(248, 255, 248), // ghost white
        ofColor(255, 240, 255), // ivory
        ofColor(253, 230, 245), // old lace
        ofColor(255, 238, 245), // seashell
        ofColor(255, 250, 250) // snow
    };
    
    for(int piece_index = 0; piece_index < piece.size(); piece_index++) {
        blocks.push_back(Block(piece[piece_index], pieces_colors[(int) ofRandom(0, piece.size())]));
    }
    num_slide_down = 0;
}
