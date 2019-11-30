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
    
    // Check touching borders at end. No finally???
    if(tetromino.isTouchingBottom(changed_tetromino)) {
        // tetromino = changed_tetromino;
    }
    else if(!(tetromino.isTouchingLeft(changed_tetromino) || tetromino.isTouchingRight(changed_tetromino))) {
    }
    else {
       // tetromino = changed_tetromino;
    }
}
