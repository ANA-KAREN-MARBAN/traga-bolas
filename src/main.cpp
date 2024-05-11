// src/main.cpp
#include <iostream>
#include <string>
#include <thread>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/string.hpp>
#include <ftxui/screen/terminal.hpp>
#include <fstream>
#include <Cocodrilo.hpp> // Cambiado desde #include <Dibujo.hpp>

using namespace std;
using namespace ftxui;

int main(int argc, char const *argv[])
{
    Archivo dCocodrilo1("./assets/images/cocodrilo1.txt"); // Cambiado desde dTanque
    Archivo dCocodrilo2("./assets/images/cocodrilo2.txt"); // Cambiado desde dAlien
    Archivo dBolas("./assets/images/bolas.txt"); // Cambiado desde dBloque

    int fotograma = 0;
    while(true)
    {
        fotograma++;
        Element cocodrilo1 = dCocodrilo1.GetElement() | bold | color(Color::Green); // Cambiado desde personaje
        Element cocodrilo2 = dCocodrilo2.GetElement() | bold | color(Color::Green); // Cambiado desde tanque
        Element bolas = dBolas.GetElement() | bold | color(Color::Blue); // Cambiado desde lienzo
        Element lienzo = hbox({cocodrilo1, cocodrilo2, bolas}); // Cambiado desde hbox({personaje , tanque, dAlien.GetElement() })

        Screen pantalla = Screen::Create(
            Dimension::Full(),
            Dimension::Fit(lienzo));
        
        Render(pantalla, lienzo);
        pantalla.Print();
        cout<<pantalla.ResetPosition();

        this_thread::sleep_for(0.1s);
    }

    return 0;
}
