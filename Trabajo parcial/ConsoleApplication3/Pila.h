#pragma once

template <typename T>
class pila {

	struct  Nodo
	{
		T*elemento;
		Nodo*next;

		Nodo(T*elemento,Nodo*next = nullptr): elemento(elemento),next(next){}
	};

	Nodo*_top;
	int longitud;

public:

	pila() : _top(nullptr),longitud(0){}
	~pila() {
		while (_top != nullptr) {
			Nodo*aux = _top;
			_top = _top->next;
			delete aux;
		}
	}

	bool is_empty() { return longitud == nullptr; }
	

	void push(T*elemento) {
		_top = new Nodo(elemento, _top);
		++logitud;
	}

	void pop() {

		id(!is_empty()) {
			Nodo*aux = _top;
			_top = _top->next;
			delete aux;
			--longitud;
		}
	}

	T top() {
		if (!is_empty()) {
			return _top->elemento;
		}

		return0;
	}

};
