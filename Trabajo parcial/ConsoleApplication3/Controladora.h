
#ifndef __CONTROLADORA__
#define __CONTROLADORA__
#include "Ecenario.h"
#include "CJugador.h"
#include "CEnemigo.h"
#include "CNivel.h"
#include "ListaEnlazadaSimple.h"
#include "ListaEnlazadaCircularDoble.h"

class Controladora
{

private:

	//Listas a usar

	ListaDobEnlazadaCircular<CNivel> *ColeccionNiveles;

	//OBJETOS

	CJugador* objJugador;
	CEnemigo * objEnemigo;

	//Auxilkiares
	CNivel * auxNiv;

	//CFuego* objFuego;
	//CEnemigoFuego* objEnemigoFuego;


public:
	Controladora()
	{
		
		this->objJugador = new CJugador();
		
		this->ColeccionNiveles = new ListaDobEnlazadaCircular<CNivel>();

		//LLENAMOS LA "LISTA DOBLE ENLAZADA" DE NIVELES

		for (int i = 1; i <= 4; i++) {

			CNivel * niv = new CNivel(i);

			ColeccionNiveles->AgregarElementoFinal(niv);

		}

		auxNiv = ColeccionNiveles->ObtenerElemento(0);

		//this->objFuego = new CFuego();
		//this->objEnemigoFuego = new CEnemigoFuego();

	}
	~Controladora() {}



	void GanaJuego() {

		if (auxNiv->LLegoAlameta(objJugador) == 1) { 
			auxNiv = ColeccionNiveles->ObtSigElement(auxNiv->GetNivel());
			auxNiv->ActualizaPosJugador(objJugador);
		}
			
	}
	

	void PierdeJuego() {

		if (objJugador->GetVidas() == 0) { 
			auxNiv = ColeccionNiveles->ObtIniElement();
			objJugador->PierdeJuego();
		}
	}

	int Vidas()
	{
		 return objJugador->GetVidas();
	}


	void DibujarMapa(Graphics^ g, Bitmap^ bmpBloque, Bitmap^ bmpEspinas, Bitmap^ bmpFondo)
	{
		auxNiv->DibujaNivel(g , bmpBloque, bmpEspinas ,bmpFondo);
	}
	void DibujaEnemigos(Graphics^ g, Bitmap^ Enemigo, Bitmap^ bala) {

		auxNiv->DibujaEnemigosDeNivel(g, Enemigo, bala);

	}
	void DibujaCompuerta(Graphics^ g, Bitmap^ c) {

		auxNiv->DibujaCompuerta(g,c);
	}


	void ColisionEnemigoJugador() {

		auxNiv->ColisionEnemigoBala(objJugador);

	}
	void DireccionJugador(Direcciones direccion)
	{
		objJugador->cambiarDireccion(direccion);
	}
	
	void DibujarJugador(Graphics^ g, Bitmap^ jugador)
	{
		
		objJugador->Mover(g, jugador,auxNiv->MatMapa());
	}

	void PosInicial() {

		auxNiv->ActualizaPosJugador(objJugador);
	}
	int get_nivel() {
		return auxNiv->GetNivel();
	}

	/*void InteraccionJyEsc() {


		int x, y = 0;

		for (int i = 0; i < FILAS; i++)
		{
			x = 0;

			for (int j = 0; j < COLUMNAS; j++)
			{
				Rectangle bloque(x, y, 30, 30);

				if ((auxNiv->MatMapa())[i][j] == 1)
				{

					if ((objJugador->GetRecJugadorCDI()).IntersectsWith(bloque)) { objJugador->SetDx(0); }
					if ((objJugador->GetRecJugadorCAA()).IntersectsWith(bloque)) { objJugador->SetDy(0); }
					//if ((objJugador->GetRectaguloLateralIzquierdo()).IntersectsWith(bloque)) { objJugador->SetIzq(0); }

					//if ((objJugador->GetJugador()).IntersectsWith(bloque)) { objJugador->SetDer(0); }

				}

				x += 30;
			}
			y += 30;
		}
		

		

	}
	*/
	
};

#endif // !__CONTROLADORA_