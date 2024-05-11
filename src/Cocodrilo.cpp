#include "Cocodrilo.hpp"

Cocodrilo::Cocodrilo(int y, int x) : y_(y), x_(x), bocaAbierta_(true) {}

void Cocodrilo::dibujar(WINDOW *win) {
    if (bocaAbierta_) {
        mvwprintw(win, y_, x_, " ______");
        mvwprintw(win, y_+1, x_, " \\ oo /");
        mvwprintw(win, y_+2, x_, " / . . \\");
         mvwprintw(win, y_+3, x_, "          ");
        mvwprintw(win, y_+4, x_, " / . . \\");
        mvwprintw(win, y_+5, x_, " / oo \\");
        mvwprintw(win, y_+6, x_, " ------");
    } else {
        mvwprintw(win, y_, x_, " ______");
        mvwprintw(win, y_+1, x_, " \\ oo /");
        mvwprintw(win, y_+2, x_, " / . . \\");
        mvwprintw(win, y_+3, x_, "           ");
        mvwprintw(win, y_+4, x_, "/ . . \\");
        mvwprintw(win, y_+5, x_, " / oo \\");
        mvwprintw(win, y_+6, x_, " ------");
    }
}

bool Cocodrilo::isBocaAbierta() const {
    return bocaAbierta_;
}
