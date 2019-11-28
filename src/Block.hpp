//
//  Block.hpp
//  fantastic-finale-vmyadam2
//
//  Created by Vaishnavi Myadam on 11/17/19.
//
#include "ofMain.h"
#ifndef Block_hpp
#define Block_hpp

#include <stdio.h>


class Block {
private:
    int x;
    int y;
    ofColor shade;
    ofColor border;
    
public:
    static const int kBlockWidth = 25;
    static const int kBlockHeight = 25;
    
    int GetX();
    int GetY();
    void SetX(int set_x);
    void SetY(int set_y);
    ofColor GetShade();
    void SetShade(ofColor set_shade);
    
    Block(ofPoint point, ofColor shade);
    void draw();
};

#endif /* Block_hpp */
