#include "Timer.hpp"

Timer::Timer() {}

float Timer::restart() {
    return clock.restart().asSeconds();
}

float Timer::getElapsedTime() const {
    return clock.getElapsedTime().asSeconds();
}
