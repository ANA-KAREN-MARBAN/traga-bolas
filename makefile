bin/tragabolas : src/main.cpp include/Cocodrilo.hpp include/Bolas.hpp
	g++ src/main.cpp -o bin/tragabolas -std=c++2a -lftxui-screen -lftxui-component -lftxui-dom -Iinclude

bin/test : src/tui_test.cpp include/Cocodrilo.hpp
	g++ src/tui_test.cpp -o bin/test -std=c++2a -lftxui-screen -lftxui-component -lftxui-dom -Iinclude

bin/ventana : src/ventana.cpp include/Cocodrilo.hpp include/Bolas.hpp
	g++ src/ventana.cpp -o bin/ventana -std=c++2a -lftxui-screen -lftxui-component -lftxui-dom -Iinclude

run : bin/tragabolas
	./bin/tragabolas

runTest : bin/test
	./bin/test

runVentana : bin/ventana
	./bin/ventana
