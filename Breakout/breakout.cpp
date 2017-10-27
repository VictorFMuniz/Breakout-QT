#include "breakout.h"
#include <iostream>
#include <QPainter>
#include <QApplication>
#include <QMediaPlaylist>
#include <QMediaPlayer>
#include <QMouseEvent>
using namespace std;

Breakout::Breakout(QWidget *parent) : QWidget(parent) {
    // instanciando todos os objetos e modelos
    x = 0;
    score = 0;
    gameOver = false;
    gameWon = false;
    gamePaused = false;
    gameStarted = false;
    ball = new Ball();
    paddle = new Paddle();
    sound = new Sounds();
    int k = 0;
    // instanciando 30 blocos no jogo
    for(int i=0; i<5; i++) {
        for(int j=0; j<6; j++) {
            brick[k] = new Brick(j*40+30, i*10+50);
            if(i==0) {
                brick[k]->setStrength(2);
            } else {
                brick[k]->setStrength(1);
            }
            k++;
        }
    }
}

Breakout::~Breakout() {
    delete ball;
    delete paddle;
    delete sound;
    for(int i=0; i<N_OF_BRICKS; i++) {
        delete brick[i];
    }
}

void Breakout::paintEvent(QPaintEvent *e) {
    Q_UNUSED(e);
    QPainter painter(this);

    // jogo terminado: game over aparece na tela
    // jogo ganho: texto de vitória aparece
    if(gameOver) {
        QString message = "Game Over...";
        finishGame(&painter, message);
    } else if(gameWon) {
        QString message = "You Win!!!";
        finishGame(&painter, message);
    } else {
        drawObjects(&painter);
    }
}

// pinta o texto na tela de acordo com o resultado
void Breakout::finishGame(QPainter *painter, QString message) {
    QFont font("system", 32, QFont::DemiBold);
    QFontMetrics fm(font);
    int textWidth = fm.width(message);

    painter->setFont(font);
    painter->setPen(Qt::white);
    int h = height();
    int w = width();

    painter->translate(QPoint(w/2, h/2));
    painter->drawText(-textWidth/2, 0, message);
}

// método que desenha os objetos do jogo na tela
void Breakout::drawObjects(QPainter* painter) {
    painter->drawImage(ball->getRect(), ball->getImage());
    painter->drawImage(paddle->getRect(), paddle->getImage());

    for(int i=0; i<N_OF_BRICKS; i++) {
        if(!brick[i] -> isDestroyed()) {
            painter->drawImage(brick[i]->getRect(), brick[i]->getImage());
        }
    }
}

// método que faz mover os objetos, checa colisão da bola
// e gera evento de paint
void Breakout::timerEvent(QTimerEvent *e) {
    Q_UNUSED(e);

    moveObjects();
    checkCollision();
    repaint();
}

// método que chama movimento dos objetos não-estáticos
void Breakout::moveObjects() {
    ball->autoMove();
    paddle->move();
}

// método que faz o movimento da barra parar
void Breakout::keyReleaseEvent(QKeyEvent *e) {
    int dx = 0;

    switch(e->key()) {
        case Qt::Key_Left:
            dx = 0;
            paddle->setDx(dx);
        break;
        case Qt::Key_Right:
            dx = 0;
            paddle->setDx(dx);
        break;
    }
}


// método que faz checagem do mouse
void Breakout::mouseReleaseEvent(QMouseEvent *e) {

    switch(e->button()) {
        case Qt::RightButton:
            pauseGame();
        break;
        case Qt::LeftButton:
            gameStarted = false;
            startGame();
        break;
        default:
        QWidget::mouseReleaseEvent(e);
    }
}


// método que gera ações de acordo com as teclas pressionadas
void Breakout::keyPressEvent(QKeyEvent *e) {
    int dx = 0;

    switch (e->key()) {
    case Qt::Key_Left:
        dx = -1;
        paddle->setDx(dx);

    break;
    case Qt::Key_Right:
        dx = 1;
        paddle->setDx(dx);

    break;
    case Qt::Key_R:
        gameStarted = false;
        startGame();

    break;
    case Qt::Key_Space:
        startGame();

    break;
    case Qt::Key_Escape:
        qApp ->exit();

    break;
    case Qt::Key_Q:
        qApp ->exit();

    break;
    default:
        QWidget::keyPressEvent(e);
    }
}

// reseta a posição dos objetos para a posição inicial
void Breakout::startGame() {
    if(!gameStarted) {
        if (timerId > 0)killTimer(timerId);
        sound->bgmusic(50);
        ball->resetState();
        paddle->resetState();

        for(int i=0; i<N_OF_BRICKS; i++) {
            brick[i]->setDestroyed(false);
        }

        gameOver = false;
        gameWon = false;
        gameStarted = true;
        score = 0;
        life = 3;
        timerId = startTimer(DELAY);
    }else{
        timerId = startTimer(DELAY);
    }
}

// jogo é pausado
void Breakout::pauseGame() {
    if(gamePaused) {
        timerId = startTimer(DELAY);
        gamePaused = false;
    } else {
        gamePaused = true;
        cout<<"pontos: "<<score<<endl<<"vidas: "<<life<<endl;
        killTimer(timerId);
    }
}

void Breakout::stopGame() {
    killTimer(timerId);
    gameOver = true;
    gameStarted = false;
    sound->stop();
    sound->gameoverEff(30);
}

void Breakout::victory() {
    killTimer(timerId);
    gameWon = true;
    gameStarted = false;
    sound->stop();
    sound->winEff(30);
}

void Breakout::checkCollision() {

    // se bola acerta o chão, diminui a vida e
    // bola e barra voltam à posição inicial
    // caso a vida chegue a 0, o jogo termina
    if(ball->getRect().bottom() > BOTTOM_EDGE) {
        if(life > 0) {
            sound->failEff(30);
            life--;
            paddle->resetState();
            ball->resetState();
            pauseGame();
        }
        else {
            stopGame();
        }
    }

    for(int i=0, j=0; i<N_OF_BRICKS; i++) {
        if(brick[i]->isDestroyed()) {
            j++;
        }
        if(j == N_OF_BRICKS) {
            victory();
        }
    }

    if(ball->getRect().intersects(paddle->getRect())) {
        // faz barulho
        sound->hitpadEff(30);

        int paddlePos = paddle->getRect().left();
        int ballPos = ball->getRect().left();
        // barra é dividida em 4 partes
        int first = paddlePos + 8;
        int second = paddlePos + 16;
        int third = paddlePos + 24;
        int fourth = paddlePos + 32;
    // colisão da bola com a 1a parte
        if(ballPos < first) {
            ball->setXDir(-1);
            ball->setYDir(-1);
        }
   // colisão da bola com a 2a parte
        if(ballPos >= first && ballPos < second) {
            ball->setXDir(-1);
            ball->setYDir(-1*ball->getYDir());
        }
   // colisão da bola com a 3a parte
        if(ballPos >= second && ballPos < third) {
            ball->setXDir(0);
            ball->setYDir(-1);
        }
   // colisão da bola com a 4a parte
        if(ballPos >= third && ballPos < fourth) {
            ball->setXDir(0);
            ball->setYDir(-1*ball->getYDir());
        }
        if(ballPos > fourth) {
            ball->setXDir(1);
            ball->setYDir(-1);
        }
    }

    for(int i=0; i<N_OF_BRICKS; i++) {
        if((ball->getRect()).intersects(brick[i]->getRect())) {

            // ------------------
            int ballLeft = ball->getRect().left();
            int ballHeight = ball->getRect().height();
            int ballWidth = ball->getRect().width();
            int ballTop = ball->getRect().top();

            QPoint pointRight(ballLeft + ballWidth + 1, ballTop);
            QPoint pointLeft(ballLeft - 1, ballTop);
            QPoint pointTop(ballLeft, ballTop - 1);
            QPoint pointBottom(ballLeft, ballTop + ballHeight + 1);

            if (!brick[i]->isDestroyed()) {
                    if(brick[i]->getRect().contains(pointRight)) {
                       ball->setXDir(-1);
                    }

                    else if(brick[i]->getRect().contains(pointLeft)) {
                       ball->setXDir(1);
                    }

                    if(brick[i]->getRect().contains(pointTop)) {
                       ball->setYDir(1);
                    }

                    else if(brick[i]->getRect().contains(pointBottom)) {
                       ball->setYDir(-1);
                    }
                    // faz barulho
                    sound->hitblkEff(30);
                    brick[i]->setStrength(brick[i]->getStrength()-1);
                    if(brick[i]->getStrength() == 0) {
                        brick[i]->setDestroyed(true);
                        score++;
                    }
                  }
        }
    }

}















