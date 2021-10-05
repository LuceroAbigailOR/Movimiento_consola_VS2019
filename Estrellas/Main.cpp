#include <conio.h>
#include "Controlador.h"
#include "time.h"
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
		c->final_consola();
		c->colision();
		c->crearEstrellas();
		//Mover
		c->moverTodo();

		if (clock() >= 60000) {//1 minuto acaba la partida
			Console::Clear();
			cout << "Se acabo el tiempo" << endl;
			cout << "Estrellas capturadas: " << c->getCont() << endl;
			_getch();
			break;
		}

		if (_kbhit()) { //Si se presiona una tecla
			tecla = _getch();
			tecla = toupper(tecla);
			c->getMonigote()->Mover(tecla);
		}

		//Dibujar
		c->dibujarTodo();
		_sleep(200);
	}
	_getch();
	delete c;
	return 0;
}
