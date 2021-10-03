#pragma once
#include "SuperOvni.h"

class RazaAlfa : public SuperOvni{
public:
	RazaAlfa()  : SuperOvni() {
		alto = 6;
		ancho = 19;
		x = 1;
		y = 1;
	}

	~RazaAlfa() {}

	void borrar() {
		Console::SetCursorPosition(x, y);		cout << "                   ";
		Console::SetCursorPosition(x, y + 1);	cout << "                   ";
		Console::SetCursorPosition(x, y + 2);	cout << "                   ";
		Console::SetCursorPosition(x, y + 3);	cout << "                   ";
		Console::SetCursorPosition(x, y + 4);	cout << "                   ";
	}

	void dibujar() {
		Console::SetCursorPosition(x, y);		cout << R"(      _.---._      )";
		Console::SetCursorPosition(x, y + 1);	cout << R"(    .'       '.    )";
		Console::SetCursorPosition(x, y + 2);	cout << R"(_.-~===========~-._)";
		Console::SetCursorPosition(x, y + 3);	cout << R"((_________________))";
		Console::SetCursorPosition(x, y + 4);	cout << R"(     \_______/     )";
	}
};
