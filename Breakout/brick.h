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
    void setStrength(int);
    int getStrength();

private:
    QImage image;
    QRect rect;
    // quando um tijolo é destruído,
    // destroyed = true;
    bool destroyed;
    // alguns tijolos terão mais força
    // (precisam de até 2 batidas para quebrarem)
    int strength;
};

#endif // BRICK_H
