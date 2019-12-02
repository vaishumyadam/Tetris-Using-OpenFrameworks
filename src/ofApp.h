#pragma once

#include "Tetromino.hpp"
#include "Pieces.hpp"
#include "Block.hpp"
#include "Board.hpp"
#include "ofMain.h"
#include "ofxControlPanel.h"

class ofApp : public ofBaseApp{
    private:
        ofSoundPlayer success, gameover, fall;
        ofxControlPanel control_panel;

        static int column_size;
        static int row_size;
        static const int time_given_to_act = 500;
    
        // For measuring time: https://developer.android.com/reference/android/os/SystemClock
        long frame_number;
    
        // remember that it's p to pause!
    
        bool is_game_finished;
        bool is_game_paused;
        bool is_game_started;
    
	public:
        Board board;
        Tetromino tetromino;
    
		void setup();
		void update();
		void draw();
        void finish();
    
		void keyPressed(int key);
    
        static bool TouchesLeftRightBorders(vector<Block> changed_tetromino);
        static bool TouchesBlock(vector<Block> changed_tetromino);
        static bool TouchesBottom(vector<Block> changed_tetromino);
        void mousePressed(int x, int y, int button);
};
