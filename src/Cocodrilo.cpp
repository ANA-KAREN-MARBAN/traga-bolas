#include "Cocodrilo.hpp"

Cocodrilo::Cocodrilo(const sf::Texture& texture, const sf::Vector2f& position, float stepSize) 
    : initialPosition(position), stepSize(stepSize), frame(0), score(0) {
    sprite.setTexture(texture);
    sprite.setPosition(position);
    sprite.setTextureRect(sf::IntRect(0, 0, 50, 50));
}

void Cocodrilo::update() {
    if (animationClock.getElapsedTime().asSeconds() > 0.1f) {
        animate();
        animationClock.restart();
    }
}

void Cocodrilo::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

void Cocodrilo::animate() {
    frame = (frame + 1) % 6;
    sprite.setTextureRect(sf::IntRect(frame * 50, 0, 50, 50));
}

void Cocodrilo::moveForward() {
    sprite.move(stepSize, 0);
}

void Cocodrilo::moveBackward() {
    sprite.move(-stepSize, 0);
}

void Cocodrilo::increaseScore() {
    ++score;
}

int Cocodrilo::getScore() const {
    return score;
}

sf::FloatRect Cocodrilo::getBounds() const {
    return sprite.getGlobalBounds();
}
