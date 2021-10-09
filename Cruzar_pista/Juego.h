#pragma once
#include "Persona.h"
#include "Bus.h"
#include "Carro.h"
#include "Bicicleta.h"
#include <vector>

class Juego
{
private:
	Persona* p;
	vector<Bus*> arrbuses;
	vector<Carro*> arrcarros;
	vector<Bicicleta*> arrbicicletas;
	bool bandera, ganaste;

public:
	Juego() {
		p = new Persona();
		bandera = false;
		ganaste = false;
	}

	~Juego() {
		delete p;
		for(int i=0;i<arrbuses.size();i++)delete[] arrbuses[i];
		for(int i=0;i<arrcarros.size();i++)delete[] arrcarros[i];
		for(int i=0;i<arrbicicletas.size();i++)delete[] arrbicicletas[i];
	}

	void addBus() {
		Bus* _t = new Bus();
		arrbuses.push_back(_t);
	}

	void addCarro() {
		Carro* _t = new Carro();
		arrcarros.push_back(_t);
	}

	void addBicicleta() {
		Bicicleta* _t = new Bicicleta();
		arrbicicletas.push_back(_t);
	}

	void borrarTodo() {
		p->Borrar();

		for (unsigned int i = 0; i < arrbuses.size(); i++) {
			arrbuses[i]->borrar();
		}
		for (unsigned int i = 0; i < arrcarros.size(); i++) {
			arrcarros[i]->borrar();
		}
		for (unsigned int i = 0; i < arrbicicletas.size(); i++) {
			arrbicicletas[i]->borrar();
		}
	}

	void moverTodo() { //Movimiento Automatico
		for (unsigned int i = 0; i < arrbuses.size(); i++) {
			arrbuses[i]->mover();
		}
		for (unsigned int i = 0; i < arrcarros.size(); i++) {
			arrcarros[i]->mover();
		}
		for (unsigned int i = 0; i < arrbicicletas.size(); i++) {
			arrbicicletas[i]->mover();
		}
	}

	Persona* getPersona() {
		return p;
	}

	void dibujarTodo() {
		p->Dibujar();
		for (unsigned int i = 0; i < arrbuses.size(); i++) {
			arrbuses[i]->dibujar();
		}
		for (unsigned int i = 0; i < arrcarros.size(); i++) {
			arrcarros[i]->dibujar();
		}
		for (unsigned int i = 0; i < arrbicicletas.size(); i++) {
			arrbicicletas[i]->dibujar();
		}
	}

	void final_consola() {
		for (unsigned int i = 0; i < arrbuses.size(); i++) {
			if ((arrbuses[i]->getx()) < 5) {
				arrbuses[i]->borrar();
				arrbuses[i]->setx(78);
			}
		}

		for (unsigned int i = 0; i < arrcarros.size(); i++) {
			if ((arrcarros[i]->getx() + arrcarros[i]->getancho() + arrcarros[i]->getdx()) > 100) {
				arrcarros[i]->borrar();
				arrcarros[i]->setx(1);
			}
		}
	}

	void colision() {
		for (int i = 0; i < arrbuses.size(); i++) {
			if (p->getRectangle().IntersectsWith(arrbuses[i]->getRectangle())) {
				bandera = true;
			}
		}

		for (int i = 0; i < arrcarros.size(); i++) {
			if (p->getRectangle().IntersectsWith(arrcarros[i]->getRectangle())) {
				bandera = true;
			}
		}

		for (int i = 0; i < arrbicicletas.size(); i++) {
			if (p->getRectangle().IntersectsWith(arrbicicletas[i]->getRectangle())) {
				arrbicicletas[i]->cambiar_direccion();
			}
		}
	}

	bool ganaste_juego() {
		if (p->gety() == 3) ganaste = true;
		else
			ganaste = false;
		return ganaste;
	}

	bool fin_del_juego() { return bandera; }
};
