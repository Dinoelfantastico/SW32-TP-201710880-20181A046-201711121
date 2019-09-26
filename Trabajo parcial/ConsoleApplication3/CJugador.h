#ifndef __JUGADOR__
#define __JUGADOR__

using namespace System::Drawing;

enum Direcciones { ninguna, izquierda, derecha, arriba , abajo};

class CJugador{
	Direcciones direccion;
	
	int x, y, dx, dy, indiceX, indiceY;
	float ancho, alto;

	int numVidas;
	int energiarecolectada;
public:
	CJugador() {
		this->x = (120), this->y = (430), this->dx = (17), this->dy = (17), this->ancho=(64), this->alto=(64),
			this->indiceX = (0), this->indiceY = (0), this->numVidas = (3); energiarecolectada = 0;
	}
	~CJugador() {}

	int GetX() { return x; };
	int GetY() { return y; };
	void set_vida() {
		numVidas++;
	}
	void SetPosx(int px) { x = px; }
	void SetPosy(int py) { y = py; }
	
	void Setx(int px) { x = px; }

	void PierdeVida() { numVidas--; }
	void PierdeJuego() { numVidas = 3; energiarecolectada = 0; }
	bool GanoJuego() {
		
		if (energiarecolectada == 15) {
			return true;
		}
		return false;
	}
	int get_energiarecolectada() {
		return energiarecolectada;
	}
	void recolecta() {
		energiarecolectada++;
	}
	int GetVidas() {

		return numVidas;
	}

	void Dibujar(Graphics^ g, Bitmap^ jugador)
	{
		Rectangle areaDibujo(x, y, ancho, alto);
		Rectangle areaSprite(indiceX*ancho, indiceY*alto, ancho, alto);
		g->DrawImage(jugador, areaDibujo, areaSprite, GraphicsUnit::Pixel);

		indiceX++;
		if (indiceX == 4) {
			indiceX = 0;
		}

	}
	void Mover(Graphics^ g, Direcciones direccion)
	{
		switch (direccion)
		{
		case Direcciones::ninguna:

			indiceY = 0;
			break;
		case Direcciones::izquierda:
			if (x - dx > 0)
				x -= dx;
			indiceY = 1;
			break;
		case Direcciones::derecha:
			if (x + ancho + dx < 960)
				x += dx;
			indiceY = 2;
			break;
		case Direcciones::arriba:
			if (y - dy > 0)
				y -= dy;
			indiceY = 0;
			break;
		case Direcciones::abajo:
			if (y + alto + dy < g->VisibleClipBounds.Bottom)
				y += dy;
			indiceY = 3;
			break;
		}
	}


		Rectangle GetRecJugadorCDI() {

			return Rectangle(x + dx, y, 60, 60);
		}
		Rectangle GetRecJugadorCAA() {

			return Rectangle(x, y + dy, 60, 60);
		}

		Rectangle GetJugador() {

			return Rectangle(x, y, ancho, alto);
		}

		//Rectangle GetRectanguloLateralDerecho() {

			//return Rectangle(x +59.999999, y , 60 - 59.999999, 60);
		//}
		//Rectangle GetRectaguloLateralIzquierdo() {

			//return Rectangle(x , y, x+0.00001,60);
		//}


		void SetDx(int d) { this->dx = d; }
		void SetDy(int d) { this->dy = d; }
		


	
};


#endif // !__JUGADOR__
