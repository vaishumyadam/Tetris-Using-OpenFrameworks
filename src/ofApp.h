#pragma once

#include "Tetromino.hpp"
#include "Pieces.hpp"
#include "Block.hpp"
#include "Board.hpp"
#include "ofMain.h"
#include "ofxControlPanel.h"

class ofApp : public ofBaseApp{
    private:
        int score = 0;
        const int points_per_line = 25;
    
        ofSoundPlayer success, gameover, fall;
        ofxControlPanel control_panel;
        //int ofApp::column_size = 25;
        //int ofApp::row_size = 21;

        static const int column_size = 20;
        static const int row_size = 12;
    
        static int time_given_to_act;
        static const int target_frame_rate = 50;
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
    
    static bool TouchesLeftRightBorder(vector<Block> changed_tetromino);
        static bool TouchesLeftBorder(vector<Block> changed_tetromino);
        static bool TouchesRightBorder(vector<Block> changed_tetromino);
        //static bool TouchesBlock(vector<Block> changed_tetromino);
        static bool TouchesBottom(vector<Block> changed_tetromino);
        void mousePressed(int x, int y, int button);
};
