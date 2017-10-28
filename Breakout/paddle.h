#ifndef PADDLE_H
#define PADDLE_H

#include <QImage>
#include <QRect>

class Paddle {
public:
    Paddle();
    ~Paddle();

    void resetState();
    void move();
    void setDx(int);
    int getDx();
    QRect getRect();
    QImage& getImage();

private:
    QImage image;
    QRect rect;
    // dx controla direção de movimento da barra:
    int dx;
    // posição inicial da barrinha do jogo
    static const int INITIAL_X = 130;
    static const int INITIAL_Y = 360;
};

#endif // PADDLE_H
