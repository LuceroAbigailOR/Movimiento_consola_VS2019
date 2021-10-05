#pragma once
#include <iostream>
#define derecha 77
#define izquierda 75

using namespace std;
using namespace System;
using namespace System::Drawing;

class Monigote
{
private:
	int x, y, ancho, alto, dx, dy;
public:
	Monigote() {
		x = 50;
		y = 40;
		dx = 1;
		ancho = 1;
		alto = 2;
	};
	~Monigote() {};

	void Imprimir() {
		Console::SetCursorPosition(x, y); cout << (char)64;
		Console::SetCursorPosition(x, y + 1); cout << (char)197;
	};

	void Borrar() {
		Console::SetCursorPosition(x, y); cout << " ";
		Console::SetCursorPosition(x, y + 1); cout << " ";
	}

	void Mover(char tecla) {
		switch (tecla)
		{
		case derecha: if (this->x < 100)this->x += this->dx; break;
		case izquierda: if (this->x > 1)this->x -= this->dx; break;
		}
	};

	Rectangle getRectangle() {
		return Rectangle(x, y, ancho, alto);
	}
};
