#pragma once

using namespace System::Drawing;
using System::Drawing::Graphics;
using System::Drawing::Pens;
using System::Drawing::Brushes;

class Ki {

private:
	int x, y, w, h, indiceX, indiceY;
	int columna, fila;

public:

	Ki(int x, int y) {

		this->x = x;
		this->y = y;
		columna = fila = 0;
		
		indiceX = indiceY = 0;
	}

	~Ki() {}

	void Dibujar(BufferedGraphics^ buffer);
	void set_x_y(int x, int y);
	int get_x() { return x; };
	int get_y() { return y; };
	int get_ancho(){ return w; };
	int get_alto(){ return h; };

};

	void Ki::Dibujar(BufferedGraphics^ buffer) {
		Bitmap ^bmp = gcnew Bitmap(gcnew System::String("Imagenes\\Ki.png"));
		h = bmp->Height / 1;
		w = bmp->Width / 6;
		Rectangle molde = Rectangle(columna*w, fila*h, w, h);
		buffer->Graphics->DrawImage(bmp, x, y,molde, GraphicsUnit::Pixel);
		columna++;
		if (columna == 6) {
			columna = 0;
		}
	}
		void Ki::set_x_y(int x, int y) {

			this->x = x;
			this->y = y;
		}
