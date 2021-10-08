#pragma once
#include <iostream>

using namespace std;
using namespace System;
using namespace System::Drawing;

class SuperClase {
protected:
	int x, y, alto, ancho, dx,dy;

public:
	SuperClase() {
		dx = 1;
		dy = 1;
	}
	~SuperClase() {}

	virtual void borrar() {}
	virtual void dibujar() {}
	virtual void mover() {}
};
