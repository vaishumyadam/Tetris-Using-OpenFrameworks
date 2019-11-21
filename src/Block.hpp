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
    ofColor color;
    
public:
    // TODO: Change these?
    // Keeping them separate so that users can change it to rectangle
    static const int kHorizontalBlockLength = 44;
    static const int kVerticalBlockLength = 44;
    
    int GetX();
    int GetY();
    void SetX(int set_x);
    void SetY(int set_y);
    
    Block(ofColor color, ofPoint point);
    void draw();
};

#endif /* Block_hpp */
