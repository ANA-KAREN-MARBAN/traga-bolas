// Cocodrilo.hpp
#ifndef COCODRILO_HPP
#define COCODRILO_HPP

#include <ncurses.h>


class Cocodrilo {
public:
    Cocodrilo(int y, int x);
    void dibujar(WINDOW *win);
    bool isBocaAbierta() const; // Función para obtener el estado de la boca
private:
    int y_;
    int x_;
    bool bocaAbierta_;
};

#endif // COCODRILO_HPP
