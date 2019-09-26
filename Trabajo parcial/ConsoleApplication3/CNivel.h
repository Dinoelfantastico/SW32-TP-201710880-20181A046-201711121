#pragma once
#include "ListaEnlazadaSimple.h"
#include "Ecenario.h"
#include "CEnemigo.h"
#include "Compuertas.h"
#include "ArregloKi.h"
#include <cstdlib>
#include <ctime>

class CNivel {

private:

	int NumNivel;
	CEcenario * Ecenario;
	CCompuerta * Compuerta;
	ListaEnlazadaSimple<CEnemigo> *ColeccionEnemigos;
	CEnemigo *Enemigo;
	CEnemigo *Enemigo2;
	CEnemigo *Enemigo3;
	ArregloKi *ki;

public:

	CNivel(int n,CJugador *jugador) { 

		this->ColeccionEnemigos = new ListaEnlazadaSimple<CEnemigo>();
		Ecenario = new CEcenario();
		NumNivel = n;

		if (n == 1) { 

			
			Enemigo = new CEnemigo(400, 410, 90, 60, 1,2);
			Enemigo2 = new CEnemigo(600, 30, 90, 60, 2,3);
			Enemigo3 = new CEnemigo(200, 30, 60, 60, 2,4);
			Compuerta = new CCompuerta(830,400);
			generarki();
			ColeccionEnemigos->AgregarElementoFinal(Enemigo);
			ColeccionEnemigos->AgregarElementoFinal(Enemigo2);
			ColeccionEnemigos->AgregarElementoFinal(Enemigo3);
		
		}
		
		if (n == 2) {
		
			generarki();
			Ecenario->GeneraMapa2();
			Enemigo = new CEnemigo(400, 410, 90, 60, 1,2);
			Enemigo2 = new CEnemigo(600, 30, 90, 60, 2,3);
			Enemigo3 = new CEnemigo(200, 30, 60, 60, 2,4);
			Compuerta = new CCompuerta(830, 400);
			ColeccionEnemigos->AgregarElementoFinal(Enemigo);
			ColeccionEnemigos->AgregarElementoFinal(Enemigo2);
			ColeccionEnemigos->AgregarElementoFinal(Enemigo3);
			

		}
		if (n == 3) { 
			generarki();
			Ecenario->GeneraMapa3();
			Enemigo = new CEnemigo(400, 410, 90, 60, 1,2);
			Enemigo2 = new CEnemigo(600, 30, 90, 60, 2,3);
			Enemigo3 = new CEnemigo(200, 30, 60, 60, 2,4);
			Compuerta = new CCompuerta(830, 400);
			ColeccionEnemigos->AgregarElementoFinal(Enemigo);
			ColeccionEnemigos->AgregarElementoFinal(Enemigo2);
			ColeccionEnemigos->AgregarElementoFinal(Enemigo3);
		}
		if (n == 4) { 
			generarki();
			Ecenario->GeneraMapa4();
			
			Compuerta = new CCompuerta(830, 400);
			
		}

	}
	~CNivel() { }


	int GetNivel() { return NumNivel; }
	void generarki() {
		
		ki = new ArregloKi[4 + rand() % 7];
		srand(time(NULL));
		for (int i = 0; i < 5; i++) {

			int a = 10 + rand() % 800;
			int b = 10 + rand() % 400;

			ki->agregar(a, b);
		}
		
		
	}
	void DibujaNivel(Graphics^ g, Bitmap^ bmpBloque, Bitmap^ bmpEspinas, Bitmap^bmpFondo) {
		Ecenario->Dibujar(g, bmpBloque, bmpEspinas, bmpFondo);
	}

	int ** MatMapa() {

		return (Ecenario->GetMatriz());

	}

	//Dibujar enemigos de determinado nivel

	void DibujaEnemigosDeNivel(Graphics ^ g, Bitmap^ enemigo1,Bitmap^ enemigo2, Bitmap^ enemigo3, Bitmap^ enemigo4, Bitmap^ bala,int tipoenemigo,int i) {
		
	
			switch (tipoenemigo) {
			case 1:(ColeccionEnemigos->ObtenerElemento(i))->DibujaEnemigo(g, enemigo1);
				(ColeccionEnemigos->ObtenerElemento(i))->EnemigoDispara(g, bala); break;
			case 2:(ColeccionEnemigos->ObtenerElemento(i))->DibujaEnemigo(g, enemigo2);
				(ColeccionEnemigos->ObtenerElemento(i))->EnemigoDispara(g, bala); break;
			case 3:(ColeccionEnemigos->ObtenerElemento(i))->DibujaEnemigo(g, enemigo3);
				(ColeccionEnemigos->ObtenerElemento(i))->EnemigoDispara(g, bala); break;
			case 4:(ColeccionEnemigos->ObtenerElemento(i))->DibujaEnemigo(g, enemigo4);
				(ColeccionEnemigos->ObtenerElemento(i))->EnemigoDispara(g, bala); break;
			}
		
		

	}
	void DibujaKi(BufferedGraphics ^buffer) {
		ki->dibujar(buffer);
	}

	void DibujaCompuerta(Graphics ^ g, Bitmap^ compuerta) {

		Compuerta->DibujaCompuerta(g,compuerta);
	}

	void ActualizaPosJugador(CJugador * jugador) {

		if (NumNivel == 1) { jugador->SetPosx(120); jugador->SetPosy(430); }
		if(NumNivel == 2){ jugador->SetPosx(60); jugador->SetPosy(430); }
		if (NumNivel == 3) { jugador->SetPosx(60); jugador->SetPosy(430); }
		if (NumNivel == 4) { jugador->SetPosx(60); jugador->SetPosy(430); }
	}

	void ColisionEnemigoBala(CJugador * jugador) {

		for (int i = 0; i < ColeccionEnemigos->tamaño(); i++)
		{

			if ((ColeccionEnemigos->ObtenerElemento(i))->GetRectangleBala().IntersectsWith(jugador->GetJugador())) { 
				ActualizaPosJugador(jugador);
				jugador->PierdeVida();
			}


		}


	}

	void ColisionKiJugador(CJugador * jugador) {
	int x1, y1, a1, l1;
	x1 = jugador->GetX();
	y1 = jugador->GetY();

	int lenght;
	Ki *KI;
	CJugador *GOKU;
	Rectangle kii;
	Rectangle gokuu;

	for (int i = 0; i < ki->get_lenght(); i++) {
		lenght = ki->get_lenght();
		KI = ki->get_ep(i);
		kii = Rectangle(KI->get_x(), KI->get_y(), KI->get_ancho(), KI->get_alto());
		gokuu = Rectangle(x1, y1, 64, 64);

		if (kii.IntersectsWith(gokuu)) {
			ki->eliminar(i);
			jugador->recolecta();
		}

	}
	}

	bool LLegoAlameta(CJugador * jugador) {
		return (Compuerta->GetCompuerta().IntersectsWith(jugador->GetJugador()));	
	}

};