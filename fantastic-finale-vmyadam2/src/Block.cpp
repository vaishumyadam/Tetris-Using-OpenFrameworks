//
//  Block.cpp
//  fantastic-finale-vmyadam2
//
//  Created by Vaishnavi Myadam on 11/17/19.
//

#include "ofMain.h"
#include "Block.hpp"

int GetX() {
    return x;
}

int GetY() {
    return y;
}

void SetX(int set_x) {
    x = set_x;
}

void SetY(int set_y) {
    y = set_y;
}

//https://www.oreilly.com/library/view/mastering-openframeworks-creative/9781849518048/ch02s04.html
Block::Block(ofColor color, ofPoint point) {
    x = point.x;
    y = point.y;
    fill = color;
}

//https://openframework.cc/documentation/graphics/ofGraphics/#show_ofPushStyle
void Block::draw() {
    ofPushStyle();
    
    ofFill();
    ofSetColor(color);
    ofRect(x, y, kHorizontalBlockLength, kVerticalBlockLength);
    
    ofPopStyle();
}
