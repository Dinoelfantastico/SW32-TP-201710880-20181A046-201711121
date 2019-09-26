#pragma once

//Implementados este espacio de nombre porque trabajaremos con imagenes (Bitmap)
using namespace System::Drawing;
//Clase Bala
class CBala {

//variables privados
private:

	int x, y , des ,alto , ancho;

public:

	//Contructor le ponemos 2 parámetros los cuales servira para inicializar 
	//Sus coordenadas x e y, tambien inicializamos des , alto y ancho
	CBala(int px , int py){

		x = px, y = py  , des = 21 , alto = 50, ancho = 50;
	}

	//No vamos a destruir nada porque clase bala es estatico, no es dinámico
	~CBala(){}

	//Metdos de la clase bala tipos enteros
	int Getx() { return x; }
	int Gety() { return y; }

	//Dibujando a la bala
	//Graphics sirve para dibujar la bala , para que lo hago visible en la pantalla
    void DibujaBala(Graphics ^ g , Bitmap^ bala) {

		g->DrawImage(bala, x, y, ancho, alto);
	}

	//Movimiento de la bala hacia arriba
	void MovimientoBalaArriba(Graphics ^ g, Bitmap^ bala) {

		if (y > 30)y = y - des; else y = 510;

		DibujaBala( g, bala);
	}
	//Movimiento de la bala hacia abajo
	void MovimientoBalaAbajo(Graphics ^ g, Bitmap^ bala) {

		if (y < 510)y = y + des; else y = 30;
		DibujaBala( g, bala);

	}

    //Movimiento de bala a la derecha
	void MovimientoBalaDerecha(Graphics ^ g, Bitmap^ bala) {

		if (x < 800)x = x + des; else x = 30;
		DibujaBala( g, bala);
	}

	//Movimiento de la bala a la izquierda
	void MovimientoBalaIzquierda(Graphics ^ g, Bitmap^ bala) {
		if (x > 30) x = x - des; else x = 810;
		DibujaBala(  g,  bala);
	}
};