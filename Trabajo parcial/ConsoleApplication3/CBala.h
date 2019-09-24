#pragma once

using namespace System::Drawing;

class CBala {

private:

	int x;
	int y;
	int des;
	int alto;
	int ancho;

public:

	CBala(int px , int py){

		x = px; y = py ; des = 21; alto = 50;
		ancho = 50;
	}
	~CBala(){}

	int Getx() { return x; }
	int Gety() { return y; }

	void DibujaBala(Graphics ^ g , Bitmap^ bala) {

		g->DrawImage(bala, x, y, ancho, alto);
	}

	void MovimientoBalaArriba(Graphics ^ g, Bitmap^ bala) {

		if (y > 30)y = y - des; else y = 510;

		DibujaBala( g, bala);
	}
	void MovimientoBalaAbajo(Graphics ^ g, Bitmap^ bala) {

		if (y < 510)y = y + des; else y = 30;
		DibujaBala( g, bala);

	}
	void MovimientoBalaDerecha(Graphics ^ g, Bitmap^ bala) {

		if (x < 800)x = x + des; else x = 30;
		DibujaBala( g, bala);
	}
	void MovimientoBalaIzquierda(Graphics ^ g, Bitmap^ bala) {

		if (x > 30) x = x - des; else x = 810;
		DibujaBala(  g,  bala);
	}


};