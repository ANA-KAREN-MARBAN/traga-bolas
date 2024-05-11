#include "Bola.hpp"

Bola::Bola() : visible_(true) {}

void Bola::dibujar(WINDOW *win, int maxY, int maxX) {
    if (visible_) {
        mvwprintw(win, y_, x_, "O");
    } else {
        mvwprintw(win, y_, x_, " ");
    }
}
