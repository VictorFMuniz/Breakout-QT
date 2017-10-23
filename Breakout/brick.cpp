#include "brick.h"
#include <iostream>

using namespace std;

Brick::Brick(int x, int y) {
    image.load("brick.png");
    destroyed = false;
    rect = image.rect();
    rect.translate(x,y);
}

Brick::~Brick() {
    cout << ("Brick deleted") << endl;
}

QRect Brick::getRect() {
    return rect;
}

void Brick::setRect(QRect rct) {
    rect = rct;
}

QImage& Brick::getImage() {
    return image;
}

bool Brick::isDestroyed() {
    return destroyed;
}

void Brick::setDestroyed(bool destroy) {
    destroyed = destroy;
}