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

#endif /* Block_hpp */

class Block {
public:
    int x;
    int y;
    ofColor color;
    
    // TODO: Change these?
    static const int kHorizontalLength = 44;
    static const int kVerticalLength = 44;
    
    Block(ofColor color, ofPoint, point);
    void draw();
};
