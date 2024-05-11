#include <iostream>
#include <ncurses.h>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include "Cocodrilo.hpp"

// Función para inicializar la ventana de ncurses
void init_ncurses() {
    initscr(); // Inicializa la pantalla
    cbreak(); // Deshabilita el búfer de línea
    noecho(); // No mostrar caracteres escritos
    curs_set(0); // Oculta el cursor
    timeout(0); // Configura el tiempo de espera de getch() en modo no bloqueante
}

// Función para generar una posición aleatoria en la pantalla
void generar_posicion(int &x, int &y) {
    x = rand() % COLS;
    y = rand() % LINES;
}

int main() {
    init_ncurses(); // Inicializa la ventana de ncurses

    srand(time(NULL)); // Inicializa la semilla aleatoria

    // Crear nuevos objetos Cocodrilo
    Cocodrilo cocodrilo1(LINES / 2, COLS / 4);
    Cocodrilo cocodrilo2(LINES / 2, 3 * COLS / 4);

    int puntuacionCocodrilo1 = 0;
    int puntuacionCocodrilo2 = 0;

    bool mostrarCocodrilo1 = true;
    bool mostrarCocodrilo2 = true;
    bool mostrarBolas = true;

    while (true) {
        clear(); // Limpia la pantalla

        // Dibujar bolas blancas y negras en posiciones aleatorias
        if (mostrarBolas) {
            for (int i = 0; i < 50; ++i) {
                int x, y;
                generar_posicion(x, y);
                attron(COLOR_PAIR(1)); // Establece el color a blanco
                mvprintw(y, x, "o");
                attroff(COLOR_PAIR(1));

                generar_posicion(x, y);
                attron(COLOR_PAIR(2)); // Establece el color a negro
                mvprintw(y, x, "o");
                attroff(COLOR_PAIR(2));
            }
        }

        // Alternar entre mostrar y ocultar los cocodrilos
        if (mostrarCocodrilo1) {
            cocodrilo1.dibujar(stdscr);
        }
        if (mostrarCocodrilo2) {
            cocodrilo2.dibujar(stdscr);
        }

        // Contar las bolas comidas por cada cocodrilo
        if (cocodrilo1.isBocaAbierta()) {
            ++puntuacionCocodrilo1;
        }
        if (cocodrilo2.isBocaAbierta()) {
            ++puntuacionCocodrilo2;
        }

        // Imprimir la puntuación de cada cocodrilo
        mvprintw(1, 1, "Cocodrilo 1: %d bolas comidas", puntuacionCocodrilo1);
        mvprintw(2, 1, "Cocodrilo 2: %d bolas comidas", puntuacionCocodrilo2);

        // Refrescar la pantalla para mostrar los cambios
        refresh();

        // Esperar un tiempo antes de la próxima actualización
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        // Alternar entre mostrar y ocultar los cocodrilos en cada iteración
        mostrarCocodrilo1 = !mostrarCocodrilo1;
        mostrarCocodrilo2 = !mostrarCocodrilo2;
        mostrarBolas = !mostrarBolas;
    }

    endwin(); // Restaura la configuración de la terminal al salir
    return 0;
}
