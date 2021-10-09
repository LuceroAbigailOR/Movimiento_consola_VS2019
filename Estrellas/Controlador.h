#pragma once
#include "Monigote.h"
#include "Estrellas.h"
#include <vector>

class Controlador
{
private:
	Monigote* m;
	vector<Estrella*> arrestrellas;
	int cont;

public:
	Controlador() {
		m = new Monigote();
		cont = 0;
	}

	~Controlador() {
		delete m;
		for(int i=0;i<arrestrellas.size();i++) delete[] arrestrellas[i];
	}

	void addEstrella() {
		Estrella* _ra = new Estrella();
		arrestrellas.push_back(_ra);
	}

	void crearEstrellas() {
		for (int i = 0; i < 3;i++) {
			addEstrella();
		}
	}

	void borrarTodo() {
		Console::SetCursorPosition(1, 1); cout << "                       ";//borrar el contador de estrellas
		m->Borrar();

		for (unsigned int i = 0; i < arrestrellas.size(); i++) {
			arrestrellas[i]->Borrar();
		}
	}

	void moverTodo() { //Movimiento Automatico
		for (unsigned int i = 0; i < arrestrellas.size(); i++) {
			arrestrellas[i]->Mover();
		}
	}

	Monigote* getMonigote() {
		return m;
	}
	void dibujarTodo() {
		Console::SetCursorPosition(1, 1); cout << "Estrellas capturadas: " << cont;

		m->Imprimir();
		for (unsigned int i = 0; i < arrestrellas.size(); i++) {
			arrestrellas[i]->Imprimir();
		}
	}

	void final_consola() {
		for (unsigned int i = 0; i < arrestrellas.size(); i++) {
			if ((arrestrellas[i]->gety() + arrestrellas[i]->getalto() + arrestrellas[i]->getdy()) > 45) {
				arrestrellas[i]->Borrar();
				arrestrellas.erase(arrestrellas.begin()+i);
			}
		}
	}

	void colision() {
		for (int i = 0; i < arrestrellas.size(); i++) {
			if (m->getRectangle().IntersectsWith(arrestrellas[i]->getRectangle())) {
				arrestrellas[i]->Borrar();
				arrestrellas.erase(arrestrellas.begin()+i);
				cont++;
			}
		}
	}

	int getCont() { return cont; }
	void setCont(int v) { cont = v; }
};
