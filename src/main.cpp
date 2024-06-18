#include <SFML/Graphics.hpp>
#include "Bola.hpp"
#include "Cocodrilo.hpp"
#include <vector>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Traga Bolas");
    sf::Texture backgroundTexture;
    backgroundTexture.loadFromFile("assets/images/background.png");

    sf::Sprite background(backgroundTexture);
    sf::FloatRect backgroundBounds = background.getGlobalBounds();
    background.setOrigin(backgroundBounds.width / 2, backgroundBounds.height / 2);
    background.setPosition(window.getSize().x / 2, window.getSize().y / 2);

    sf::Texture cocodriloTexture1, cocodriloTexture2;
    cocodriloTexture1.loadFromFile("assets/images/cocodrilo1.png");
    cocodriloTexture2.loadFromFile("assets/images/cocodrilo2.png");

    sf::Vector2f leftPosition(backgroundBounds.left + 50, backgroundBounds.top + backgroundBounds.height / 2);
    sf::Vector2f rightPosition(backgroundBounds.left + backgroundBounds.width - 50, backgroundBounds.top + backgroundBounds.height / 2);
    sf::Vector2f bolaPosition1(backgroundBounds.left + 100, backgroundBounds.top + 100);
    sf::Vector2f bolaPosition2(backgroundBounds.left + backgroundBounds.width - 100, backgroundBounds.top + 100);

    Cocodrilo cocodriloLeft(cocodriloTexture1, leftPosition, 2.0f);
    Cocodrilo cocodriloRight(cocodriloTexture2, rightPosition, 2.0f);

    Bola bola1(15.0f, bolaPosition1, sf::Color::Red, sf::Vector2f(50.0f, 50.0f));
    Bola bola2(15.0f, bolaPosition2, sf::Color(128, 0, 128), sf::Vector2f(40.0f, 40.0f));

    std::vector<Bola> bolas = { bola1, bola2 };

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Enter) {
                    cocodriloRight.moveForward();
                }
                if (event.key.code == sf::Keyboard::Space) {
                    cocodriloLeft.moveForward();
                }
            }
        }

        cocodriloLeft.update();
        cocodriloRight.update();

        for (auto& bola : bolas) {
            bola.update(background.getGlobalBounds());

            if (cocodriloLeft.getBounds().intersects(bola.getBounds())) {
                cocodriloLeft.increaseScore();
            }

            if (cocodriloRight.getBounds().intersects(bola.getBounds())) {
                cocodriloRight.increaseScore();
            }
        }

        window.clear();
        window.draw(background);
        cocodriloLeft.draw(window);
        cocodriloRight.draw(window);

        for (const auto& bola : bolas) {
            bola.draw(window);
        }

        window.display();
    }

    return 0;
}
