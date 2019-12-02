#include "ofApp.h"
#include "Tetromino.hpp"
#include "Pieces.hpp"
#include "Block.hpp"
#include "Board.hpp"

int ofApp::column_size = 25;
int ofApp::row_size = 21;

//--------------------------------------------------------------
void ofApp::setup() {
    // background is yellow
    // board is pink
    // pieces colors are shades of white
    control_panel.setup("TETRIS");
    ofSetBackgroundColor(ofColor::yellow);
    Board::init(column_size, row_size);
}

//--------------------------------------------------------------
void ofApp::update() {
    vector<Block> changed_tetromino;
    if(ofGetElapsedTimeMillis() - frame_number > time_given_to_act && !is_game_paused && !is_game_finished) {
        changed_tetromino = tetromino.ShiftDown();
        
        if(TouchesBottom(changed_tetromino)) {
            for(int block_index = 0; block_index < tetromino.blocks.size(); block_index++) {
                // updating board:

                int width_index = tetromino.blocks[block_index].GetX() / Block::kBlockWidth;
                int height_index = tetromino.blocks[block_index].GetY() / Block::kBlockHeight;
                
                Board::blocks[width_index][height_index].SetShade(tetromino.blocks[block_index].GetShade());
            }
            Board::DeleteLine(column_size, row_size);
            
            if(tetromino.num_slide_down == 0) {
                is_game_finished = true;
                Board::init(column_size, row_size);
            }
            else {
                tetromino.reset();
            }
        }
        else {
            tetromino.SlideDown(changed_tetromino);
        }
        frame_number = ofGetElapsedTimeMillis();
    }
    
}

void ofApp::mousePressed(int x, int y, int button) {
    is_game_started = true;
}

//--------------------------------------------------------------
void ofApp::draw() {
    if(!is_game_started) {
        string open_message = "CLICK ANYWHERE TO PLAY \"TETRIS: A WORTHY GAME\"";
        control_panel.draw();
        ofDrawBitmapString(open_message, ofGetWindowWidth() * 0.3, ofGetWindowHeight() * 0.5);
    } else {
        Board::draw();
        tetromino.draw();
    
        string game_message = "TETRIS: A WORTHY GAME:\np = pause\nw = clockwise\nr = counterclockwise";
        ofSetColor(0, 0, 0);
    
        ofDrawBitmapString(game_message, ofGetWindowWidth() * 0.65, ofGetWindowHeight() * 0.25); // TODO: how to do nums for this
    }
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
