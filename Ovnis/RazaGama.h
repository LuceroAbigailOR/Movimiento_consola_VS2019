#pragma once
#include "SuperOvni.h"

class RazaGama : public SuperOvni
{
public:
	RazaGama() : SuperOvni() {
		x = 70;
		y = 1;
		alto = 10;
		ancho = 19;
	}

	~RazaGama() {}

	void borrar() {
		Console::SetCursorPosition(x, y);		cout << "                   ";
		Console::SetCursorPosition(x, y + 1);	cout << "                   ";
		Console::SetCursorPosition(x, y + 2);	cout << "                   ";
		Console::SetCursorPosition(x, y + 3);	cout << "                   ";
		Console::SetCursorPosition(x, y + 4);	cout << "                   ";
		Console::SetCursorPosition(x, y + 5);	cout << "                   ";
		Console::SetCursorPosition(x, y + 6);	cout << "                   ";
		Console::SetCursorPosition(x, y + 7);	cout << "                   ";
		Console::SetCursorPosition(x, y + 8);	cout << "                   ";
		Console::SetCursorPosition(x, y + 9);	cout << "                   ";
	}

	void dibujar() {
		Console::SetCursorPosition(x, y);		cout << R"(         .         )";
		Console::SetCursorPosition(x, y + 1);	cout << R"(         |         )";
		Console::SetCursorPosition(x, y + 2);	cout << R"(      .-"^"-.      )";
		Console::SetCursorPosition(x, y + 3);	cout << R"(     /_....._\     )";
		Console::SetCursorPosition(x, y + 4);	cout << R"( .-"`         `"-. )";
		Console::SetCursorPosition(x, y + 5);	cout << R"((  ooo  ooo  ooo  ))";
		Console::SetCursorPosition(x, y + 6);	cout << R"( '-.,_________,.-' )";
		Console::SetCursorPosition(x, y + 7);	cout << R"(     /       \     )";
		Console::SetCursorPosition(x, y + 8);	cout << R"(   _/         \_   )";
		Console::SetCursorPosition(x, y + 9);	cout << R"(  `"`         `"`  )";
	}
};
