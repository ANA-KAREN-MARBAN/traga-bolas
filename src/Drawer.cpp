#include "Drawer.hpp"

Drawer::Drawer(sf::RenderWindow& window) : window(window) {}

void Drawer::drawBackground(const sf::Sprite& background) {
    window.draw(background);
}

void Drawer::drawBolas(const std::vector<Bola>& bolas) {
    for (const auto& bola : bolas) {
        bola.draw(window);
    }
}

void Drawer::drawCocodrilos(const Cocodrilo& cocodriloLeft, const Cocodrilo& cocodriloRight) {
    cocodriloLeft.draw(window);
    cocodriloRight.draw(window);
}

void Drawer::drawScore(const sf::Text& scoreText) {
    window.draw(scoreText);
}

void Drawer::drawGameOver(const sf::Text& gameOverText) {
    window.draw(gameOverText);
}
