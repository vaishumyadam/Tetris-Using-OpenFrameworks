#pragma once

#include "Tetromino.hpp"
#include "Pieces.hpp"
#include "Block.hpp"
#include "Board.hpp"
#include "ofMain.h"

class ofApp : public ofBaseApp{
    private:
        static int column_size;
        static int row_size;
    
        // do this
        ofSoundPlayer slide;
        ofSoundPlayer rotate;
    
        // remember that it's p to pause
        bool is_game_finished;
        bool is_game_paused;
    
	public:
        Board board;
        Tetromino tetromino;
    
		void setup();
		void update();
		void draw();
        void finish();
    
		void keyPressed(int key);
    
        bool isTouchingLeft(vector<Block> blocks);
        bool isTouchingRight(vector<Block> blocks);
        bool isTouchingBottom(vector<Block> blocks);
};
