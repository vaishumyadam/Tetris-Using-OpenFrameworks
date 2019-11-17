//
//  Block.cpp
//  fantastic-finale-vmyadam2
//
//  Created by Vaishnavi Myadam on 11/17/19.
//

#include "ofMain.h"
#include "Block.hpp"

//https://www.oreilly.com/library/view/mastering-openframeworks-creative/9781849518048/ch02s04.html
Block::Block(ofColor color, ofPoint point) {
    x = point.x;
    y = point.y;
    fill = color;
}

//https://openframeworks.cc/documentation/graphics/ofGraphics/#show_ofPushStyle
void Block::draw() {
    ofPushStyle();
    
    ofFill();
    ofSetColor(color);
    ofRect(x, y, kHorizontalLength, kVerticalLength);
    
    ofPopStyle();
}
