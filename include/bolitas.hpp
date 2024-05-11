// include/Bolas.hpp
#pragma once
#include <string>
#include <list>
#include <ftxui/screen/screen.hpp>
using namespace std;

class Bolas {
private:
    int posicionX;
    int posicionY;
    list<string> contenido;

public:
    Bolas() {
        this->posicionX = 0;
        this->posicionY = 0;
    }

    Bolas(list<string> contenido, int posicionX, int posicionY) {
        this->contenido = contenido;
        this->posicionX = posicionX;
        this->posicionY = posicionY;
    }

    void Dibujar(ftxui::Screen &Pantalla) {
        int posicionPalabraY = 0;
        for (auto &&linea : contenido) {
            int posicionPalabraX = 0;
            for (auto &&letra : linea) {
                int posicionFinalX = this->posicionX + posicionPalabraX;
                int posicionFinalY = this->posicionY + posicionPalabraY;

                Pantalla.PixelAt(posicionFinalX, posicionFinalY).character = letra;
                posicionPalabraX++;
            }
            posicionPalabraY++;
        }
    }

    void DesplazarX(int distancia) {
        posicionX += distancia;
    }

    void DesplazarY(int distancia) {
        posicionY += distancia;
    }

    void EstablecerPosicion(int x, int y) {
        this->posicionX = x;
        this->posicionY = y;
    }

    ~Bolas() {}
};
