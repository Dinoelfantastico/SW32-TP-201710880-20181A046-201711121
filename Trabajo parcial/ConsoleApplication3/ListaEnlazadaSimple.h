#pragma once
#include <functional>

using namespace std;

typedef unsigned int uint;

//Se utiliza template para cualquier tipo de dato

template <typename T >
//Clase ListaEnlazadaSimple
class ListaEnlazadaSimple {

	struct nodo {

		T * elem;
		nodo * sig;

		nodo(T *elem = nullptr, nodo* sig = nullptr):elem(elem),sig(sig){}
	};

private :

	uint tam;//tam(número de elementos en la lista
	nodo * ini;
	typename function<int(T, T)>Comparar;
	
public:

	//Constructor
	ListaEnlazadaSimple() : ini(nullptr), tam(0) {}
	//Destructor
	~ListaEnlazadaSimple(){

		while (ini != nullptr) {

			nodo * aux;
			aux = ini;
			ini = ini->sig;
			delete aux;

		}
	
	}

	//Verifica si la lista esta vacia
	bool EsVacia() {

		return (ini == nullptr);
	}

	//Retorna el tamanño de la lista
	int tamaño() {

		return tam;
	}

	//Obtiene un elemento de la lista en una posicion
	T * ObtenerElemento(int pos) {

		nodo * aux = ini;
		for (int i = 0; i < pos; i++) {

			aux = aux->sig;
		}

		return aux->elem;
		
	}

	//Agrega un elemento en el inicio de la lista
	void AgregarElementoIni(T *elem) {

		ini = new nodo(elem, ini);
		tam++;
		
	}
	//Agregar un elemento en posicion en la lista
	void AgregarElementoPos(T *elem, int pos) {

		if (pos == 0) AgregarElementoIni(elem);
		if (pos > 0 && pos <= tam) {

			nodo * aux = ini;

			for (int i = 1; i < pos; i++) {

				aux = aux->sig;

			}

			aux->sig = new nodo(elem,aux->sig);

			tam++;

		}

		

	}

	//Agrega un elemento en el final de la lista
	void AgregarElementoFinal(T * elem) {

		AgregarElementoPos(elem, tam);
	}

	//Elimina un elemento de la lista en posicion
	void EliminarElemento(int pos) {

		nodo * aux = ini;
		for (int i = 1; i < pos; i++) {

			aux = aux->sig;
		}
		nodo * aux2 = aux->sig;
		
		aux->sig = (aux->sig)->sig;

		delete aux2;
	}
};