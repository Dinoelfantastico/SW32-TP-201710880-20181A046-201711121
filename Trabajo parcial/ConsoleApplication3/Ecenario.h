
#ifndef __ESCENARIO__
#define __ESCENARIO__

using namespace System::Drawing;

#define FILAS 20
#define COLUMNAS 30

class CEcenario
{
	int **matriz;
	int numMapa;

public:
	CEcenario() {

		numMapa = 0;
		matriz = new int *[FILAS];

		for (int i = 0; i < FILAS; i++) {

			matriz[i] = new int[COLUMNAS];

		}
	
	}
	~CEcenario() {}

	void GeneraContorno() {

		for (int i = 0; i < FILAS; i++) {

			for (int j = 0; j < COLUMNAS; j++) {

				if (i == 0 || i == FILAS -1) matriz[i][j] = 1;
				if (j == 0 || j == COLUMNAS - 1) matriz[i][j] = 1;

			}

		}

	}
	void GeneraMapa1() {

		//GeneraContorno();

	}
	void GeneraMapa2() {
	//	GeneraContorno();
		
	}
	void GeneraMapa3() {
		
		//GeneraContorno();
		/*for (int i = 0; i < FILAS; i++) {

			for (int j = 0; j < COLUMNAS; j++) {

				if ((i == 4 && j == 11) || (i == 5 && j == 10) || (i == 5 && j == 11) || (i == 6 && j == 10) || (i == 6 && j == 11) || (i == 11 && j == 5)
					|| (i == 11 && j == 6) || (i == 11 && j == 20) || (i == 12 && j == 5) || (i == 12 && j == 6) || (i == 12 && j == 20) || (i == 13 && j == 5)
					|| (i == 13 && j == 6) || (i == 13 && j == 20) || (i == 14 && j == 5) || (i == 14 && j == 6) || (i == 14 && j == 20) || (i == 15 && j == 5) || (i == 15 && j == 6)
					|| (i == 15 && j == 20) || (i == 16 && j == 5) || (i == 16 && j == 6) || (i == 16 && j == 20) || (i == 17 && j == 5) || (i == 17 && j == 6) || (i == 17 && j == 20) || (i == 18 && j == 5) ||
					(i == 18 && j == 6) || (i == 18 && j == 20) ||(i==1 && j ==20 )|| (i ==2 && j ==20 )|| (i ==3 && j ==20 )|| (i ==4 && j ==20 )|| (i ==5 && j ==20 )|| (i ==6 && j == 20)) {
					matriz[i][j] = 1;
				}

			}

		}*/

	}

	void GeneraMapa4() {

	//	GeneraContorno();
		/*for (int i = 0; i < FILAS; i++) {

			for (int j = 0; j < COLUMNAS; j++) {

				if ((i == 4 && j == 11) || (i == 5 && j == 10) || (i == 5 && j == 11) || (i == 6 && j == 10) || (i == 6 && j == 11) || (i == 11 && j == 5)
					|| (i == 11 && j == 6) || (i == 11 && j == 20) || (i == 12 && j == 5) || (i == 12 && j == 6) || (i == 12 && j == 20) || (i == 13 && j == 5)
					|| (i == 13 && j == 6) || (i == 13 && j == 20) || (i == 14 && j == 5) || (i == 14 && j == 6) || (i == 14 && j == 20) || (i == 15 && j == 5) || (i == 15 && j == 6)
					|| (i == 15 && j == 20) || (i == 16 && j == 5) || (i == 16 && j == 6) || (i == 16 && j == 20) || (i == 17 && j == 5) || (i == 17 && j == 6) || (i == 17 && j == 20) || (i == 18 && j == 5) ||
					(i == 18 && j == 6) || (i == 18 && j == 20) || (i == 1 && j == 20) || (i == 2 && j == 20) || (i == 3 && j == 20) || (i == 4 && j == 20) || (i == 5 && j == 20) || (i == 6 && j == 20)) {
					matriz[i][j] = 1;
				}

			}

		}
		*/

	}

	int ** GetMatriz() {

		return matriz;

	}

	void Dibujar(Graphics^ g, Bitmap^ bmpBloque, Bitmap^ bmpEspinas, Bitmap^bmpFondo)
	{
		
		Rectangle areaDibujo(0, 0, g->VisibleClipBounds.Width, g->VisibleClipBounds.Height);
		g->DrawImage(bmpFondo, areaDibujo);

		int y = 0;

		for (int i = 0; i < FILAS; i++)
		{
			int x = 0;
			for (int j = 0; j < COLUMNAS; j++)
			{
				if (matriz[i][j] == 1)
				{
					g->DrawImage(bmpBloque, x, y, 30, 30);
				}
				
				x += 30;
			}
			y += 30;
		}
	}

};

#endif // !__ESCENARIO__