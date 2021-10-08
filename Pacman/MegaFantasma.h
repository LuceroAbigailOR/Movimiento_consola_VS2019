#pragma once
#include "Objetos_Movimiento.h"

class MegaFantasma : Objetos_Movimiento {
public:
	MegaFantasma() {
		dx = 4;//valor variable mayor que el pacman
		dy = 1;
		x = 5; //empieza en la izquierda de la consola
		y = rand() % 40 + 6;
		alto = 4;
		ancho = 5;
	}
	~MegaFantasma() {}

	void borrar() {
		Console::SetCursorPosition(x, y);		cout << "     ";
		Console::SetCursorPosition(x, y + 1);	cout << "     ";
		Console::SetCursorPosition(x, y + 2);	cout << "     ";
		Console::SetCursorPosition(x, y + 3);	cout << "     ";
	}

	void dibujar() {
		Console::ForegroundColor = ConsoleColor::Red;
		Console::SetCursorPosition(x, y);		cout << R"( ___ )";
		Console::SetCursorPosition(x, y + 1);	cout << R"(/o o\)";
		Console::SetCursorPosition(x, y + 2);	cout << R"(|   |)";
		Console::SetCursorPosition(x, y + 3);	cout << R"(|,,,|)";
		Console::ForegroundColor = ConsoleColor::White;
	}

	void mover() {
		if (x < 4 || x + ancho + dx > 90) dx *= -1;
		x += dx;
	}

	Rectangle getRectangle() {
		return Rectangle(x, y, ancho, alto);
	}
};
