#include "Cocodrilo.hpp"

Cocodrilo::Cocodrilo(const sf::Texture& texture, const sf::Vector2f& position, float moveDirection)
    : initialPosition(position), moveDistance(30.0f), moveDirection(moveDirection), moving(false), animationTime(0.5f), score(0) {
    sprite.setTexture(texture);
    sprite.setPosition(position);
}

void Cocodrilo::moveForward() {
    if (!moving) {
        moving = true;
        moveClock.restart();
    }
}

void Cocodrilo::update(float deltaTime) {
    if (moving) {
        float elapsed = moveClock.getElapsedTime().asSeconds();
        if (elapsed < animationTime) {
            sprite.move(moveDirection * moveDistance * (elapsed / animationTime), 0);
        } else {
            sprite.setPosition(initialPosition);
            moving = false;
        }
    }
}

void Cocodrilo::draw(sf::RenderWindow& window) const {
    window.draw(sprite);
}

sf::FloatRect Cocodrilo::getBounds() const {
    return sprite.getGlobalBounds();
}

void Cocodrilo::increaseScore() {
    score++;
}

void Cocodrilo::decreaseScore() {
    score--;
}

int Cocodrilo::getScore() const {
    return score;
}
