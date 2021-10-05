#pragma once
#include "Terrestre.h"

class Bus : Terrestre {
private:

public:
	Bus() {
		dx = rand() % 5 + 3; //valor variable mayor que el carro
		x = 78; //empieza en la derecha de la consola
		y = rand() % 45 + 3;
		alto = 4;
		ancho = 21;
	}
	~Bus() {}

	void setx(int x) { this->x = x; }
	int getx() { return this->x; }

	void setdx(int dx) { this->dx = dx; }
	int getdx() { return this->dx; }

	void setancho(int ancho) { this->ancho = ancho; }
	int getancho() { return this->ancho; }

	void borrar() {
		Console::SetCursorPosition(x, y);		cout << "                     ";
		Console::SetCursorPosition(x, y + 1);	cout << "                     ";
		Console::SetCursorPosition(x, y + 2);	cout << "                     ";
	}

	void dibujar() {
		Console::SetCursorPosition(x, y);		cout << R"(    _________________)";
		Console::SetCursorPosition(x, y + 1);	cout << R"(  _/_|[][][][][][][]|)";
		Console::SetCursorPosition(x, y + 2);	cout << R"(|                   |)";
		Console::SetCursorPosition(x, y + 2);	cout << R"( =--OO --------- OO-=)";
	}

	void mover() {
		x -= dx;
	}

	Rectangle getRectangle() {
		return Rectangle(x, y, ancho, alto);
	}
};
