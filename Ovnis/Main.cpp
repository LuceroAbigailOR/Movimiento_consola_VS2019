#include "Controladora.h"
#include <conio.h>

void main()
{
	Console::SetWindowSize(90, 50);
	Console::CursorVisible = false;
	Console::SetCursorPosition(32, 20);
	Console::ForegroundColor = ConsoleColor::Green;
	cout << "Comienza la invasion...!!!" << endl;
	Console::SetCursorPosition(32, 21);
	Console::ForegroundColor = ConsoleColor::White;
	cout << "Opcion [A]: Generar ovni de raza alfa" << endl;
	Console::SetCursorPosition(32, 22);
	cout << "La partida empezara en 3 segundos..." << endl;
	_sleep(3000);
	Console::Clear();

	char opcion;
	Controladora* c = new Controladora;
	while (true) {
		Console::CursorVisible = false;
		c->borrarTodo();

		if (c->getCont1() == 2) {
			c->setCont1(0);
			c->addRazaBeta();
		}
		if (c->getCont2() == 2) {
			c->setCont2(0);
			c->addRazaGama();
		}
		if (c->getContTotal() == 10) break;

		if (_kbhit()) { //Si se presiona una tecla
			opcion = _getch();
			opcion = toupper(opcion);
			if (opcion == 'A' || opcion == 'a') c->addRazaAlfa();
		}
		c->final_consola();
		c->moverTodo();
		c->dibujarTodo();
		_sleep(100);
	}

	Console::Clear();
	Console::SetCursorPosition(32, 20);
	Console::ForegroundColor = ConsoleColor::Red;
	cout << "Hemos sido invadidos..." << endl;
	_getch();
}
