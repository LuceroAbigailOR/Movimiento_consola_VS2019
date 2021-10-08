#pragma once
#include <iostream>
#include "SuperClase.h"

using namespace std;
using namespace System;

class Gato : SuperClase
{
public:
	Gato() {
		x = 50;
		y = 25;
		ancho = 7;
		alto = 3;
	};
	~Gato() {};

	void borrar() {
		Console::SetCursorPosition(x, y); cout << "       ";
		Console::SetCursorPosition(x, y+ 1); cout << "       ";
		Console::SetCursorPosition(x, y+ 2); cout << "       ";
	}

	void mover(char tecla) {
		switch (tecla)
		{
		case 'A':
			if (x > 1)x -= dx; break;
		case 'D':
			if (x + ancho + dx < 100) x += dx; break;
		case 'W':
			if (y > 1)y -= dy; break;
		case 'S':
			if (y + alto + dy < 50) y += dy; break;
		}
	};

	void dibujar() {
		Console::ForegroundColor = ConsoleColor::Yellow;
		Console::SetCursorPosition(x, y);     cout << R"( /\_/\ )";
		Console::SetCursorPosition(x, y + 1); cout << R"(( o.o ))";
		Console::SetCursorPosition(x, y + 2); cout << R"( > ^ < )";
		Console::ForegroundColor = ConsoleColor::White;
	};

	Rectangle getRectangle() {
		return Rectangle(x, y, ancho, alto);
	}
};
