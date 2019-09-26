#pragma once

//Se incluye la clase CBala
#include "CBala.h"

//Se utiliza el espacio de nombre porque utilizaremos imagenes (Bitmap)
using namespace System::Drawing;

class CEnemigo {

private:
	//Creamos un objeto bala
	CBala * ataque;
	//Coordenadas del enemigo x, y ,ancho, largo
	int x ,  y , ancho ,largo , w, h;
	int columna, fila;
	int dirDisparo;

public:

	//Parametros del constructor para indicarle en que posicion debe estar en la pantalla
	CEnemigo(int px , int py ,int anc,int alt, int dirDisp){
	
		x = px;
		y = py;
		ancho = anc ;
		largo = alt;
		columna = fila = 0;
		dirDisparo = dirDisp;

		//Reservamos memoria para el objeto ataque para sus coordenadas x, y
		ataque = new CBala(x,y);

	}
	//Destructor
	~CEnemigo(){}

	//Mestodos
	int Getx() { return x; }
	int Gety() { return y; }

	//Metodo dibujaEnemigo
	void DibujaEnemigo(Graphics^ g, Bitmap^ enemigo) {

		w = enemigo->Width / 6;
		h = enemigo->Height;

		//Este metodo un rectangulo con las coodenadas x, y, ancho del rectangulo y alto del rectangulo
		Rectangle molde = Rectangle(w*columna, h*fila, w, h);
		
		g->DrawImage(enemigo, x, y,molde, GraphicsUnit::Pixel);
		//Columna aumentade 1 en 1
		columna++;
		//Si la columnas es igual 6 regresa a la columna 0 y eso da el efecto del movimiento
		//de frezer en su cola
		if (columna == 6) {
			columna = 0;
		}
	}
	//Metdodo Dispara
	void EnemigoDispara(Graphics^ g, Bitmap^ bala) {

		/*Si la direccion del disparo es 1 entonces mediante el objeto ataque que se creó 
		en la clase se llama al metodo movimiento hacia arriba de la bala , lo  dibuja
		y si mueve hacia arriba*/
		if (dirDisparo == 1) ataque->MovimientoBalaArriba(g, bala);
		if (dirDisparo == 2) ataque->MovimientoBalaAbajo(g, bala);
		if (dirDisparo == 3) ataque->MovimientoBalaIzquierda(g, bala);
		if (dirDisparo == 4) ataque->MovimientoBalaDerecha(g, bala);

	}

	//Metdod GetRectangle
	//Retorna la posicion de la bala , su ancho y su alto
	Rectangle GetRectangleBala() {
		return Rectangle(ataque->Getx(), ataque->Gety(),50,50);
	}

};