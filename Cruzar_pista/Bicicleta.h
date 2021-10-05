#pragma once
#include "Terrestre.h"

class Bicicleta : Terrestre {
private:

public:
	Bicicleta() {
		dx = 1; //valor variable mayor que el carro
		x = 78; //empieza en la derecha de la consola
		y = rand() % 45 + 3;
		alto = 2;
		ancho = 6;
	}
	~Bicicleta() {}

	void borrar() {
		Console::SetCursorPosition(x, y);		cout << "      ";
		Console::SetCursorPosition(x, y + 1);	cout << "      ";
		Console::SetCursorPosition(x, y + 2);	cout << "      ";
	}

	void dibujar() {
		if (dx < 0) {
			Console::SetCursorPosition(x, y);		cout << R"( /_.. )";
			Console::SetCursorPosition(x, y + 1);	cout << R"((o)(o))";
		}
		else
		{
			Console::SetCursorPosition(x, y);		cout << R"( .._\ )";
			Console::SetCursorPosition(x, y + 1);	cout << R"((o)(o))";
		}
	}
	void mover() {
		if (x < 1 || x + ancho + dx > 100) dx *= -1;
		x += dx;
	}

	void cambiar_direccion() {
		dx *= -1;
	}

	Rectangle getRectangle() {
		return Rectangle(x, y, ancho, alto);
	}
};
