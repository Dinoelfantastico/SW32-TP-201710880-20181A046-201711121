#pragma once
#include "ListaEnlazadaSimple.h"

//Sirve para utilizar cualquier tipo de dato
template <typename T >

//Clase ListaDoblementeCircular
class ListaDobEnlazadaCircular {

	struct nodo {

		T * elem;
		nodo * sig;
		nodo * ant;

		nodo(T * elem = nullptr, nodo* sig = nullptr , nodo * ant = nullptr) :elem(elem), sig(sig) , ant(ant){}
	};
private:

	nodo * ini;
	int tam;


public:

	//Constructor
	ListaDobEnlazadaCircular():tam(0),ini(nullptr){}
	//Destructor
	~ListaDobEnlazadaCircular(){

		while (ini != nullptr) {

			nodo *aux = ini;
			ini = ini->sig ;
			delete aux;

		}
	
	}

	//Verifica si la lista esta vacia
	bool EsVacia() {

		return(tam == 0 );
	}
	int tamaño() {

		return tam;
	}

	//Obtiene un elemento de la lista en posicion
	T * ObtenerElemento(int pos) {

		nodo * aux = ini;
		for (int i = 0; i < pos; i++) {

			aux = aux->sig;

		}
		return aux->elem;
	}

	T * ObtenerElementoIni() {

	}

	//Obtiene un nodo de la lista en posicion
	nodo * obtenerNodo(int pos) 
	{
		nodo * aux = ini;
		for (int i = 0; i < pos; i++) {

			aux = aux->sig;

		}
		return aux;

	}
	//Agregar un elemento en el inicio de la lista
	void AgregarElementoIni(T *elem ) {

		nodo*aux2 = ini;

		ini = new nodo(); 

		nodo * aux = ini; tam++;
		for (int i = 1; i < tam; i++) {

			aux = aux->sig;
		}
		
		ini->elem = elem;
		ini->ant = aux;
		ini->sig = aux2;


	}

	//Agrega un elemento en posicion  de la lista
	void AgregarElementoPos(T *elem, int pos) {

		if (pos == 0) AgregarElementoIni(elem);

		if (pos > 0 && pos <= tam) {

			nodo * aux = ini;
			for (int i = 1; i < pos; i++) {

				aux = aux->sig;

			}

			if(pos < tam)aux->sig = new nodo(elem, aux->sig, aux);
			else aux->sig = new nodo(elem, ini, aux);

			tam++;

		}
	}

	//Agrega un elemento en el final de la lista
	void AgregarElementoFinal(T * elem) {
		AgregarElementoPos(elem, tam);
	}

	T * ObtSigElement(int n) {
		return ((obtenerNodo(n))->elem);
	}

	T * ObtIniElement() {	
		return (ini->elem);
	}

};