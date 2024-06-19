#ifndef SOUNDMANAGER_HPP
#define SOUNDMANAGER_HPP

#include <SFML/Audio.hpp>

class SoundManager {
public:
    SoundManager();
    void loadSounds();
    void playGanoSound();
    void playMenosSound();
    void playMasSound();

private:
    sf::SoundBuffer ganoBuffer, menosBuffer, masBuffer;
    sf::Sound ganoSound, menosSound, masSound;
};

#endif // SOUNDMANAGER_HPP
