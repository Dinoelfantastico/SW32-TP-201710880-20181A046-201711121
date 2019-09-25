#pragma once
#include <functional>

using namespace std;

typedef unsigned int uint;
template <typename T >

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

	ListaEnlazadaSimple() : ini(nullptr), tam(0) {}
	~ListaEnlazadaSimple(){

		while (ini != nullptr) {

			nodo * aux;
			aux = ini;
			ini = ini->sig;
			delete aux;

		}
	
	}


	bool EsVacia() {

		return (ini == nullptr);
	}

	int tamaño() {

		return tam;
	}

	T * ObtenerElemento(int pos) {

		nodo * aux = ini;
		for (int i = 0; i < pos; i++) {

			aux = aux->sig;
		}

		return aux->elem;
		
	}

	void AgregarElementoIni(T *elem) {

		ini = new nodo(elem, ini);
		tam++;
		
	}
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
	void AgregarElementoFinal(T * elem) {

		AgregarElementoPos(elem, tam);
	}

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