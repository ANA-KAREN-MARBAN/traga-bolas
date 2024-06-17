#ifndef COCODRILO_HPP
#define COCODRILO_HPP

#include <SFML/Graphics.hpp>

class Cocodrilo {
public:
    Cocodrilo(sf::Vector2f position, const std::string &textureFile);
    void move(float offsetX, float offsetY);
    void draw(sf::RenderWindow &window);
    void update();
    sf::FloatRect getBounds() const;

private:
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Clock clock;
    float frameTime = 0.1f;
    int currentFrame = 0;
    int numFrames = 4;
    int frameWidth = 64;
    int frameHeight = 64;
};

#endif // COCODRILO_HPP
