// src/ventana.cpp
#include <iostream>
#include <string>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <Cocodrilo.hpp> // Cambiado desde <Dibujo.hpp>
#include <Archivo.hpp>
#include <thread>
#include <list>
#include <experimental/random>
using namespace ftxui;
using namespace std;

int main(int argc, char const *argv[])
{
    Archivo cocodriloArchivo("./assets/images/cocodrilo.txt"); // Cambiado desde "./assets/images/alien.txt"

    list<Cocodrilo> cocodrilos; // Cambiado desde dibujos
    // Crear Cocodrilos
    for (size_t i = 0; i < 20; i++)
    {
        Cocodrilo cocodrilo = cocodriloArchivo.CrearDibujo(); // Cambiado desde Dibujo d = alien.CrearDibujo();
        cocodrilo.EstablecerPosicion(
            experimental::randint(0,20),
            experimental::randint(0,20)
        );
        cocodrilos.push_back(cocodrilo);
    }

    // Crear Bolas
    for (int i = 0; i < 20; i++)
    {
        list<string> bolas;
        bolas.push_back("● ● ●");
        bolas.push_back("●     ●");
        bolas.push_back("● ● ●");

        Bolas bola(
            bolas,
            experimental::randint(0,50), // PosX
            experimental::randint(0,50)  // PosY
        );
        cocodrilos.push_back(bola);
    }    

    auto Pantalla = Screen::Create(
        Dimension::Full(), 
        Dimension::Full()
    );

    while(true){
        Pantalla.Clear();
        this_thread::sleep_for(0.1s);

        // Actualizar
        for (auto &&cocodrilo : cocodrilos) // Cambiado desde i
        {
            cocodrilo.DesplazarX(experimental::randint(-1,1));
            cocodrilo.DesplazarY(experimental::randint(-1,1));
        }

        // Dibujar
        for (auto &&cocodrilo : cocodrilos) // Cambiado desde i
        {
            cocodrilo.Dibujar(Pantalla);
        }
        
        Pantalla.Print();
        cout<<Pantalla.ResetPosition();          
    }

    return 0;
}
