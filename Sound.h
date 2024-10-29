#pragma once
#include "Header.h"
#include"Sound.h"
bool isSFXEnabled = true;
void click() {
    if (isSFXEnabled) { // Kiểm tra xem SFX có được bật không
        PlaySound(TEXT("Music/click.wav"), NULL, SND_FILENAME | SND_ASYNC);
    }
}
void victory() {
    if (isSFXEnabled) { // Kiểm tra xem SFX có được bật không
        PlaySound(TEXT("Music/victory.wav"), NULL, SND_FILENAME | SND_ASYNC);
    }
}

void toggleSFX() {
    isSFXEnabled = !isSFXEnabled; // Đảo ngược trạng thái SFX
}

void step() {
    if (isSFXEnabled) { // Kiểm tra xem SFX có được bật không
        PlaySound(TEXT("Music/step.wav"), NULL, SND_FILENAME | SND_ASYNC);
    }
}

void stepO() {
    if (isSFXEnabled) { // Kiểm tra xem SFX có được bật không
        PlaySound(TEXT("Music/stepO.wav"), NULL, SND_FILENAME | SND_ASYNC);
    }
}
void error() {
    if (isSFXEnabled) { // Kiểm tra xem SFX có được bật không
        PlaySound(TEXT("Music/error.wav"), NULL, SND_FILENAME | SND_ASYNC);
    }
}