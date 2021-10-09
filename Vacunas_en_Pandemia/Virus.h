#pragma once
#include "ObjetosMovimientos.h"

class Virus : Objetos_Movimiento {
public:
	Virus() {
		dx = rand() % 3 + 1;
		dy = rand() % 3 + 1;
		x = rand() % 85 + 6;
		y = rand() % 40 + 6;
		alto = 5;
		ancho = 11;
	}
	~Virus() {}

	void borrar() {
		Console::SetCursorPosition(x, y);		cout << "           ";
		Console::SetCursorPosition(x, y + 1);	cout << "           ";
		Console::SetCursorPosition(x, y + 2);	cout << "           ";
		Console::SetCursorPosition(x, y + 3);	cout << "           ";
		Console::SetCursorPosition(x, y + 4);	cout << "           ";
	}

	void dibujar() {
		Console::ForegroundColor = ConsoleColor::Green;

		Console::SetCursorPosition(x, y);		cout << R"(     q     )";
		Console::SetCursorPosition(x, y + 1);	cout << R"(  o.-o-.o  )";
		Console::SetCursorPosition(x, y + 2);	cout << R"(o-(o o o)-o)";
		Console::SetCursorPosition(x, y + 3);	cout << R"(  o.-o-.o  )";
		Console::SetCursorPosition(x, y + 4);	cout << R"(     b     )";
		Console::ForegroundColor = ConsoleColor::White;
	}

	void mover() {
		if (x < 5 || x + ancho + dx >100) dx *= -1;
		if (y < 3 || y + alto + dy > 50) dy *= -1;
		y += dy;
		x += dx;
	}

	Rectangle getRectangle() {
		return Rectangle(x, y, ancho, alto);
	}
};
