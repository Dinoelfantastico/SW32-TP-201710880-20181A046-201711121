#pragma once
#include "ListaEnlazadaSimple.h"
#include "CJugador.h"
#include "Ecenario.h"
#include "CEnemigo.h"
#include "Compuertas.h"
#include <stdlib.h>
#include <time.h>

class CNivel {

private:

	int NumNivel;
	CEcenario * Ecenario;
	CCompuerta * Compuerta;

	ListaEnlazadaSimple<CEnemigo> *ColeccionEnemigos;

public:

	CNivel(int n) { 

		this->ColeccionEnemigos = new ListaEnlazadaSimple<CEnemigo>();
		Ecenario = new CEcenario();

		NumNivel = n;

		if (n == 1) { 
			srand(time(0));
			Ecenario->GeneraMapa1();

			for (int i = 0;i <=3;i++) {
				CEnemigo *enemigo = new CEnemigo(rand()%200, rand() % 400, 60, 60, rand() % 4);
				ColeccionEnemigos->AgregarElementoFinal(enemigo);
			}

			Compuerta = new CCompuerta(780,480);

		
		}
		if (n == 2) {
			
			Ecenario->GeneraMapa2();

			Compuerta = new CCompuerta(780, 480);
			CEnemigo*Enemigo2 = new CEnemigo(600, 30, 90, 60, 4);
			

		}
		if (n == 3) { 
			Ecenario->GeneraMapa3();

			Compuerta = new CCompuerta(780, 480);
			
		}
		if (n == 4) {

			Ecenario->GeneraMapa3();
			
			Compuerta = new CCompuerta(780, 480);
			
		}

	}
	~CNivel() { }

	int GetNivel() { return NumNivel; }
	
	void DibujaNivel(Graphics^ g, Bitmap^ bmpBloque, Bitmap^ bmpEspinas, Bitmap^bmpFondo) {
		Ecenario->Dibujar(g, bmpBloque, bmpEspinas, bmpFondo);
	}

	int ** MatMapa() {

		return (Ecenario->GetMatriz());

	}

	//Dibujar enemigos de determinado nivel

	void DibujaEnemigosDeNivel(Graphics ^ g, Bitmap^ enemigo , Bitmap^ bala) {

		for (int i = 0; i < ColeccionEnemigos->tama�o(); i++)
		{

			(ColeccionEnemigos->ObtenerElemento(i))->DibujaEnemigo(g,enemigo);
			(ColeccionEnemigos->ObtenerElemento(i))->EnemigoDispara(g, bala);

		}

	}

	void DibujaCompuerta(Graphics ^ g, Bitmap^ compuerta) {

		Compuerta->DibujaCompuerta(g,compuerta);
	}

	void ActualizaPosJugador(CJugador * jugador) {

		if (NumNivel == 1) { jugador->SetPosx(120); jugador->SetPosy(510); }
		if (NumNivel == 2) { jugador->SetPosx(60);  jugador->SetPosy(510); }
		if (NumNivel == 3) { jugador->SetPosx(60);  jugador->SetPosy(510); }
		if (NumNivel == 4) { jugador->SetPosx(60);  jugador->SetPosy(510); }
	}

	void ColisionEnemigoBala(CJugador * jugador) {

		for (int i = 0; i < ColeccionEnemigos->tama�o(); i++)
		{

			if ((ColeccionEnemigos->ObtenerElemento(i))->GetRectangleBala().IntersectsWith(jugador->GetJugador())) { 
				ActualizaPosJugador(jugador);
				jugador->PierdeVida();
			}

		}
	}

	bool LLegoAlameta(CJugador * jugador) {return (Compuerta->GetCompuerta().IntersectsWith(jugador->GetJugador()));
	}
};