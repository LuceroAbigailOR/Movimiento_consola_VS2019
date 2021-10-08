#pragma once
#include "Pacman.h"
#include "MegaFantasma.h"
#include "Fantasma.h"
#include "PacDot.h"
#include "Bonus.h"
#include <vector>

class Controlador
{
private:
	Pacman* p; MegaFantasma* m;
	vector<Fantasma*> arrFantasmas;
	vector<PacDot*> arrPacDots;
	vector<Bonus*> arrBonus;
	bool ganaste, perdiste;
	bool paused;
	time_t cronometro;

public:
	Controlador() {
		p = new Pacman(); m = new MegaFantasma();
		ganaste = false; perdiste = false;
		paused = false;
		insertar();
	}

	~Controlador() {}

	void addFantasma() {
		Fantasma* _f = new Fantasma();
		arrFantasmas.push_back(_f);
	}

	void addPacDot() {
		PacDot* _p = new PacDot();
		arrPacDots.push_back(_p);
	}

	void addBonus() {
		Bonus* _b = new Bonus();
		arrBonus.push_back(_b);
	}

	void insertar() {
		for (int i = 0; i < 4; i++) {
			addFantasma();
		}
		for (int i = 0; i < 100; i++) {
			addPacDot();
		}
		for (int i = 0; i < 10; i++) {
			addBonus();
		}
	}

	void borrarTodo() {
		p->borrar();
		m->borrar();
		for (unsigned int i = 0; i < arrPacDots.size(); i++) {
			arrPacDots[i]->borrar();
		}
		for (unsigned int i = 0; i < arrBonus.size(); i++) {
			arrBonus[i]->borrar();
		}
		for (unsigned int i = 0; i < arrFantasmas.size(); i++) {
			arrFantasmas[i]->borrar();
		}
	}

	void moverTodo() { //Movimiento Automatico
		if (paused == false) {
			m->mover();
			for (unsigned int i = 0; i < arrFantasmas.size(); i++) {
				arrFantasmas[i]->mover();
			}
			p->setdx(2); p->setdy(2); //pacman tendra una velocidad constante antes de colisionar
			//colision
			colision();
			colisionMegaFantasma();
		}
		else
			colision(); //no se agrega colisionMegaFantasma(); porque el pacman es inmune al MegaFantasma
		pausar_5_segundos();
	}

	Pacman* getPacman() {
		return p;
	}


	void dibujarTodo() {
		p->dibujar();
		m->dibujar();
		for (unsigned int i = 0; i < arrFantasmas.size(); i++) {
			arrFantasmas[i]->dibujar(i+5);
		}
		for (unsigned int i = 0; i < arrPacDots.size(); i++) {
			arrPacDots[i]->dibujar();
		}
		for (unsigned int i = 0; i < arrBonus.size(); i++) {
			arrBonus[i]->dibujar();
		}
	}

	void colision() {
		for (unsigned int i = 0; i < arrFantasmas.size(); i++) {
			if (p->getRectangle().IntersectsWith(arrFantasmas[i]->getRectangle())) {
				p->setvidas(p->getvidas()-1);
				p->sety(1); //hacer que el pacman se posicione en la esquina superior izquierda
				p->setx(1);
			}
		}
		for (unsigned int i = 0; i < arrPacDots.size(); i++) {
			if (p->getRectangle().IntersectsWith(arrPacDots[i]->getRectangle())) {
				arrPacDots[i]->borrar();
				arrPacDots.erase(arrPacDots.begin() + i);
			}
		}
		for (unsigned int i = 0; i < arrBonus.size(); i++) {
			if (p->getRectangle().IntersectsWith(arrBonus[i]->getRectangle())) {
				paused = true;
				cronometro = time(0);
				p->aumentarVelocidad();
				arrBonus[i]->borrar();
				arrBonus.erase(arrBonus.begin() + i);
				arrFantasmas.erase(arrFantasmas.begin() + (rand() % arrFantasmas.size()));
			}
		}
	}

	void colisionMegaFantasma() {
		if (p->getRectangle().IntersectsWith(m->getRectangle())) {
			p->setvidas(p->getvidas() - 2);
			addFantasma();
			p->sety(1); //hacer que el pacman se posicione en la esquina superior izquierda
			p->setx(1);
		}
	}

	void pausar_5_segundos() {
		if (paused == true) {
			if (difftime(time(0), cronometro) > 5) paused = false;
		}
	}

	bool ganaste_juego() {
		if (arrPacDots.size()==0) ganaste = true;
		else
			ganaste = false;
		return ganaste;
	}

	bool perdiste_juego() {
		if (p->getvidas() < 0) perdiste = true;
		else
			perdiste = false;
		return perdiste;
	}

	int numPacDots() {
		return arrPacDots.size();
	}
};
