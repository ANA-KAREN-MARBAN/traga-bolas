#ifndef DRAWER_HPP
#define DRAWER_HPP

#include <SFML/Graphics.hpp>
#include "Bola.hpp"
#include "Cocodrilo.hpp"

class Drawer {
public:
    Drawer(sf::RenderWindow& window);
    void drawBackground(const sf::Sprite& background);
    void drawBolas(const std::vector<Bola>& bolas);
    void drawCocodrilos(const Cocodrilo& cocodriloLeft, const Cocodrilo& cocodriloRight);
    void drawScore(const sf::Text& scoreText);
    void drawGameOver(const sf::Text& gameOverText);

private:
    sf::RenderWindow& window;
};

#endif // DRAWER_HPP
