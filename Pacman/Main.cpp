#include <conio.h>
#include "Controlador.h"
#include "time.h"
#include <cstdlib>

int main() {
	srand((unsigned int)time(NULL));
	Console::SetWindowSize(100, 50);
	char tecla;

	Controlador* c = new Controlador();
	c->dibujarTodo();

	while (1) {
		Console::CursorVisible = false;
		//Borrar
		c->borrarTodo();

		//Mover
		c->moverTodo();

		if (c->ganaste_juego() == true && (clock() < 120000)) {
			Console::Clear();
			cout << "\nGanaste el juego, comiste los 100 PacDots" << endl;
			_sleep(200);
			_getch();
			break;
		}

		if (c->perdiste_juego() == true) {
			Console::Clear();
			cout << "\nPerdiste el juego, se acabaron tus tres vidas" << endl;
			cout << "Cantidad de PacDots que comio el pacman: " << c->numPacDots() << endl;
			_sleep(200);
			_getch();
			break;
		}

		if (clock() >= 120000) {
			system("cls");
			cout << "PERDISTE";
			cout << "El tiempo se acabo"; 
			cout << "Cantidad de PacDots que comio el pacman: " << c->numPacDots() << endl;
			break;
		}

		if (_kbhit()) { //Si se presiona una tecla
			tecla = _getch();
			tecla = toupper(tecla);
			c->getPacman()->mover(tecla);
		}

		//Dibujar
		c->dibujarTodo();
		_sleep(200);
	}
	_getch();
	delete c;
	return 0;
}
