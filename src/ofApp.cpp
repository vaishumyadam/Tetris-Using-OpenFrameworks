#include "ofApp.h"
#include "Tetromino.hpp"
#include "Pieces.hpp"
#include "Block.hpp"
#include "Board.hpp"

int ofApp::time_given_to_act = 500;

void ofApp::setup() {
    success.load("success.wav");
    gameover.load("gameover.wav");
    fall.load("fall.wav");

    // background is yellow
    // board is pink
    // pieces colors are shades of white
    control_panel.setup("TETRIS");
    frame_number = 0;
    ofSetFrameRate(target_frame_rate);
    
    ofSetBackgroundColor(ofColor::yellow);
    Board::init(column_size, row_size);
}

void ofApp::update() {
   
    vector<Block> changed_tetromino;
    
    if((ofGetElapsedTimeMillis() - frame_number > time_given_to_act) && !is_game_paused && !is_game_finished) {
        changed_tetromino = tetromino.ShiftDown();
        
        if(TouchesBottom(changed_tetromino)) {
            for(int block_index = 0; block_index < tetromino.blocks.size(); block_index++) {
                // updating board:

                int width_index = tetromino.blocks[block_index].GetX() / Block::kBlockWidth;
                int height_index = tetromino.blocks[block_index].GetY() / Block::kBlockHeight;
                
                Board::blocks[width_index][height_index].SetShade(tetromino.blocks[block_index].GetShade());
            }
            Board::DeleteLine(column_size, row_size);
            score += points_per_line; // adds score for each tetromino living in the board
            
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
    success.play();
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
    
        string game_message = "TETRIS: A WORTHY GAME:\np = pause\nu = unpause\nw = clockwise\nr = counterclockwise\n";
        ofSetColor(0, 0, 0);
    
        string score_message = "\n\nCURRENT SCORE: " + std::to_string(score) + "\nSecret Message: ";
        ofSetColor(0, 0, 0);
        if(score > 500) {
            score_message += "You ";
        }
        if(score > 1000) {
            score_message += "are ";
        }
        if(score > 1500) {
            score_message += "worthy";
        }
        ofDrawBitmapString(game_message + score_message, ofGetWindowWidth() * 0.65, ofGetWindowHeight() * 0.25); // TODO: how to do nums for this
    }
    if(is_game_finished) {
        string end_message = "GAME OVER";
        ofSetColor(0, 0, 0);
        ofDrawBitmapString(end_message, ofGetWindowWidth() * .65, ofGetWindowHeight() * .5);
    }
}

bool ofApp::TouchesLeftRightBorder(vector<Block> changed_tetromino) {
   bool is_touching = false;

    for(int block_index = 0; block_index < changed_tetromino.size(); block_index++) {
        if(changed_tetromino[block_index].GetX() == Board::kBoardWidth || changed_tetromino[block_index].GetX() < 0) {
            is_touching = true;
            break;
        } else {
            Block current_block = Board::blocks[changed_tetromino[block_index].GetX()/Block::kBlockWidth][changed_tetromino[block_index].GetY()/Block::kBlockHeight];
            if(current_block.GetShade() != ofColor::pink && changed_tetromino[block_index].GetX() == current_block.GetX() && changed_tetromino[block_index].GetY() == current_block.GetY()) {
                is_touching = true;
                break;
            }}
    }
    return is_touching;
}

bool ofApp::TouchesBottom(vector<Block> changed_tetromino) {
   bool is_touching = false;

    for(int block_index = 0; block_index < changed_tetromino.size(); block_index++) {
        if(changed_tetromino[block_index].GetY() >= Board::kBoardHeight) {
            is_touching = true;
            break;
        } else {
            Block current_block = Board::blocks[changed_tetromino[block_index].GetX()/Block::kBlockWidth][changed_tetromino[block_index].GetY()/Block::kBlockHeight];
            if(current_block.GetShade() != ofColor::pink && changed_tetromino[block_index].GetX() == current_block.GetX() && changed_tetromino[block_index].GetY() == current_block.GetY()) {
                is_touching = true;
                break;
            }
        }
    }
    return is_touching;
}

void ofApp::keyPressed(int key) {
    vector<Block> changed_tetromino;
    switch(key) {
        case 'p':
            gameover.play();
            is_game_paused = true;
            break;
        case 'u':
            is_game_paused = false;
            break;
            
        // clockwise = w
        // counterclockwise = r
            
        case 'w':
            changed_tetromino = tetromino.RotateClockwise();
            if(!TouchesLeftRightBorder(changed_tetromino)) {
                tetromino.SetTetromino(changed_tetromino);
            }
            break;
        case 'r':
            changed_tetromino = tetromino.RotateCounterClockwise();
            if(!TouchesLeftRightBorder(changed_tetromino)) {
                tetromino.SetTetromino(changed_tetromino);
            }
            break;
        case 's': // stop game
           is_game_finished = true;
            break;
       case OF_KEY_LEFT:
            changed_tetromino = tetromino.ShiftLeft();
            if(!TouchesLeftRightBorder(changed_tetromino)) {
                tetromino.SetTetromino(changed_tetromino);
            }
            break;
        case OF_KEY_RIGHT:
            changed_tetromino = tetromino.ShiftRight();
            if(!TouchesLeftRightBorder(changed_tetromino)) {
                tetromino.SetTetromino(changed_tetromino);
            }
            break;
        case OF_KEY_DOWN:
            changed_tetromino = tetromino.ShiftDown();
            if(!TouchesBottom(changed_tetromino)) {
                fall.play(); // special case
                tetromino.SetTetromino(changed_tetromino);
            }
            // because I take hitting bottom as a sign of impatience
            if(time_given_to_act > 50) {
                   time_given_to_act -= 10;
            }
            break;
        default:
            break;
    }
}
