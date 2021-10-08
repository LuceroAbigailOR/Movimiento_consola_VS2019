#pragma once
#include "SuperClase.h"

class Raton : SuperClase {
public:
	Raton() {
		x = rand() % 80 + 5;
		y = rand() % 45 + 3;
		alto = 1;
		ancho = 7;
	}
	~Raton() {}

	void borrar() {
		Console::SetCursorPosition(x, y); cout << "       ";
	}

	void dibujar() {
		Console::SetCursorPosition(x, y); cout << R"(--(_c'>)";
	}

	void mover() {
		if (x < 1 || x + ancho + dx > 100) dx *= -1;
		x += dx;
	}

	Rectangle getRectangle() {
		return Rectangle(x, y, ancho, alto);
	}
};
