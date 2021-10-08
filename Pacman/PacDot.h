#pragma once
#include <iostream>

using namespace std;
using namespace System;
using namespace System::Drawing;

class PacDot {
private:
	int x, y, ancho, altura;

public:
	PacDot() {
		x = rand() % 90 + 10;
		y = rand() % 45 + 5;
		ancho = 1;
		altura = 1;
	}
	~PacDot() {}

	void dibujar() {
		Console::ForegroundColor = ConsoleColor::Red;
		Console::SetCursorPosition(x, y); cout << char(4);
		Console::ForegroundColor = ConsoleColor::White;
	}

	void borrar() {
		Console::SetCursorPosition(x, y); cout << " ";
	}

	Rectangle getRectangle() {
		return Rectangle(x, y, ancho, altura);
	}
};
