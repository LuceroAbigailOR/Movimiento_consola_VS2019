#pragma once
#include <iostream>

using namespace std;
using namespace System;
using namespace System::Drawing;

class Bonus {
private:
	int x, y, ancho, altura;

public:
	Bonus() {
		x = rand() % 90 + 10;
		y = rand() % 45 + 5;
		ancho = 1;
		altura = 1;
	}

	~Bonus() {};

	void dibujar() {
		Console::ForegroundColor = ConsoleColor::Blue;
		Console::SetCursorPosition(x, y); cout << char(16);
		Console::ForegroundColor = ConsoleColor::White;
	}

	void borrar() {
		Console::SetCursorPosition(x, y); cout << " ";
	}

	Rectangle getRectangle() {
		return Rectangle(x, y, altura, ancho);
	}
};
