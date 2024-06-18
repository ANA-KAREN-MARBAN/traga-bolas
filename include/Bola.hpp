#ifndef BOLA_HPP
#define BOLA_HPP

#include <SFML/Graphics.hpp>

class Bola {
public:
    Bola(float radius, const sf::Vector2f& position, const sf::Color& color, const sf::Vector2f& velocity);
    void update(const sf::FloatRect& bounds);
    void draw(sf::RenderWindow& window) const;
    sf::FloatRect getBounds() const;

private:
    sf::CircleShape shape;
    sf::Vector2f velocity;
};

#endif // BOLA_HPP
