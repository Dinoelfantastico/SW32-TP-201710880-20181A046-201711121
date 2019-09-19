#pragma once

#include "CBala.h"

using namespace System::Drawing;

class CEnemigo {

private:

	CBala * BalaCanon;
	int x;
	int y;

	int ancho;
	int largo;
	int fila, columna;

	//1(arriba) , 2(abajo) , 3(izquierda) , 4(derecha)
	int dirDisparo;

public:

	CEnemigo(int px , int py ,int anc,int alt, int dirDisp){
	
		x = px;
		y = py;
		fila = columna = 0;
		ancho = anc ;
		largo = alt;
		dirDisparo = dirDisp;
		BalaCanon = new CBala(x,y);

	}
	~CEnemigo(){}

	int Getx() { return x; }
	int Gety() { return y; }

	void DibujaEnemigo(Graphics^ g, Bitmap^ enemigo) {
		largo = enemigo->Height/1;
		ancho = enemigo->Width / 6;
		Rectangle molde = Rectangle(columna * ancho, fila * largo, ancho, largo);
		g->DrawImage(enemigo, x, y,molde,GraphicsUnit::Pixel);
		columna++;
		if (columna == 6) {
			columna = 0;
		}

	}
	void EnemigoDispara(Graphics^ g, Bitmap^ bala) {

		if (dirDisparo == 1) BalaCanon->MovimientoBalaArriba(g, bala);
		if (dirDisparo == 2) BalaCanon->MovimientoBalaAbajo(g, bala);
		if (dirDisparo == 3) BalaCanon->MovimientoBalaIzquierda(g, bala);
		if (dirDisparo == 4) BalaCanon->MovimientoBalaDerecha(g, bala);

	}

	Rectangle GetRectangleBala() {

		return Rectangle(BalaCanon->Getx(), BalaCanon->Gety(),50,50);
	}
	

};