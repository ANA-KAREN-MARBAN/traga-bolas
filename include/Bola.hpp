#ifndef BOLA_HPP
#define BOLA_HPP

#include <SFML/Graphics.hpp>

class Bola
{
public:
    Bola(float radius, const sf::Vector2f &position, const sf::Color &color, const sf::Vector2f &velocity);
    void update(const sf::FloatRect &bounds);
    void draw(sf::RenderWindow &window) const;
    sf::FloatRect getBounds() const;
    sf::Color getColor() const;
    void setPosition(const sf::Vector2f &position);
    sf::Vector2f getPosition() const;

private:
    sf::CircleShape shape;
    sf::Vector2f velocity;
    bool hasBounced;
};

#endif // BOLA_HPP
