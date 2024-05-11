#ifndef BOLA_HPP
#define BOLA_HPP

#include <ncurses.h>

class Bola {
public:
    Bola();
    void dibujar(WINDOW *win, int maxY, int maxX);
private:
    int y_;
    int x_;
    bool visible_;
};

#endif // BOLA_HPP
