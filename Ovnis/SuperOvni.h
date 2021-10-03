#pragma once
#include <iostream>
using namespace std;
using namespace System;

class SuperOvni
{
protected:
	int x, y;
	int dy;
	int alto, ancho;
public:
	SuperOvni() {
		dy = 1;
	}

	~SuperOvni() {}

	void setx(int x) { this->x = x; }
	int getx() { return this->x; }

	void sety(int y) { this->y = y; }
	int gety() { return this->y; }

	void setdy(int dy) { this->dy = dy; }
	int getdy() { return this->dy; }

	void setalto(int alto) { this->alto = alto; }
	int getalto() { return this->alto; }

	void setancho(int ancho) { this->ancho = ancho; }
	int getancho() { return this->ancho; }

	virtual void borrar() {}
	virtual void dibujar() {}

	void mover() {
		//if (y < 1 || y + alto + dy > 50) dy *= -1;      esta funcion no se activa, porque el ovni al llegar al final debe desaparecer
		y += dy; 
	}
};
