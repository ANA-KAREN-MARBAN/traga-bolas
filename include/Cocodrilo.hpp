#ifndef COCODRILO_HPP
#define COCODRILO_HPP

#include <SFML/Graphics.hpp>

class Cocodrilo {
public:
    Cocodrilo(const sf::Texture& texture, const sf::Vector2f& position, float stepSize);
    void update();
    void draw(sf::RenderWindow& window);
    void animate();
    void moveForward();
    void moveBackward();
    void increaseScore();
    int getScore() const;
    sf::FloatRect getBounds() const;

private:
    sf::Sprite sprite;
    sf::Vector2f initialPosition;
    float stepSize;
    int score;
    int frame;
    sf::Clock animationClock;
};

#endif // COCODRILO_HPP
