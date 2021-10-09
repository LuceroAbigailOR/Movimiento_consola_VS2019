#pragma once
#include "Gato.h"
#include "Raton.h"
#include <vector>

class Controlador
{
private:
	Gato* g;
	vector<Raton*> arrRatones;
	bool ganaste;
	int N, contN, contatrapar;
	time_t tiempo_inicio_app_r; //raton

public:
	Controlador() {
		g = new Gato();
		ganaste = false;
		tiempo_inicio_app_r = time(0);
		contN = 0;
		contatrapar = 0;
		N= rand() % 16 + 7; //valor aleatorio entre 7 y 15
	}

	~Controlador() {
		delete g;
		for (int i = 0; i < arrRatones.size(); i++) delete[] arrRatones[i];
	}

	void addRaton() {
		Raton* _r = new Raton();
		arrRatones.push_back(_r);
	}

	void insertar_ratones_N() {
		if (contN <= N) {
			if (difftime(time(0), tiempo_inicio_app_r) > 2){	
				addRaton();
				contN++;
				tiempo_inicio_app_r = time(0);
			}
		}
	}

	void borrarTodo() {
		g->borrar();
		for (unsigned int i = 0; i < arrRatones.size(); i++) {
			arrRatones[i]->borrar();
		}
	}

	void moverTodo() { //Movimiento Automatico
		for (unsigned int i = 0; i < arrRatones.size(); i++) {
			arrRatones[i]->mover();
		}
	}

	Gato* getGato() {
		return g;
	}

	void dibujarTodo() {
		g->dibujar();
		for (unsigned int i = 0; i < arrRatones.size(); i++) {
			arrRatones[i]->dibujar();
		}
	}

	void colision() {
		for (int i = 0; i < arrRatones.size(); i++) {
			if (g->getRectangle().IntersectsWith(arrRatones[i]->getRectangle())) {
				arrRatones[i]->borrar();
				arrRatones.erase(arrRatones.begin() + i);
				contatrapar++;
			}
		}
	}

	bool ganaste_juego() {
		if (contatrapar == N/2) ganaste = true;
		else
			ganaste = false;
		return ganaste;
	}
};
