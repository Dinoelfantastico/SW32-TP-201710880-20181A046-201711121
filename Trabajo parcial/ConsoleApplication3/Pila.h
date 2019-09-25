#pragma once

template <typename T>

class pila {
	
	struct Nodo {

		T*elemento;
		Nodo*next;

		Nodo(T*elemento,Nodo*next = nullptr): elemento(elemento),next(next){}
	};

	Nodo*_top;
	int len;

public:
	Stack() : _top(nullptr), len(0) {}
	~Stack() {
		while (_top != nullptr) {
			Node* aux = _top;
			_top = _top->next;
			delete aux;
		}
	}

	bool is_empty() {
		return _top == nullptr;
	}
	void push(T elem) {
		_top = new Node(elem, _top);
		++len;
	}
	void pop() {
		if (!is_empty()) {
			Node* aux = _top;
			_top = _top->next;
			delete aux;
			--len;
		}
	}

	T top() {
		if (!is_empty()) {
			return _top->elem;
		}
		return 0;
	}
};


