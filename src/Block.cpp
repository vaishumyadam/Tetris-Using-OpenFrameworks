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

int Block::GetY() {
    return y;
}

void Block::SetX(int set_x) {
    x = set_x;
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

//https://www.oreilly.com/library/view/mastering-openframeworks-creative/9781849518048/ch02s04.html
Block::Block(ofPoint point, ofColor set_shade, ofColor set_border) {
    x = point.x;
    y = point.y;
    shade = set_shade;
    border = set_border;
}

//https://openframework.cc/documentation/graphics/ofGraphics/#show_ofPushStyle
void Block::draw() {
    ofPushStyle(); {
        ofSetColor(border);
        ofRect(x, y, kBlockWidth, kBlockHeight);
        ofFill();
        ofSetColor(shade);
        ofRect(x + 1, y + 1, kBlockWidth - 1, kBlockHeight - 1);
    };
    ofPopStyle();
}
