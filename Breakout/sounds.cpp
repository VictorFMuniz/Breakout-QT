#include "sounds.h"

using namespace std;

Sounds::Sounds() {
    player = new QMediaPlayer;
    playlist = new QMediaPlaylist;
    fail = new QSoundEffect;
    win = new QSoundEffect;
    hitblk = new QSoundEffect;
    hitpad = new QSoundEffect;
    gameover = new QSoundEffect;
}

Sounds::~Sounds() {
    delete player;
    delete playlist;
    delete win;
    delete hitblk;
    delete hitpad;
    delete gameover;
}

void Sounds::bgmusic(int volume){
    playlist->addMedia(QUrl("qrc:/assets/sound.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);
    player->setPlaylist(playlist);
    player->setVolume(volume);
    player->play();
}

void Sounds::failEff(int volume){
    fail->setSource(QUrl("qrc:/assets/fail.wav"));
    fail->setVolume(volume);
    fail->play();
}

void Sounds::gameoverEff(int volume){
    gameover->setSource(QUrl("qrc:/assets/gameover.wav"));
    gameover->setVolume(volume);
    gameover->play();
}

void Sounds::hitpadEff(int volume){
    hitpad->setSource(QUrl("qrc:/assets/hitpad.wav"));
    hitpad->setVolume(volume);
    hitpad->play();
}

void Sounds::hitblkEff(int volume){
    hitblk->setSource(QUrl("qrc:/assets/hitblk.wav"));
    hitblk->setVolume(volume);
    hitblk->play();
}

void Sounds::winEff(int volume){
    win->setSource(QUrl("qrc:/assets/win.wav"));
    win->setVolume(volume);
    win->play();
}
