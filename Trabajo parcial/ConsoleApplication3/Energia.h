#pragma once

using namespace System::Drawing;
using System::Drawing::Graphics;
using System::Drawing::Pens;
using System::Drawing::Brushes;

class ki {

private:
	int x, y, w, h;
public:

	ki(int x, int y) {
		this->x = x;
		this->y = y;
		w = 70;
		h = 64;
	}

	~ki(){}

	void dibujar(BufferedGraphics^buffer);

	void set_x_y(int x, int y);
	int get_x() { return x; }
	int get_y() { return y; }	
};

void ki::dibujar(BufferedGraphics^buffer) {

	Bitmap^bmp = gcnew Bitmap(gcnew System::String("Imagenes\\Enemigos Pequeños\\estrella.png"));
	Rectangle porcion = Rectangle(1, 1, w, h);
	Rectangle destino = Rectangle(x, y, w, h);
	buffer->Graphics->DrawImage(bmp, destino, porcion, GraphicsUnit::Pixel);
}

void ki::set_x_y(int x, int y) {

	this->x = x;
	this->y = y;
}


