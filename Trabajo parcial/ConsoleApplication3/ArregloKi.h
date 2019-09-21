#pragma once
#include "Ki.h"

class ArregloKi {
private:
	int p;
	Ki **arreglo_ki;

public:
	ArregloKi() {
		p = 0;

		arreglo_ki = new Ki*[p];
	};
	~ArregloKi() {};
	void agregar(int posx, int posy);
	void eliminar(int i);
	void dibujar(BufferedGraphics ^ buffer);
	int get_x(int i) {
		return arreglo_ki[i]->get_x();
	}
	int get_y(int i) {
		return arreglo_ki[i]->get_y();
	}
	int get_lenght() {
		return p;
	}
	int get_ancho(int i) {
		return arreglo_ki[i]->get_ancho();
	}
	int get_alto(int i) {
		return arreglo_ki[i]->get_alto();
	}
	Ki * get_ep(int i) {
		return arreglo_ki[i];
	}
};

void ArregloKi::agregar(int posx, int posy) {
	Ki **temp = new Ki*[p + 1];
	for (int i = 0; i < p; i++) {
		temp[i] = arreglo_ki[i];
	}
	temp[p] = new Ki(posx, posy);
	p++;

	if (arreglo_ki != nullptr) {
		delete arreglo_ki;
	}
	arreglo_ki = temp;
}
void ArregloKi::dibujar(BufferedGraphics ^ buffer) {
	for (int i = 0; i < p; i++) {
		arreglo_ki[i]->Dibujar(buffer);
	}
}

void ArregloKi::eliminar(int posicion) {
	delete arreglo_ki[posicion];
	for (int i = posicion; i< p; i++) {
		arreglo_ki[i] = arreglo_ki[i + 1];
	}
	p--;
}

