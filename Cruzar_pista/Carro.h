#pragma once
#include "Terrestre.h"

class Carro : Terrestre {
private:

public:
	Carro() {
		dx = rand() % 3 + 2; //valor variable
		x = 1; //empieza en la izquierda de la consola
		y = rand() % 45 + 3;
		alto = 3;
		ancho = 11;
	}
	~Carro() {}

	void setx(int x) { this->x = x; }
	int getx() { return this->x; }

	void setdx(int dx) { this->dx = dx; }
	int getdx() { return this->dx; }

	void setancho(int ancho) { this->ancho = ancho; }
	int getancho() { return this->ancho; }

	void borrar() {
		Console::SetCursorPosition(x, y);		cout << "           ";
		Console::SetCursorPosition(x, y + 1);	cout << "           ";
		Console::SetCursorPosition(x, y + 2);	cout << "           ";
	}

	void dibujar() {
		Console::SetCursorPosition(x, y);		cout << R"(_______|~\_)";
		Console::SetCursorPosition(x, y + 1);	cout << R"([______|_|-)";
		Console::SetCursorPosition(x, y + 2);	cout << R"((_)  (_)   )";
	}

	void mover() {
		x += dx;
	}

	Rectangle getRectangle() {
		return Rectangle(x, y, ancho, alto);
	}
};
