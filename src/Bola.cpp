#include "Bola.hpp"

Bola::Bola(float radius, const sf::Vector2f &position, const sf::Color &color, const sf::Vector2f &velocity)
    : velocity(velocity), hasBounced(false)
{
    shape.setRadius(radius);
    shape.setFillColor(color);
    shape.setPosition(position);
}

void Bola::update(const sf::FloatRect &bounds)
{
    shape.move(velocity);

    if (!hasBounced)
    {
        if (shape.getPosition().y + shape.getRadius() * 2 >= bounds.top + bounds.height * 0.8f)
        {
            velocity.y = -velocity.y;
            hasBounced = true;
        }
    }
    else if (!bounds.intersects(shape.getGlobalBounds()))
    {
        shape.setPosition(-100, -100); // Mover la bola fuera de la pantalla
    }
}

void Bola::draw(sf::RenderWindow &window) const
{
    window.draw(shape);
}

sf::FloatRect Bola::getBounds() const
{
    return shape.getGlobalBounds();
}

sf::Color Bola::getColor() const
{
    return shape.getFillColor();
}

void Bola::setPosition(const sf::Vector2f &position)
{
    shape.setPosition(position);
}

sf::Vector2f Bola::getPosition() const
{
    return shape.getPosition();
}
