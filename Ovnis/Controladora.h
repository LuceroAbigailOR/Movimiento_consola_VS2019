#pragma once
#include "RazaGama.h"
#include "RazaBeta.h"
#include "RazaAlfa.h"
#include <vector>

class Controladora
{
private:
	vector<RazaAlfa*> arreglora;
	vector<RazaGama*> arreglorg;
	vector<RazaBeta*> arreglorb;
	int cont1, cont2, contTotal;

public:
	Controladora() {
		cont1 = 0;
		cont2 = 0;
		contTotal = 0;
		//addRazaBeta();
		//addRazaGama();
	}

	void addRazaAlfa() {
		RazaAlfa* _ra = new RazaAlfa();
		arreglora.push_back(_ra);
		cont1++;
		contTotal++;
	}

	void addRazaBeta() {
		RazaBeta* _rb = new RazaBeta();
		arreglorb.push_back(_rb);
		cont2++;
		contTotal++;
	}

	void addRazaGama() {
		RazaGama* _rg = new RazaGama();
		arreglorg.push_back(_rg);
		contTotal++;
	}

	void borrarTodo() {
		for (unsigned int i = 0; i < arreglora.size(); i++) {
			arreglora[i]->borrar();
		}
		for (unsigned int i = 0; i < arreglorb.size(); i++) {
			arreglorb[i]->borrar();
		}
		for (unsigned int i = 0; i < arreglorg.size(); i++) {
			arreglorg[i]->borrar();
		}
	}

	void moverTodo() { //Movimiento Automatico
		for (unsigned int i = 0; i < arreglora.size(); i++) {
			arreglora[i]->mover();
		}
		for (unsigned int i = 0; i < arreglorb.size(); i++) {
			arreglorb[i]->mover();
		}
		for (unsigned int i = 0; i < arreglorg.size(); i++) {
			arreglorg[i]->mover();
		}
	}

	void dibujarTodo() {
		Console::ForegroundColor = ConsoleColor::White;

		for (unsigned int i = 0; i < arreglora.size(); i++) {
			arreglora[i]->dibujar();
		}
		for (unsigned int i = 0; i < arreglorb.size(); i++) {
			arreglorb[i]->dibujar();
		}
		for (unsigned int i = 0; i < arreglorg.size(); i++) {
			arreglorg[i]->dibujar();
		}
	}

	void final_consola() {
		for (unsigned int i = 0; i < arreglora.size(); i++) {
			if ((arreglora[i]->gety() + arreglora[i]->getalto() + arreglora[i]->getdy()) > 50) {
				arreglora[i]->borrar();
				arreglora.erase(arreglora.begin());
				contTotal--;
			}
		}

		for (unsigned int i = 0; i < arreglorb.size(); i++) {
			if ((arreglorb[i]->gety() + arreglorb[i]->getalto() + arreglorb[i]->getdy()) >50) {
				arreglorb[i]->borrar();
				arreglorb.erase(arreglorb.begin());
				contTotal--;
			}
		}

		for (unsigned int i = 0; i < arreglorg.size(); i++) {
			if ((arreglorg[i]->gety() + arreglorg[i]->getalto() + arreglorg[i]->getdy()) >50) {
				arreglorg[i]->borrar();
				arreglorg.erase(arreglorg.begin());
				contTotal--;
			}
		}
	}

	int getCont1() { return cont1; }
	void setCont1(int v) { cont1 = v; }

	int getCont2() { return cont2; }
	void setCont2(int v) { cont2 = v; }

	int getContTotal() { return contTotal; }
	void setContTotal(int v) { contTotal = v; }
};
