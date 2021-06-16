#pragma once
using namespace System::Drawing;
class CCiudadano
{
private:
	int x, y;
	int dx, dy;
	int ancho, alto;
	int idx, idy;
public:
	CCiudadano(int ancho, int alto, int i) { 
		
		this->ancho = ancho;
		this->alto = alto;
		idx = 1;
		idy = 0;
		dx = dy = 3;

		if      (i == 0) { x = 650; y = 100; }// posicion de habitante 1
		else if (i == 1) { x = 590; y = 290; }// posicion de habitante 2
		else if (i == 2) { x = 540; y = 435; }// posicion de habitante 3
	}
	~CCiudadano(){}

	void dibujar(Graphics^ g, Bitmap^ bmp) {
		Rectangle sectionShow = Rectangle(idx * ancho, idy * alto, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho * 0.9, alto * 0.9);
		g->DrawImage(bmp, zoom, sectionShow, GraphicsUnit::Pixel);
	}
	void mover(Graphics^ g, int i) {
		switch (i)
		{
		case 0:                     //ciudadano 1
			//movimiento horizontal
			if (x + ancho * 0.9 > 710 || x < 630)dx *= -1;

			if (dx > 0)idy = 2;
			else idy = 1;
			x += dx;

			break;
		case 1:	                    //ciudadano 2	
			//movimiento horizontal
			if (x + ancho * 0.9 > 630 || x < 570)dx *= -1;

			if (dx > 0)idy = 2;
			else idy = 1;
			x += dx;

			break;
		case 2:		                //ciudadano 3
			//movimiento horizontal
			if (x + ancho * 0.9 > 620 || x < 480)dx *= -1;

			if (dx > 0)idy = 2;
			else idy = 1;
			x += dx;

			break;
		}

		idx++;			
		if (idx > 2)idx = 0;
	}

	int getX() { return x; }
	int getY() { return y; }
	int getAncho() { return ancho; }
	int getAlto() { return alto; }
};
