#pragma once
#include <iostream>
#define derecha 77
#define izquierda 75
#define arriba 80
#define abajo 72

using namespace std;
using namespace System;
using namespace System::Drawing;

class Persona
{
private:
	int x, y, ancho, alto, dx, dy;
public:
	Persona() {
		x = 50;
		y = 45;
		dx = 1;
		dy = 1;
		ancho = 1;
		alto = 1;
	};
	~Persona() {};

	int gety() { return this->y; }

	void Dibujar() {
		Console::ForegroundColor = ConsoleColor::Green;
		Console::SetCursorPosition(x, y); cout << (char)254;
		Console::ForegroundColor = ConsoleColor::White;
	};

	void Borrar() {
		Console::SetCursorPosition(x, y); cout << " ";
	}

	void Mover(char tecla) {
		switch (tecla)
		{
		case arriba: if (this->y < 23)this->y += this->dy; break;
		case abajo: if (this->y > 1)this->y -= this->dy; break;
		case derecha: if (this->x < 100)this->x += this->dx; break;
		case izquierda: if (this->x > 1)this->x -= this->dx; break;
		}
	};

	Rectangle getRectangle() {
		return Rectangle(x, y, ancho, alto);
	}
};
