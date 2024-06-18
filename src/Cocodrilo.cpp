#include "Cocodrilo.hpp"

Cocodrilo::Cocodrilo(const sf::Texture& texture, const sf::Vector2f& position, float moveDirection)
    : initialPosition(position), moveDistance(2.0f), moveDirection(moveDirection), moving(false), animationTime(0.5f), score(0), frameIndex(0) {
    this->texture = texture;
    sprite.setTexture(this->texture);
    sprite.setPosition(position);
    int frameWidth = texture.getSize().x / 6; // Dividimos la textura en 6 frames de igual tamaño
    textureRect = sf::IntRect(0, 0, frameWidth, texture.getSize().y); // Primer frame inicializado
    sprite.setTextureRect(textureRect);
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
            float distanceToMove = moveDirection * moveDistance * (deltaTime / animationTime);
            sprite.move(distanceToMove, 0);
            // Actualizamos el rectángulo de textura para la siguiente frame de la animación
            frameIndex = static_cast<int>((elapsed / animationTime) * 6) % 6; // Calculamos el índice del frame actual
            textureRect.left = frameIndex * textureRect.width; // Posicionamos el rectángulo en la nueva frame
            sprite.setTextureRect(textureRect);
        } else {
            sprite.setPosition(initialPosition);
            moving = false;
            frameIndex = 0; // Reiniciamos la animación
            textureRect.left = 0;
            sprite.setTextureRect(textureRect);
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

void Cocodrilo::resetAnimation() {
    frameIndex = 0;
    textureRect.left = 0;
    sprite.setTextureRect(textureRect);
}
