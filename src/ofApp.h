#pragma once

#include "Tetromino.hpp"
#include "Pieces.hpp"
#include "Block.hpp"
#include "Board.hpp"
#include "ofMain.h"
#include "ofxControlPanel.h"

class ofApp : public ofBaseApp{
    private:
        static const int column_size = 20;
        static const int row_size = 12;
        static const int target_frame_rate = 50;
        const int points_per_line = 25;
        int score = 0;

        ofSoundPlayer success, gameover, fall;
        ofxControlPanel control_panel;
        
        // For measuring time: https://developer.android.com/reference/android/os/SystemClock
        long frame_number;
        static int time_given_to_act;
    
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
        void mousePressed(int x, int y, int button);

        static bool TouchesLeftRightBorder(vector<Block> changed_tetromino);
        static bool TouchesBottom(vector<Block> changed_tetromino);
};
