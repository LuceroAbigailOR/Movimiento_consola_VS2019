#pragma once
#include <iostream>

using namespace std;
using namespace System;
using namespace System::Drawing;
class Casa {
private:
	int x, y, alto, ancho;
public:
	Casa() {
		x = 90;
		y = 45;
		alto = 4;
		ancho = 9;
	}
	~Casa() {}

	void borrar() {
		Console::SetCursorPosition(x, y);		cout << "         ";
		Console::SetCursorPosition(x, y + 1);	cout << "         ";
		Console::SetCursorPosition(x, y + 2);	cout << "         ";
		Console::SetCursorPosition(x, y + 3);	cout << "         ";
	}

	void dibujar() {
		Console::ForegroundColor = ConsoleColor::Red;
		Console::SetCursorPosition(x, y);		cout << R"(   __I_  )";
		Console::SetCursorPosition(x, y + 1);	cout << R"( /\-_--\ )";
		Console::SetCursorPosition(x, y + 2);	cout << R"(/  \_-__\)";
		Console::SetCursorPosition(x, y + 3);	cout << R"(|[]| [] |)";
		Console::ForegroundColor = ConsoleColor::White;
	}

	Rectangle getRectangle() {
		return Rectangle(x, y, ancho, alto);
	}
};
