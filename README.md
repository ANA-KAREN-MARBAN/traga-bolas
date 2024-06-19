# Juego Traga Bolas

Objetivo:
El objetivo de este proyecto es desarrollar un juego de Traga Bolas utilizando la biblioteca SFML, donde dos cocodrilos compiten por comer la mayor cantidad de bolas de colores que caen aleatoriamente por la pantalla.

Exploración del Proyecto:
bin/: Directorio que contiene los ejecutables del proyecto.
src/: Contiene el código fuente del juego.
include/: Archivos de cabecera.
assets/: Directorio que contiene los recursos del juego, como las imágenes y sonidos necesarios para representar los cocodrilos y las bolas.
docs/: Documentación del proyecto.
Descripción:
El juego Traga Bolas consiste en dos cocodrilos representados con sprites que compiten por comer la mayor cantidad de bolas de colores que caen desde la parte superior de la pantalla. Los cocodrilos pueden moverse hacia adelante para atrapar las bolas mientras estas caen. El juego termina cuando uno de los cocodrilos alcanza 10 puntos.

Funcionamiento:
Cocodrilo.hpp y Cocodrilo.cpp:

Definen la clase Cocodrilo, que representa a un cocodrilo en el juego.
La clase incluye métodos para dibujar el cocodrilo, moverlo horizontalmente, manejar la animación, y detectar colisiones con las bolas.
Los cocodrilos pueden ganar o perder puntos al atrapar bolas de su color o del color del adversario.
Bola.hpp y Bola.cpp:

Definen la clase Bola, que representa una bola de colores en el juego.
La clase incluye métodos para dibujar la bola en la pantalla, moverla hacia abajo y detectar colisiones con los cocodrilos.
Las bolas rebotan una vez antes de ser removidas de la pantalla.
main.cpp:

Contiene la función principal main, donde se ejecuta la lógica principal del juego Traga Bolas.
En el main, se inicializan los objetos de los cocodrilos y las bolas, se crea una ventana de pantalla utilizando la biblioteca SFML, y se inicia un bucle principal.
Dentro del bucle, se actualiza la posición de los cocodrilos y las bolas, se detectan colisiones y se determina la puntuación de cada cocodrilo.
El juego continúa hasta que uno de los cocodrilos alcanza 10 puntos.
Instrucciones:
Clonar el repositorio:

sh
Copiar código
git clone https://github.com/usuario/traga-bolas.git
cd traga-bolas
Compilar el proyecto:

sh
Copiar código
make
Ejecutar el juego:

sh
Copiar código
make run
Controles:
Jugador 1 (Cocodrilo Izquierdo):

Presiona la tecla Espacio para mover el cocodrilo hacia adelante.
Jugador 2 (Cocodrilo Derecho):

Presiona la tecla Enter para mover el cocodrilo hacia adelante.
Requisitos:
Biblioteca SFML instalada en el sistema.
Recursos:
assets/images/: Contiene las imágenes de los cocodrilos y el fondo del juego.
assets/fonts/: Contiene las fuentes usadas para mostrar el texto en el juego.
assets/music/: Contiene los archivos de sonido para efectos de juego (ganar, perder puntos).
Documentación:
Para más detalles sobre la implementación y la estructura del código, revisa la documentación en el directorio docs/.