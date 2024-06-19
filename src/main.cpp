#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Bola.hpp"
#include "Cocodrilo.hpp"
#include "SoundManager.hpp"
#include "Drawer.hpp"
#include "Timer.hpp"
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Traga Bolas");

    SoundManager soundManager;
    Drawer drawer(window);
    Timer timer;

    // Cargar la textura del fondo
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("assets/images/background.png")) {
        return -1;
    }

    sf::Sprite background(backgroundTexture);
    sf::FloatRect backgroundBounds = background.getGlobalBounds();
    background.setOrigin(backgroundBounds.width / 2, backgroundBounds.height / 2);
    background.setPosition(window.getSize().x / 2, window.getSize().y / 2);

    // Cargar las texturas de los cocodrilos
    sf::Texture cocodriloTexture1, cocodriloTexture2;
    if (!cocodriloTexture1.loadFromFile("assets/images/cocodrilo1.png") ||
        !cocodriloTexture2.loadFromFile("assets/images/cocodrilo2.png")) {
        return -1;
    }

    sf::Vector2f leftPosition(backgroundBounds.left + 100, window.getSize().y / 2); // Ajuste de posición inicial para cocodrilo morado
    sf::Vector2f rightPosition(backgroundBounds.left + backgroundBounds.width - 50, window.getSize().y / 2); // Ajuste de posición inicial para cocodrilo rojo

    Cocodrilo cocodriloLeft(cocodriloTexture1, leftPosition, 100.0f); // Avanza a la derecha
    Cocodrilo cocodriloRight(cocodriloTexture2, rightPosition, -100.0f); // Avanza a la izquierda

    std::vector<Bola> bolas;
    const sf::Vector2f bolaVelocity(0.0f, 0.15f); // Velocidad más lenta de las bolas

    sf::Font font;
    if (!font.loadFromFile("assets/fonts/arial.ttf")) {
        return -1;
    }

    sf::Text scoreText;
    scoreText.setFont(font);
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(window.getSize().x / 2 - 50, 10);

    bool gameOver = false;
    std::string winner;

    float spawnTimer = 0.0f;

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

        float deltaTime = timer.restart();
        spawnTimer += deltaTime;

        if (spawnTimer >= 0.09f) { // Aumentar el tiempo de spawn para ralentizar la generación de bolas
            float xPos = static_cast<float>(std::rand() % static_cast<int>(backgroundBounds.width / 2) + backgroundBounds.left + backgroundBounds.width / 4);
            float yPos = backgroundBounds.top + 50;
            sf::Color color = (std::rand() % 2 == 0) ? sf::Color::Red : sf::Color(128, 0, 128);
            bolas.emplace_back(15.0f, sf::Vector2f(xPos, yPos), color, bolaVelocity);
            spawnTimer = 0.0f;
        }

        cocodriloLeft.update(deltaTime);
        cocodriloRight.update(deltaTime);

        for (auto& bola : bolas) {
            bola.update(background.getGlobalBounds());

            if (cocodriloLeft.getBounds().intersects(bola.getBounds())) {
                if (bola.getColor() == sf::Color(128, 0, 128)) {
                    cocodriloLeft.increaseScore();
                    soundManager.playMasSound(); // Reproducir sonido de ganancia de puntos
                } else {
                    cocodriloLeft.decreaseScore();
                    soundManager.playMenosSound(); // Reproducir sonido de pérdida de puntos
                }
                bola.setPosition(sf::Vector2f(-100, -10)); // Mover la bola fuera de la pantalla
            }

            if (cocodriloRight.getBounds().intersects(bola.getBounds())) {
                if (bola.getColor() == sf::Color::Red) {
                    cocodriloRight.increaseScore();
                    soundManager.playMasSound(); // Reproducir sonido de ganancia de puntos
                } else {
                    cocodriloRight.decreaseScore();
                    soundManager.playMenosSound(); // Reproducir sonido de pérdida de puntos
                }
                bola.setPosition(sf::Vector2f(-100, -100)); // Mover la bola fuera de la pantalla
            }
        }

        // Eliminar bolas fuera de la pantalla
        bolas.erase(std::remove_if(bolas.begin(), bolas.end(), [&window](const Bola& bola) {
            return bola.getPosition().y < -100 || bola.getPosition().y > window.getSize().y + 100; // Límites arbitrarios para eliminar bolas fuera de la pantalla
        }), bolas.end());

        // Verificar condiciones de fin de juego
        if (!gameOver) {
            if (cocodriloLeft.getScore() >= 10) {
                gameOver = true;
                winner = "Gana el jugador uno";
                soundManager.playGanoSound(); // Reproducir sonido de victoria
            } else if (cocodriloRight.getScore() >= 10) {
                gameOver = true;
                winner = "Gana el jugador dos";
                soundManager.playGanoSound(); // Reproducir sonido de victoria
            }
        }

        // Dibujar en pantalla
        window.clear();
        drawer.drawBackground(background);
        drawer.drawBolas(bolas);
        drawer.drawCocodrilos(cocodriloLeft, cocodriloRight);

        if (!gameOver) {
            scoreText.setString("Jugador 1: " + std::to_string(cocodriloLeft.getScore()) + " Jugador 2: " + std::to_string(cocodriloRight.getScore()));
            drawer.drawScore(scoreText);
        } else {
            sf::Text gameOverText;
            gameOverText.setFont(font);
            gameOverText.setCharacterSize(48);
            gameOverText.setFillColor(sf::Color::White);
            gameOverText.setString(winner);
            gameOverText.setPosition(window.getSize().x / 2 - gameOverText.getGlobalBounds().width / 2, window.getSize().y / 2);
            drawer.drawGameOver(gameOverText);
        }

        window.display();
    }

    return 0;
}
