#ifndef SOUNDS_H
#define SOUNDS_H

#include<QMediaPlayer>
#include<QMediaPlaylist>
#include<QSoundEffect>

class Sounds {
public:
    Sounds();
    ~Sounds();

    void bgmusic(int);
    void failEff(int);
    void gameoverEff(int);
    void hitpadEff(int);
    void hitblkEff(int);
    void winEff(int);

private:
    QMediaPlaylist *playlist;
    QMediaPlayer *player;
    QSoundEffect *fail;
    QSoundEffect *win;
    QSoundEffect *gameover;
    QSoundEffect *hitpad;
    QSoundEffect *hitblk;
};


#endif // SOUNDS_H
