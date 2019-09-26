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
	Stack() : _top(nullptr), len(0) {}
	//Destructor
	~Stack() {
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

	//Inserta un elemento en la cima de la pila
	void push(T elem) {
		_top = new Node(elem, _top);
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
};


