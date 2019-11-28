#include "ofApp.h"
#include "Tetromino.hpp"
#include "Pieces.hpp"
#include "Block.hpp"
#include "Board.hpp"

int ofApp::column_size = 25;
int ofApp::row_size = 25;

//--------------------------------------------------------------
void ofApp::setup(){
    // background is yellow
    // board is pink
    // pieces colors are shades of white
    
    ofSetBackgroundColor(ofColor::yellow);
    Board::init(column_size, row_size);
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    Board::draw();
    tetromino.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}
