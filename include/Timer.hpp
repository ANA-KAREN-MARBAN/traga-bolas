#ifndef TIMER_HPP
#define TIMER_HPP

#include <SFML/System.hpp>

class Timer {
public:
    Timer();
    float restart(); // Retorna el tiempo transcurrido desde la ultima vez que se llamo a esta funcion
    float getElapsedTime() const;

private:
    sf::Clock clock;
};

#endif // TIMER_HPP
