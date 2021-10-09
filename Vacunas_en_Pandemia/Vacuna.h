#pragma once
#include "ObjetosMovimientos.h"

class Vacuna : Objetos_Movimiento {
public:
	Vacuna() {
		dx = 2;
		dy = 2;
		x = rand() % 90 + 6;
		y = rand() % 40 + 6;
		alto = 1;
		ancho = 4;
	}
	~Vacuna() {}

	void borrar() {
		Console::SetCursorPosition(x, y); cout << "    ";
	}

	void dibujar() {
		Console::ForegroundColor = ConsoleColor::Cyan;
		Console::SetCursorPosition(x, y); cout << R"(|->|)";
		Console::ForegroundColor = ConsoleColor::White;
	}

	void mover(int direccion) {
		if (direccion % 2 == 0) {
			if (x < 3 || x + ancho + dx > 90) dx *= -1;
			x += dx;
		}
		else {
			if (y < 3 || y + alto + dy > 40) dy *= -1;
			y += dy;
		}
	}

	Rectangle getRectangle() {
		return Rectangle(x, y, ancho, alto);
	}
};
