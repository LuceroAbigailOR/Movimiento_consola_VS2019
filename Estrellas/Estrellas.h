#pragma once
#include <iostream>

using namespace std;
using namespace System;
using namespace System::Drawing;

class Estrella {
private:
	int x, y;
	int dy;
	int ancho, alto;

public:
	Estrella() {
		x = rand() % 90;
		y = rand() % 20 + 2;
		dy = rand() % 5 + 1;
		ancho = 1;
		alto = 1;
	}

	~Estrella() {}

	int gety() { return this->y; }
	int getdy() { return this->dy; }
	int getalto() { return this->alto; }

	void Borrar() {
		Console::SetCursorPosition(x, y); cout << " ";
	}

	void Mover() {
		y += dy;
	}

	void Imprimir() {
		Console::SetCursorPosition(x, y); cout << "*";
	}

	Rectangle getRectangle() {
		return Rectangle(x, y, ancho, alto);
	}
};
