#pragma once
#include "ObjetosMovimientos.h"
#define derecha 77
#define izquierda 75
#define arriba 80
#define abajo 72

class Monigote : Objetos_Movimiento
{
private:
	int vidas;
public:
	Monigote() {
		x = 1; //esquina superior izquierda
		y = 1;
		ancho = 1;
		alto = 2;
		dx = 2;
		dy = 2;
		vidas = 3;
	};
	~Monigote() {};

	int getvidas() { return this->vidas; }

	void setvidas(int vidas) { this->vidas = vidas; }
	void setx(int x) { this->x = x; }
	void sety(int y) { this->y = y; }
	void setdx(int dx) { this->dx = dx; }
	void setdy(int dy) { this->dy = dy; }

	void borrar() {
		Console::SetCursorPosition(x, y);     cout << " ";
		Console::SetCursorPosition(x, y + 1); cout << " ";
	}

	void dibujar() {
		Console::ForegroundColor = ConsoleColor::Yellow;
		Console::SetCursorPosition(x, y);     cout << "0";
		Console::SetCursorPosition(x, y + 1); cout << "+";
		Console::ForegroundColor = ConsoleColor::White;
	};

	void mover(char tecla) {
		switch (tecla)
		{
		case arriba: if (y + alto + dy < 50) y += dy; break;
		case abajo: if (y > 1) y -= dy; break;
		case derecha: if (x + dx + ancho < 100) x += dx; break;
		case izquierda: if (x > 1) x -= dx; break;
		}
	};

	Rectangle getRectangle() {
		return Rectangle(x, y, ancho, alto);
	}
};
