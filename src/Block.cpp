//
//  Block.cpp
//  fantastic-finale-vmyadam2
//
//  Created by Vaishnavi Myadam on 11/17/19.
//

#include "ofMain.h"
#include "Block.hpp"

int Block::GetX() {
    return x;
}

void Block::SetX(int set_x) {
    x = set_x;
}

int Block::GetY() {
    return y;
}

void Block::SetY(int set_y) {
    y = set_y;
}

ofColor Block::GetShade() {
    return shade;
}

void Block::SetShade(ofColor set_shade) {
    shade = set_shade;
}

ofColor Block::GetBorder() {
    return border;
}

// https://www.oreilly.com/library/view/mastering-openframeworks-creative/9781849518048/ch02s04.html
Block::Block(ofPoint point, ofColor set_shade, ofColor set_border) {
    x = point.x;
    y = point.y;
    shade = set_shade;
    border = set_border;
}

// https://openframework.cc/documentation/graphics/ofGraphics/#show_ofPushStyle
void Block::draw() {
    int outer_x = x + 1;
    int outer_y = y + 1;
    int inner_width = kBlockWidth - 1;
    int inner_height = kBlockHeight - 1;
    
    ofPushStyle(); {
        ofSetColor(border);
        ofRect(x, y, kBlockWidth, kBlockHeight);
        ofFill();
        ofSetColor(shade);
        ofRect(outer_x, outer_y, inner_width, inner_height);
    };
    ofPopStyle();
}
