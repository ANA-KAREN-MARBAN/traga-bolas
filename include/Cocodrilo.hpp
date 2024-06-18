#ifndef COCODRILO_HPP
#define COCODRILO_HPP

#include <SFML/Graphics.hpp>

class Cocodrilo {
public:
    Cocodrilo(const sf::Texture& texture, const sf::Vector2f& position, float moveDirection);
    void moveForward();
    void update(float deltaTime);
    void draw(sf::RenderWindow& window) const;
    sf::FloatRect getBounds() const;
    void increaseScore();
    void decreaseScore();
    int getScore() const;

private:
    sf::Sprite sprite;
    sf::Vector2f initialPosition;
    float moveDistance;
    float moveDirection;
    bool moving;
    float animationTime;
    int score;
    sf::Clock moveClock;
};

#endif // COCODRILO_HPP
