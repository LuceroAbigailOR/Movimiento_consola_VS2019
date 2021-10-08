#include <conio.h>
#include "Controlador.h"

int main() {
	srand(time(NULL));
	Console::SetWindowSize(100, 50);
	char tecla;

	Controlador* c = new Controlador();
	c->dibujarTodo();

	while (1) {
		Console::CursorVisible = false;
		//Borrar
		c->borrarTodo();

		//Colision
		c->colision();
		c->insertar_ratones_N();

		//Mover
		c->moverTodo();

		if (c->ganaste_juego() == true) {
			Console::Clear();
			cout << "\nGanaste el juego" << endl;
			_sleep(200);
			_getch();
			break;
		}

		if (_kbhit()) { //Si se presiona una tecla
			tecla = _getch();
			tecla = toupper(tecla);
			c->getGato()->mover(tecla);
		}

		//Dibujar
		c->dibujarTodo();
		_sleep(200);
	}
	_getch();
	delete c;
	return 0;
}
