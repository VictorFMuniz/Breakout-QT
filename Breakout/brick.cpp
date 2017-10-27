#include "brick.h"
#include <iostream>

using namespace std;

Brick::Brick(int x, int y) {
    image.load(":/images/brick.png");
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

int Brick::getStrength() {
    return strength;
}

void Brick::setStrength(int st) {
    strength = st;
}

void Brick::setDestroyed(bool destroy) {
    destroyed = destroy;
}
