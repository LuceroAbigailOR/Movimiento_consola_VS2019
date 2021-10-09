#pragma once
#include "Casa.h"
#include "Vacuna.h"
#include "Virus.h"
#include "Monigote.h"
#include <vector>

class Controlador
{
private:
	Monigote* m; Casa* c;
	vector<Vacuna*> arrVacunas;
	vector<Virus*> arrVirus;
	bool ganaste, perdiste;
	int N, cantPasos, contMov;

public:
	Controlador() { 
		m = new Monigote();
		c = new Casa();
		ganaste = false; perdiste = false;
		N = rand() % 7 + 3; //cantidad de virus
		cantPasos = 0; contMov = 0;
		insertar();
	}

	~Controlador() {
		delete m,c;
		for (int i = 0; i < arrVirus.size(); i++) delete[] arrVirus[i];
		for (int i = 0; i < arrVacunas.size(); i++) delete[] arrVacunas[i];
	}

	void addVirus() {
		Virus* _v = new Virus();
		arrVirus.push_back(_v);
	}

	void addVacuna() {
		Vacuna* _v = new Vacuna();
		arrVacunas.push_back(_v);
	}

	void insertar() {
		for (int i = 0; i < N;i++) {
			addVirus();
		}
		for (int i = 0; i < 5; i++) {
			addVacuna();
		}
	}

	void borrarTodo() {
		m->borrar();
		c->borrar();
		for (unsigned int i = 0; i < arrVacunas.size(); i++) {
			arrVacunas[i]->borrar();
		}
		for (unsigned int i = 0; i < arrVirus.size(); i++) {
			arrVirus[i]->borrar();
		}
	}

	void moverTodo() { //Movimiento Automatico
		for (unsigned int i = 0; i < arrVirus.size(); i++) {
			arrVirus[i]->mover();
		}
		for (unsigned int i = 0; i < arrVacunas.size(); i++) {
			arrVacunas[i]->mover(i);
		}
		if (contMov == 0) {
			colisionVirus();
			colisionVacunas();
		}
		else
			colisionVacunas(); //inmune a los virus
		
	}

	Monigote* getMonigote() {
		cantPasos++;
		if (contMov > 0) contMov--;
		return m;
	}

	int cant_Pasos() {
		return cantPasos;
	}

	void dibujarTodo() {
		m->dibujar();
		c->dibujar();
		for (unsigned int i = 0; i < arrVirus.size(); i++) {
			arrVirus[i]->dibujar();
		}
		for (unsigned int i = 0; i < arrVacunas.size(); i++) {
			arrVacunas[i]->dibujar();
		}
	}

	void colisionVirus() {
		for (int i = 0; i < arrVirus.size(); i++) {
			if (m->getRectangle().IntersectsWith(arrVirus[i]->getRectangle())) {
				m->setvidas(m->getvidas()-1);
				m->setx(1);
				m->sety(1);
			}
		}
	}
	void colisionVacunas(){
		for (int i = 0; i < arrVacunas.size(); i++) {
			if (m->getRectangle().IntersectsWith(arrVacunas[i]->getRectangle())) {
				contMov = 10;
			}
		}
	}

	bool perdiste_juego() {
		if (m->getvidas() <= 0) perdiste = true;
		else
			perdiste = false;
		return perdiste;
	}

	bool ganaste_juego() {
		if (m->getRectangle().IntersectsWith(c->getRectangle())) {
			ganaste = true;
		}
		else
			ganaste = false;
		return ganaste;
	}
};
