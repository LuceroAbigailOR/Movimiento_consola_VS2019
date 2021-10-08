#pragma once
#include "Objetos_Movimiento.h"

class Fantasma : Objetos_Movimiento {
public:
	Fantasma() {
		dx = rand() % 3 + 1;
		dy = rand() % 3 + 1;
		x = rand() % 90 + 6;
		y = rand() % 40 + 6;
		alto = 4;
		ancho = 5;
	}
	~Fantasma() {}

	void borrar() {
		Console::SetCursorPosition(x, y);		cout << "     ";
		Console::SetCursorPosition(x, y + 1);	cout << "     ";
		Console::SetCursorPosition(x, y + 2);	cout << "     ";
		Console::SetCursorPosition(x, y + 3);	cout << "     ";
	}

	void dibujar(int color) {
		Console::ForegroundColor = ConsoleColor(color);

		Console::SetCursorPosition(x, y);		cout << R"( ___ )";
		Console::SetCursorPosition(x, y + 1);	cout << R"(/o o\)";
		Console::SetCursorPosition(x, y + 2);	cout << R"(|   |)";
		Console::SetCursorPosition(x, y + 3);	cout << R"(|,,,|)";
		Console::ForegroundColor = ConsoleColor::White;
	}

	void mover() {
		if (x < 3 || x + ancho + dx > 90) dx *= -1;
		if (y < 3 || y + alto + dy > 40) dy *= -1;
		y += dy;
		x += dx;
	}

	Rectangle getRectangle() {
		return Rectangle(x, y, ancho, alto);
	}
};
