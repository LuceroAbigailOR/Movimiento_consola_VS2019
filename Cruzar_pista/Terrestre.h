#pragma once
#include <iostream>

using namespace std;
using namespace System;
using namespace System::Drawing;

class Terrestre {
protected:
	int x, y, alto, ancho, dx;

public:
	Terrestre() {}
	~Terrestre() {}

	virtual void borrar() {}
	virtual void dibujar() {}
	virtual void mover() {}
};
