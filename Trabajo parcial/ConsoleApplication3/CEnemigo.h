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

	//1(arriba) , 2(abajo) , 3(izquierda) , 4(derecha)
	int dirDisparo;

public:

	CEnemigo(int px , int py ,int anc,int alt, int dirDisp){
	
		x = px;
		y = py;
		ancho = anc ;
		largo = alt;
		dirDisparo = dirDisp;
		BalaCanon = new CBala(x,y);

	}
	~CEnemigo(){}

	int Getx() { return x; }
	int Gety() { return y; }

	void DibujaEnemigo(Graphics^ g, Bitmap^ enemigo) {

		g->DrawImage(enemigo, x, y, ancho, largo);

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