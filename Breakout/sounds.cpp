#include "sounds.h"

using namespace std;

Sounds::Sounds() {
}

Sounds::~Sounds() {
}

void Sounds::bgmusic(int volume){
    player = new QMediaPlayer;
    playlist = new QMediaPlaylist;
    playlist->addMedia(QUrl("qrc:/assets/sound.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);
    player->setPlaylist(playlist);
    player->setVolume(volume);
    player->play();
}

void Sounds::fail(int volume){
    efx->setSource(QUrl("qrc:/assets/fail.wav"));
    efx->setVolume(volume);
    efx->play();
}

void Sounds::gameover(int volume){
    efx->setSource(QUrl("qrc:/assets/gameover.wav"));
    efx->setVolume(volume);
    efx->play();
}

void Sounds::hitpad(int volume){
    efx->setSource(QUrl("qrc:/assets/hitpad.wav"));
    efx->setVolume(volume);
    efx->play();
}

void Sounds::hitblk(int volume){
    efx->setSource(QUrl("qrc:/assets/hitblk.wav"));
    efx->setVolume(volume);
    efx->play();
}

void Sounds::win(int volume){
    efx->setSource(QUrl("qrc:/assets/win.wav"));
    efx->setVolume(volume);
    efx->play();
}
