#ifndef BREAKOUT_H
#define BREAKOUT_H

#include <QWidget>
#include <QKeyEvent>
#include "ball.h"
#include "brick.h"
#include "paddle.h"

class Breakout : public QWidget
{
    Q_OBJECT

public:
    explicit Breakout(QWidget *parent = 0);
    ~Breakout();

protected:
    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent *);
    // barra controlada por teclas
    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *);
    void drawObjects(QPainter *);
    void finishGame(QPainter*, QString);
    void moveObjects();
    void startGame();
    void pauseGame();
    void stopGame();
    void victory();
    void checkCollision();

private:
    // x é a posição atual da barra
    int x;
    // timerId para controlar o tempo do jogo, necessário para Pause
    int timerId;
    // adicionando pontuação a cada checkCollision() ou cada vez q N_OF_BRICKS diminui 1.
    int score=0;
    // adicionando vidas para o jogo (máximo 3);
    int life = 3;
    static const int N_OF_BRICKS = 30;
    // DELAY control a velocidade do jogo
    static const int DELAY = 10;
    static const int BOTTOM_EDGE = 400;
    Ball* ball;
    Brick* brick[N_OF_BRICKS];
    Paddle* paddle;
    bool gameOver;
    bool gameWon;
    bool gameStarted;
    bool gamePaused;


};

#endif // BREAKOUT_H
