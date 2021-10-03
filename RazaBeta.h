#pragma once
#include "SuperOvni.h"

class RazaBeta : public SuperOvni
{
public:
	RazaBeta() : SuperOvni() {
		x = 35;
		y = 1;
		alto = 3;
		ancho = 11;
	}

	~RazaBeta() {}

	void borrar() {
		Console::SetCursorPosition(x, y);		cout << "            ";
		Console::SetCursorPosition(x, y + 1);	cout << "            ";
		Console::SetCursorPosition(x, y + 2);	cout << "            ";
	}

	void dibujar() {
		Console::SetCursorPosition(x, y);		cout << R"(   .---.   )";
		Console::SetCursorPosition(x, y + 1);	cout << R"( _/__~0_\_ )";
		Console::SetCursorPosition(x, y + 2);	cout << R"((_________))";
	}
};
