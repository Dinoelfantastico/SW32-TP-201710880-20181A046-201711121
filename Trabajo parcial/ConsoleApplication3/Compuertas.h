#pragma once

using namespace System::Drawing;

class CCompuerta {

private:
	int x;
	int y;

	int ancho;
	int alto;

public:

	CCompuerta(int px, int py) {

		x = px;
		y = py;
		ancho = 90;
		alto = 90;
	}
	~CCompuerta() {}

	void DibujaCompuerta(Graphics^ g, Bitmap^ Compuerta) {
		g->DrawImage(Compuerta, x, y, ancho, alto);

	}

	Rectangle GetCompuerta() {
		return Rectangle(x, y, ancho, alto);
	}


};