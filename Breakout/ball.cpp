#include "ball.h"
#include <iostream>
#define MAX_X 300
#define MAX_Y 400
using namespace std;

Ball::Ball() {
    // no início, bola vai para a direção nordeste
    // direita e cima (x = 1 -> direita, y = 1 -> esquerda);
    xdir = 1;
    ydir = -1;

    image.load(":/images/ball.png");

    rect = image.rect();
    resetState();
}

Ball::~Ball() {
    cout << ("Ball deleted") << endl;
}

// uma forma de fazer ela mover-se com ângulos talvez seja pegando os senos dos ângulos de contato (pelo menos de alguns)
// e multiplicando pelas direções (x,y), que devem ser doubles para tal. Dessa forma, bolinha terá direções não exatamente
// para cima, para baixo, direita, esquerda e diagonal, tendo também angulação no movimento;
void Ball::autoMove() {
    rect.translate(xdir, ydir);
    // movimentos da bola quando ela bate em alguma das fronteiras
    // se a bola cai no chão, não é rebatida, o jogo termina
    if(rect.left() <= 0) {
        xdir = 2;
    }
    if(rect.right() >= MAX_X) {
        xdir = -2;
    }
    if(rect.top() <= 0) {
        ydir = 1;
    }
}

void Ball::resetState() {
    rect.moveTo(INITIAL_X, INITIAL_Y);
}

void Ball::setXDir(int x) {
    xdir = x;
}

void Ball::setYDir(int y) {
    ydir = y;
}

int Ball::getXDir() {
    return xdir;
}

int Ball::getYDir() {
    return ydir;
}

QRect Ball::getRect() {
    return rect;
}

QImage& Ball::getImage() {
    return image;
}
