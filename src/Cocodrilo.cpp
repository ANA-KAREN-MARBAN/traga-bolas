#include "Cocodrilo.hpp"
#include <iostream>

Cocodrilo::Cocodrilo(sf::Vector2f position, const std::string &textureFile) {
    if (!texture.loadFromFile(textureFile)) {
        std::cerr << "Error cargando la textura de cocodrilo" << std::endl;
    }
    sprite.setTexture(texture);
    sprite.setPosition(position);
    sprite.setTextureRect(sf::IntRect(0, 0, frameWidth, frameHeight));
}

void Cocodrilo::move(float offsetX, float offsetY) {
    sprite.move(offsetX, offsetY);
}

void Cocodrilo::draw(sf::RenderWindow &window) {
    window.draw(sprite);
}

void Cocodrilo::update() {
    if (clock.getElapsedTime().asSeconds() >= frameTime) {
        currentFrame = (currentFrame + 1) % numFrames;
        sprite.setTextureRect(sf::IntRect(currentFrame * frameWidth, 0, frameWidth, frameHeight));
        clock.restart();
    }
}

sf::FloatRect Cocodrilo::getBounds() const {
    return sprite.getGlobalBounds();
}
