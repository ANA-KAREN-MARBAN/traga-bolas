#include "SoundManager.hpp"

SoundManager::SoundManager() {
    loadSounds();
}

void SoundManager::loadSounds() {
    if (!ganoBuffer.loadFromFile("assets/music/gano.mp3") ||
        !menosBuffer.loadFromFile("assets/music/menos.mp3") ||
        !masBuffer.loadFromFile("assets/music/mas.mp3")) {
        throw std::runtime_error("Error al cargar archivos de sonido");
    }

    ganoSound.setBuffer(ganoBuffer);
    menosSound.setBuffer(menosBuffer);
    masSound.setBuffer(masBuffer);
}

void SoundManager::playGanoSound() {
    ganoSound.play();
}

void SoundManager::playMenosSound() {
    menosSound.play();
}

void SoundManager::playMasSound() {
    masSound.play();
}
