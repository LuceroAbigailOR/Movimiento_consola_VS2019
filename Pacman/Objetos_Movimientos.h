#pragma once
#include <iostream>

using namespace std;
using namespace System;
using namespace System::Drawing;

class Objetos_Movimiento {
protected:
	int x, y, alto, ancho, dx, dy;

public:
	Objetos_Movimiento() {}
	~Objetos_Movimiento() {}

	virtual void borrar() {}
	virtual void dibujar() {}
	virtual void mover() {}
};
