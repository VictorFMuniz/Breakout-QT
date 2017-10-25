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
    void fail(int);
    void gameover(int);
    void hitpad(int);
    void hitblk(int);
    void win(int);

private:
    QMediaPlaylist *playlist;
    QMediaPlayer *player;
    QSoundEffect *efx;

};


#endif // SOUNDS_H
