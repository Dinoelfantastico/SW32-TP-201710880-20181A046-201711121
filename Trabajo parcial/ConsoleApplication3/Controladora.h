#
#include "Ecenario.h"
#include "CJugador.h"
#include "CEnemigo.h"
#include "ArregloKi.h"
#include "CNivel.h"
#include "ListaEnlazadaSimple.h"
#include "ListaEnlazadaCircularDoble.h"
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
#include <stdlib.h>

using namespace std;
class Controladora
{

private:

	//Listas a usar

	ListaDobEnlazadaCircular<CNivel> *ColeccionNiveles;
	ListaEnlazadaSimple<CEnemigo> *ColeccionEnemigos;
	//OBJETOS
	CBala *objbala;
	CJugador* objJugador;
	CEnemigo * objEnemigo;
	ArregloKi * ki;
	//Auxilkiares
	CNivel * auxNiv;

	//CFuego* objFuego;
	//CEnemigoFuego* objEnemigoFuego;
	

public:
	Controladora()
	{

		this->objJugador = new CJugador();
		this->ki = new ArregloKi();
		this->ColeccionNiveles = new ListaDobEnlazadaCircular<CNivel>();
		this->ColeccionEnemigos = new ListaEnlazadaSimple<CEnemigo>();
		//LLENAMOS LA "LISTA DOBLE ENLAZADA" DE NIVELES

		for (int i = 1; i <= 4; i++) {

			CNivel * niv = new CNivel(i, objJugador);

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
		auxNiv->DibujaNivel(g, bmpBloque, bmpEspinas, bmpFondo);
	}
	void DibujaEnemigos(Graphics^ g, Bitmap^ Enemigo1, Bitmap^ Enemigo2, Bitmap^ Enemigo3, Bitmap^ Enemigo4, Bitmap^ bala) {
		for (int i = 0; i < 3; i++)
		{
			
			auxNiv->DibujaEnemigosDeNivel(g, Enemigo1, Enemigo2, Enemigo3, Enemigo4, bala, i+1, i); 
			
			
		
		}
	}
	void guardarpartida() {
		ofstream archivo;
		archivo.open("datosdepartida.txt", ios::out); //ABRIR ARCHIVO
		if (archivo.fail()) {
			exit(1);
		}
		/*JUGADOR*/
		
		archivo << objJugador->GetX() << endl;
		archivo << objJugador->GetY() << endl;
		archivo << objJugador->GetVidas() << endl;
		archivo << (20 - objJugador->get_energiarecolectada()) << endl;
		/*ENEMIGOS*/
	
	
		archivo.close();

	}
	void abrirpartida() {
		string x,y, vida, energia;
		ifstream archivo;
		archivo.open("datosdepartida.txt", ios::in);
		if (archivo.fail()) {
			exit(0);
		}
		while (!archivo.eof()) {//mientras no sea final
			getline(archivo, x);
		}
		archivo.close();
	}
	void DibujarKi(BufferedGraphics ^buffer) {
		auxNiv->DibujaKi(buffer);
	}
	void DibujaCompuerta(Graphics^ g, Bitmap^ c) {

		auxNiv->DibujaCompuerta(g, c);
	}

	void ColisionKiJugador() {
		auxNiv->ColisionKiJugador(objJugador);
	}

	void ColisionEnemigoJugador() {

		auxNiv->ColisionEnemigoBala(objJugador);
	}

	void DibujarJugador(Graphics^ g, Bitmap^ jugador)
	{

		objJugador->Dibujar(g, jugador);
	}
	
	void MoverJugador(Direcciones direccion, Graphics^ g) {
		objJugador->Mover(g, direccion);
	}
	void PosInicial() {

		auxNiv->ActualizaPosJugador(objJugador);
	}
	int get_nivel() {
		return auxNiv->GetNivel();
	}
	int get_energiarecolectada() {
		return objJugador->get_energiarecolectada();
	}
	bool gano() {
		return objJugador->GanoJuego();
	}

	
	 
};

