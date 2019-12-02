#include "ofApp.h"
#include "Tetromino.hpp"
#include "Pieces.hpp"
#include "Block.hpp"
#include "Board.hpp"

int ofApp::column_size = 25;
int ofApp::row_size = 25;

//--------------------------------------------------------------
void ofApp::setup() {
    // background is yellow
    // board is pink
    // pieces colors are shades of white
    
    ofSetBackgroundColor(ofColor::yellow);
    Board::init(column_size, row_size);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
    board.draw();
    tetromino.draw();
}

bool ofApp::TouchesLeftRightBorders(vector<Block> changed_tetromino) {
    bool is_touching = false;
    for(int block_index = 0; block_index < changed_tetromino.size(); block_index++) {
        if(changed_tetromino[block_index].GetX() < 0 || changed_tetromino[block_index].GetX() == Board::kBoardWidth) {
            is_touching = true;
            break;
        }
    }
    return is_touching;
}
   
bool ofApp::TouchesBottom(vector<Block> changed_tetromino) {
    bool is_touching = false;
    for(int block_index = 0; block_index < changed_tetromino.size(); block_index++) {
        if(changed_tetromino[block_index].GetY() >= Board::kBoardHeight) {
            is_touching = true;
            break;
        }
    }
    return is_touching;
}

bool ofApp::TouchesBlock(vector<Block> changed_tetromino) {
    bool is_touching = false;
    for(int block_index = 0; block_index < changed_tetromino.size(); block_index++) {
        int x = changed_tetromino[block_index].GetX();
        int y = changed_tetromino[block_index].GetY();
        Block block_left = Board::blocks[x / Block::kBlockWidth][y / Block::kBlockHeight];
        Block block_right = Board::blocks[x / Block::kBlockWidth][y * Block::kBlockHeight];
        
        if(block_left.GetShade() != ofColor::pink && x == block_left.GetX() && y == block_left.GetY()) {
            is_touching = true;
            break;
        }
        if(block_right.GetShade() != ofColor::pink && x == block_right.GetX() && y == block_right.GetY()) {
            is_touching = true;
            break;
        }
    }
    return is_touching;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    vector<Block> changed_tetromino;
    switch(key) {
        case 'p':
            is_game_paused = true;
            break;
            
        // clockwise = w
        // counterclockwise = r
            
        case 'w':
            changed_tetromino = tetromino.RotateClockwise();
            break;
        case 'r':
            changed_tetromino = tetromino.RotateCounterClockwise();
            break;
       case OF_KEY_LEFT:
            changed_tetromino = tetromino.ShiftLeft();
            break;
        case OF_KEY_RIGHT:
            changed_tetromino = tetromino.ShiftRight();
            break;
        case OF_KEY_DOWN:
            changed_tetromino = tetromino.ShiftDown();
            break;
        default:
            break;
    }
    
    if(!TouchesLeftRightBorders(changed_tetromino) && !TouchesBlock(changed_tetromino) && !TouchesBottom(changed_tetromino)) {
        tetromino.SetTetromino(changed_tetromino);
    }
}
