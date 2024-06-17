#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>
#include "Cocodrilo.hpp"
#include "Bola.hpp"

int main() {
    srand(static_cast<unsigned>(time(0)));

    sf::RenderWindow window(sf::VideoMode(800, 600), "Traga Bolas");
    window.setFramerateLimit(60);

    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("assets/images/background.png")) {
        std::cerr << "Error cargando la textura de fondo" << std::endl;
        return -1;
    }
    sf::Sprite background(backgroundTexture);

    Cocodrilo cocodrilo1(sf::Vector2f(200, 300), "assets/images/cocodrilo1.png");
    Cocodrilo cocodrilo2(sf::Vector2f(600, 300), "assets/images/cocodrilo2.png");

    std::vector<Bola> bolas;
    sf::Clock bolaClock;

    int puntuacionCocodrilo1 = 0;
    int puntuacionCocodrilo2 = 0;

    sf::Font font;
    if (!font.loadFromFile("assets/fonts/arial.ttf")) {
        std::cerr << "Error cargando la fuente" << std::endl;
        return -1;
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            cocodrilo1.move(0, -5);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            cocodrilo1.move(0, 5);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            cocodrilo1.move(-5, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            cocodrilo1.move(5, 0);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            cocodrilo2.move(0, -5);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            cocodrilo2.move(0, 5);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            cocodrilo2.move(-5, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            cocodrilo2.move(5, 0);
        }

        if (bolaClock.getElapsedTime().asSeconds() >= 1) {
            bool isPositive = rand() % 2 == 0;
            bolas.push_back(Bola(sf::Vector2f(rand() % 800, rand() % 600), isPositive ? "assets/images/bola.png" : "assets/images/bola_negativa.png", isPositive));
            bolaClock.restart();
        }

        for (auto it = bolas.begin(); it != bolas.end(); ) {
            if (cocodrilo1.getBounds().intersects(it->getBounds())) {
                puntuacionCocodrilo1 += it->isPositive() ? 1 : -1;
                it = bolas.erase(it);
            } else if (cocodrilo2.getBounds().intersects(it->getBounds())) {
                puntuacionCocodrilo2 += it->isPositive() ? 1 : -1;
                it = bolas.erase(it);
            } else {
                ++it;
            }
        }

        window.clear();
        window.draw(background);
        cocodrilo1.update();
        cocodrilo2.update();
        cocodrilo1.draw(window);
        cocodrilo2.draw(window);
        for (auto &bola : bolas) {
            bola.draw(window);
        }

        sf::Text text1("Cocodrilo 1: " + std::to_string(puntuacionCocodrilo1), font, 20);
        text1.setPosition(10, 10);
        text1.setFillColor(sf::Color::White);
        window.draw(text1);

        sf::Text text2("Cocodrilo 2: " + std::to_string(puntuacionCocodrilo2), font, 20);
        text2.setPosition(10, 40);
        text2.setFillColor(sf::Color::White);
        window.draw(text2);

        window.display();
    }

    return 0;
}
