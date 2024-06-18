#include "Bola.hpp"

Bola::Bola(float radius, const sf::Vector2f& position, const sf::Color& color, const sf::Vector2f& velocity) 
    : velocity(velocity) {
    shape.setRadius(radius);
    shape.setPosition(position);
    shape.setFillColor(color);
    shape.setOrigin(radius, radius);
}

void Bola::update(const sf::FloatRect& bounds) {
    sf::Vector2f position = shape.getPosition();
    position += velocity * 0.016f;

    if (position.x - shape.getRadius() < bounds.left || 
        position.x + shape.getRadius() > bounds.left + bounds.width) {
        velocity.x = -velocity.x;
    }
    if (position.y - shape.getRadius() < bounds.top || 
        position.y + shape.getRadius() > bounds.top + bounds.height) {
        velocity.y = -velocity.y;
    }

    shape.setPosition(position);
}

void Bola::draw(sf::RenderWindow& window) const {
    window.draw(shape);
}

sf::FloatRect Bola::getBounds() const {
    return shape.getGlobalBounds();
}
