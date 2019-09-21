#ifndef __JUGADOR__
#define __JUGADOR__

using namespace System::Drawing;

enum Direcciones { ninguna, izquierda, derecha, arriba , abajo};

class CJugador
{
	Direcciones direccion;
	
	int x, y, dx, dy, indiceX, indiceY;
	float ancho, alto;

	int numVidas;

	Rectangle CDI;
	Rectangle CAA;

public:
	CJugador() {
		this->x = (120), this->y = (430), this->dx = (0), this->dy = (0), this->ancho = (64),
			this->alto = (64), this->indiceX = (0), this->indiceY = (0), this->numVidas = (3);
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
	void PierdeJuego() { numVidas = 3; }

	int GetVidas() {

		return numVidas;
	}

	void Dibujar(Graphics^ g, Bitmap^ jugador , int**matriz)
	{
		CDI = Rectangle(x + 15 + dx, y + 5, ancho -40, alto - 10);
		CAA = Rectangle(x + 15, y + 5 + dy, ancho - 40, alto - 10);

		validarMov(matriz);

		Rectangle areaDibujo(x, y, 60, 60);
		Rectangle areaSprite(indiceX*ancho, indiceY*alto, ancho, alto);
		g->DrawImage(jugador, areaDibujo, areaSprite, GraphicsUnit::Pixel);

		x = x + dx;
		y = y + dy;
		indiceX++;
		if (indiceX == 4) {
			indiceX = 0;
		}

	}
	void Mover(Graphics^ g, Bitmap^ jugador, int **matriz)
	{
		switch (direccion)
		{
		case Direcciones::ninguna:
		{
			indiceY = 0;
			indiceX++;
			if (indiceX == 4) {
				indiceX = 0;
			}
		
		
		    this->dy = 0;
			this->dx = 0;

		}break;
		case Direcciones::izquierda:
		{

			indiceY = 1;

			if (indiceX >= 0 && indiceX < 3)
			{
				indiceX++;

			}
			else
			{
				indiceX = 0;
			}

			if (x + dx > 0) {
				dx = -17;
				dy = 0;
			}
			else {
				dx = 0;
				dy = 0;
			}

		}break;
		case Direcciones::derecha:
		{
		
			indiceY = 2;

			if (indiceX >= 0 && indiceX < 3)
			{
				indiceX++;

			}
			else
			{
				indiceX = 0;
			}

			if (x + dx + ancho < g->VisibleClipBounds.Width) {
				dx = 17;
				dy = 0;
			}
			else {
				dx = 0;
				dy = 0;
			}

			

		}break;

		case Direcciones::arriba:
		{
			indiceY = 3;

			if (indiceX >= 0 && indiceX < 3)
			{
				indiceX++;

			}
			else
			{
				indiceX = 0;
			}
			if (y + dy > 0) {
				dx = 0;
				dy = -17;
			}
			else {
				dy = 0;
				dx = 0;
			}

		}break;

		case Direcciones::abajo:
		{
			indiceY = 0;

			if (indiceX >= 0 && indiceX < 3)
			{
				indiceX++;

			}
			else
			{
				indiceX = 0;
			}
			if (y + dy + alto < g->VisibleClipBounds.Height) {
				dx = 0;
				dy = 17;
			}
			else {
				dx = 0;
				dy = 0;
			}
		}break;

		}

		Dibujar(g, jugador,matriz);
	}
	
	void cambiarDireccion(Direcciones direccion)
	{
		this->direccion = direccion;
	}


	Rectangle GetRecJugadorCDI() {

		return Rectangle(x + dx, y , 60 , 60);
	}
	Rectangle GetRecJugadorCAA() {

		return Rectangle(x , y + dy, 60 , 60);
	}

	Rectangle GetJugador() {

		return Rectangle(x,y,ancho,alto);
	}

	//Rectangle GetRectanguloLateralDerecho() {

		//return Rectangle(x +59.999999, y , 60 - 59.999999, 60);
	//}
	//Rectangle GetRectaguloLateralIzquierdo() {

		//return Rectangle(x , y, x+0.00001,60);
	//}


	void SetDx(int d) { this->dx = d; }
	void SetDy(int d) { this->dy = d; }



	//VALIDARMOVIMIENTO

	void validarMov(int ** matriz) {

		int x, y = 0;

		for (int i = 0; i < FILAS; i++)
		{
			x = 0;

			for (int j = 0; j < COLUMNAS; j++)
			{
				Rectangle bloque(x, y, 30, 30);

				if (matriz[i][j] == 1)
				{
					if (CDI.IntersectsWith(bloque)) { dx = 0; }
					if (CAA.IntersectsWith(bloque)) { dy = 0; }
				}
				x += 30;
			}
			y += 30;
		}


	}

};


#endif // !__JUGADOR__
