
#include "paddle.h"
#include <iostream>
#define MAX_X 300
#define MAX_Y 400
using namespace std;

Paddle::Paddle() {
    dx = 0;
    image.load(":/images/paddle.png");

    rect = image.rect();
    resetState();
}

Paddle::~Paddle() {
    cout << ("Paddle deleted.") << endl;
}

int Paddle::getDx() {
    return dx;
}

void Paddle::setDx(int x) {
    dx = x;
}

void Paddle::move() {
    int x = rect.x() + dx;
    if(x <=0){
        x=rect.x();
    }
    if(rect.x() + rect.width() + dx >= MAX_X )
        x=rect.x();
    int y = rect.top();
        rect.moveTo(x,y);
}

void Paddle::resetState() {
    rect.moveTo(INITIAL_X, INITIAL_Y);
}

QRect Paddle::getRect() {
    return rect;
}

QImage& Paddle::getImage() {
    return image;
}
