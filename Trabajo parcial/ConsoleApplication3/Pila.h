#pragma once

//Sirve para utilizar cualquier tipo de elemento
template <typename T>
//Clase pila
class pila {
	
	struct Nodo {

		T*elemento;
		Nodo*next;

		Nodo(T*elemento,Nodo*next = nullptr): elemento(elemento),next(next){}
	};

	Nodo*_top;
	int len;

public:
	//Constructor
	pila() : _top(nullptr), len(0) {}
	//Destructor
	~pila() {
		while (_top != nullptr) {
			Node* aux = _top;
			_top = _top->next;
			delete aux;
		}
	}

	//Sirve para verificar si pila esta vacia
	bool is_empty() {
		return _top == nullptr;
	}

	int tamanio() {
		return len;
	}

	//Inserta un elemento en la cima de la pila
	void push(T*elem) {

		_top = new Nodo(elem, _top);
		++len;
	}

	//Recupera y elimina el último elemento en la cima de la pila
	void pop() {
		if (!is_empty()) {
			Node* aux = _top;
			_top = _top->next;
			delete aux;
			--len;
		}
	}

	//Hace referencia a la cima de la pila
	T*top() {
		if (!is_empty()) {
			return _top->elem;
		}
		return 0;
	}

	T * ObtenerElemento(int pos) {

		Nodo * aux = _top;
		for (int i = 0; i < pos; i++) {

			aux = aux->next;
		}

		return aux->elemento;

	}

};


