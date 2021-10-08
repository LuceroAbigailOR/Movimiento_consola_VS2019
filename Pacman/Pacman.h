#pragma once
#include "Objetos_Movimiento.h"
#define derecha 77
#define izquierda 75
#define arriba 80
#define abajo 72

class Pacman : Objetos_Movimiento
{
private:
	int vidas;
public:
	Pacman() {
		x = 1; //esquina superior izquierda
		y = 1;
		ancho = 5;
		alto = 4;
		dx = 2;
		dy = 2;
		vidas = 3;
	};
	~Pacman() {};

	int getvidas() { return this->vidas; }

	void setvidas(int vidas) { this->vidas = vidas; }
	void setx(int x) { this->x = x; }
	void sety(int y) { this->y = y; }
	void setdx(int dx) { this->dx = dx; }
	void setdy(int dy) { this->dy = dy; }

	void borrar() {
		Console::SetCursorPosition(x, y);     cout << "     ";
		Console::SetCursorPosition(x, y + 1); cout << "     ";
		Console::SetCursorPosition(x, y + 2); cout << "     ";
		Console::SetCursorPosition(x, y + 3); cout << "     ";
	}

	void dibujar() {
		Console::ForegroundColor = ConsoleColor::Yellow;
		Console::SetCursorPosition(x, y);     cout << R"( __  )";
		Console::SetCursorPosition(x, y + 1); cout << R"(/ o\ )";
		Console::SetCursorPosition(x, y + 2); cout << R"(|   <)";
		Console::SetCursorPosition(x, y + 3); cout << R"(\__/ )";
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

	void aumentarVelocidad() { //aumenta velocidad al doble
		if (dx > 0)dx*=2;
		else dx--;

		if (dy > 0)dy*=2;
		else dy--;
	}
	Rectangle getRectangle() {
		return Rectangle(x, y, ancho, alto);
	}
};
