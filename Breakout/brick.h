#ifndef BRICK_H
#define BRICK_H

#include <QImage>
#include <QRect>

class Brick {
public:
    Brick(int, int);
    ~Brick();

    bool isDestroyed();
    void setDestroyed(bool);
    QRect getRect();
    void setRect(QRect);
    QImage& getImage();

private:
    QImage image;
    QRect rect;
    // quando um tijolo é destruído,
    // destroyed = true;
    bool destroyed;
};

#endif // BRICK_H
