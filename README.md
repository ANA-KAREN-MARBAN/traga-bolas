Juego Traga Bolas 

Objetivo:

El objetivo de este proyecto es desarrollar un juego de Traga Bolas en formato ASCII Art, donde dos cocodrilos compiten por comer la mayor cantidad de bolas de colores que caen aleatoriamente por la pantalla.

Exploración:

bin/: Directorio que contiene los ejecutables del proyecto.
src/: Contiene el código fuente del juego.
include/: Archivos de cabecera.
assets/: Directorio que contiene los recursos del juego, como los caracteres ASCII Art para representar los cocodrilos y las bolas.
docs/: Documentación del proyecto.


Descripción:

El juego Traga Bolas consiste en dos cocodrilos representados con arte ASCII que compiten por comer la mayor cantidad de bolas de colores que caen desde la parte superior de la pantalla. Los cocodrilos pueden abrir y cerrar sus bocas para atrapar las bolas mientras se desplazan horizontalmente por la pantalla. El juego termina cuando las bolas se acumulan en la parte inferior de la pantalla y los cocodrilos no pueden comer más.

Funcionamiento:

Cocodrilo.hpp y Cocodrilo.cpp: Definen la clase Cocodrilo, que representa a un cocodrilo en el juego. La clase incluye métodos para dibujar el cocodrilo con la boca abierta o cerrada, moverlo horizontalmente por la pantalla y detectar colisiones con las bolas.

Bola.hpp y Bola.cpp: Definen la clase Bola, que representa una bola de colores en el juego. La clase incluye métodos para dibujar la bola en la pantalla, moverla hacia abajo y detectar colisiones con los cocodrilos.

main.cpp: Contiene la función principal main, donde se ejecuta la lógica principal del juego Traga Bolas. En el main, se inicializan los objetos de los cocodrilos y las bolas, se crea una ventana de pantalla utilizando la biblioteca ncurses, y se inicia un bucle principal. Dentro del bucle, se actualiza la posición de los cocodrilos y las bolas, se detectan colisiones y se determina la puntuación de cada cocodrilo. El juego continúa hasta que las bolas se acumulan en la parte inferior de la pantalla.

Instrucciones:
Una vez clonado el repositorio, ejecutar el comando "make run" en la terminal para iniciar el juego Traga Bolas y disfrutar de la competencia entre los dos cocodrilos por comer la mayor cantidad de bolas.
