#include "Bola.hpp"
#include <iostream>

Bola::Bola(sf::Vector2f position, const std::string &textureFile, bool isPositive) : positive(isPositive) {
    if (!texture.loadFromFile(textureFile)) {
        std::cerr << "Error cargando la textura de bola" << std::endl;
    }
    sprite.setTexture(texture);
    sprite.setPosition(position);
}

void Bola::draw(sf::RenderWindow &window) {
    window.draw(sprite);
}

sf::FloatRect Bola::getBounds() const {
    return sprite.getGlobalBounds();
}

bool Bola::isPositive() const {
    return positive;
}
