#pragma once

using namespace System::Drawing;

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

	void Dibuja(Graphics^ g, Bitmap^ energia) {

		g->DrawImage(energia,x,y,w,h);

	}

	void set_x_y(int x, int y) {

		this->x = x;
		this->y = y;
	}
	int get_x() { return x; }
	int get_y() { return y; }

};




