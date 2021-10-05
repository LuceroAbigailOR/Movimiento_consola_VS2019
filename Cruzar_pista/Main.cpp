#include <conio.h>
#include "Juego.h"

int main() {
	srand(time(NULL));
	Console::SetWindowSize(100, 50);
	char tecla; char opcion;

	Juego* c = new Juego();
	c->dibujarTodo();

	while (1) {
		Console::CursorVisible = false;
		//Borrar
		c->borrarTodo();

		//Colision
		c->final_consola();
		c->colision();
		//Mover
		c->moverTodo();
		if (_kbhit()) { //Si se presiona una tecla
			opcion = _getch();
			opcion = toupper(opcion);
			if (opcion == 'A' || opcion == 'a') c->addBicicleta();
			if (opcion == 'S' || opcion == 's') c->addCarro();
			if (opcion == 'D' || opcion == 'd') c->addBus();
		}

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
			c->getPersona()->Mover(tecla);
		}

		if (c->fin_del_juego() == true) {
			Console::Clear();
			cout << "\nFin del juego" << endl;
			_sleep(200);
			_getch();
			break;
		}

		//Dibujar
		c->dibujarTodo();
		_sleep(200);
	}
	_getch();
	delete c;
	return 0;
}
