#pragma once
#include"Dependencias.h"

class Virus :public CEntidad
{
public:
	Virus(int ancho, int alto) :CEntidad() {
		
		idx = idy = 0;
		dx = dy =0;
		x = 0;
		y =0;
	}
	~Virus(){}


	void dibujar(Graphics^ g, Bitmap^ bmp) {
		Rectangle sectionShow = Rectangle(idx * ancho, idy * alto, ancho, alto);
		Rectangle zoom = Rectangle(x, y, (double)ancho * 1.0, (double)alto * 1.0);
		g->DrawImage(bmp, zoom, sectionShow, GraphicsUnit::Pixel);
	}
	void mover(Graphics^ g, char i) {
		switch (i)
		{
		case 'A':
			if (x > 0) {
				x -= dx;
				idy = 1;
			}
			break;
		case 'D':
			if (x + ancho * 1.0 < g->VisibleClipBounds.Width) {
				x += dx;
				idy = 2;
			}
			break;
		case 'W':
			if (y > 0) {
				y -= dy;
				idy = 3;
			}
			break;
		case 'S':
			if (y + alto * 1.0 < g->VisibleClipBounds.Height) {
				y += dy;
				idy = 0;
			}
		}
		idx++;
		if (idx > 3)idx = 0;
	}

	int getX() { return x; }
	int getY() { return y; }
	double getAncho() { return ancho; }
	double getAlto() { return alto; }
};
