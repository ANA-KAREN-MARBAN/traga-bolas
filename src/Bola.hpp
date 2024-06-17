#ifndef BOLA_HPP
#define BOLA_HPP

#include <SFML/Graphics.hpp>

class Bola {
public:
    Bola(sf::Vector2f position, const std::string &textureFile, bool isPositive);
    void draw(sf::RenderWindow &window);
    sf::FloatRect getBounds() const;
    bool isPositive() const;

private:
    sf::Sprite sprite;
    sf::Texture texture;
    bool positive;
};

#endif // BOLA_HPP
