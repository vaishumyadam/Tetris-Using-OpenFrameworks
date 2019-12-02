//
//  Tetromino.cpp
//  fantastic-finale-vmyadam2
//
//  Created by Vaishnavi Myadam on 11/17/19.
//

// Work on this one

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
    num_slide_down = 0;
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
}

void Tetromino::SlideDown(vector<Block> new_blocks) {
    blocks = new_blocks;
    num_slide_down++;
}

void Tetromino::SetTetromino(vector<Block> changed_tetromino) {
    blocks = changed_tetromino;
}

vector<Block> Tetromino::ShiftLeft() {
    vector<Block> changed_tetromino = blocks;
    
    for(int block_index = 0; block_index < blocks.size(); block_index++) {
        int to_set_x = changed_tetromino[block_index].GetX() - Block::kBlockWidth;
        changed_tetromino[block_index].SetX(to_set_x);
    }
    return changed_tetromino;
}

vector<Block> Tetromino::ShiftRight() {
    vector<Block> changed_tetromino = blocks;
    
    for(int block_index = 0; block_index < blocks.size(); block_index++) {
        // same as above method just + instead of -
        int to_set_x = changed_tetromino[block_index].GetX() + Block::kBlockWidth;
        changed_tetromino[block_index].SetX(to_set_x);
    }
    return changed_tetromino;
}

vector<Block> Tetromino::ShiftDown() {
    vector<Block> changed_tetromino = blocks;
    
    for(int block_index = 0; block_index < blocks.size(); block_index++) {
        // same as above method just y instead of x
        int to_set_y = changed_tetromino[block_index].GetY() + Block::kBlockHeight;
        changed_tetromino[block_index].SetY(to_set_y);
    }
    return changed_tetromino;
}

// Adapted from this for algorithm for both rotations: https://stackoverflow.com/questions/233850/tetris-piece-rotation-algorithm

// Doing origins separate because it would be redundant in both methods
pair<int, int> Tetromino::GetOrigins(vector<Block> changed_tetromino) {
    vector<int> x_blocks_coordinates;
    vector<int> y_blocks_coordinates;
    
    for(int block_index = 0; block_index < changed_tetromino.size(); block_index++) {
        x_blocks_coordinates.push_back(changed_tetromino[block_index].GetX());
        y_blocks_coordinates.push_back(changed_tetromino[block_index].GetY());
    }
    
    // https://www.geeksforgeeks.org/how-to-find-the-minimum-and-maximum-element-of-a-vector-using-stl-in-c/
    // Adding height width to get center of rotation
    int x_origin = *min_element(x_blocks_coordinates.begin(), x_blocks_coordinates.end()) + Block::kBlockWidth;
    int y_origin = *min_element(y_blocks_coordinates.begin(), y_blocks_coordinates.end()) + Block::kBlockHeight;
    
    return make_pair(x_origin, y_origin);
}

vector<Block> Tetromino::RotateClockwise() {
    vector<Block> changed_tetromino = blocks;
    pair<int, int> origins_pair = GetOrigins(changed_tetromino);
    int x_trans, y_trans, x_rotate, y_rotate;
    
    for(int block_index = 0; block_index < blocks.size(); block_index++) {
        
        // trans means translating coordinates in relation to origins
        x_trans = changed_tetromino[block_index].GetX() - origins_pair.first;
        y_trans = changed_tetromino[block_index].GetY() - origins_pair.second;
        
        x_rotate = y_trans;
        y_rotate = -1 * x_trans;
        
        // un-translating
        changed_tetromino[block_index].SetX(origins_pair.first + x_rotate);
        changed_tetromino[block_index].SetY(origins_pair.second + y_rotate);
    }
    return changed_tetromino;
}

vector<Block> Tetromino::RotateCounterClockwise() {
    // similar to above
    vector<Block> changed_tetromino = blocks;
    pair<int, int> origins_pair = GetOrigins(changed_tetromino);
    int x_trans, y_trans, x_rotate, y_rotate;

    for(int block_index = 0; block_index < blocks.size(); block_index++) {
        
        // trans means translating coordinates in relation to origins
        x_trans = changed_tetromino[block_index].GetX() - origins_pair.first;
        y_trans = changed_tetromino[block_index].GetY() - origins_pair.second;
        
        // these 2 lines are different from CW
        x_rotate = y_trans * -1;
        y_rotate = x_trans;
        
        // un-translating
        changed_tetromino[block_index].SetX(origins_pair.first + x_rotate);
        changed_tetromino[block_index].SetY(origins_pair.second + y_rotate);
    }
    return changed_tetromino;
}
