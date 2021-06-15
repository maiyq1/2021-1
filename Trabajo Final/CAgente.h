#pragma once
#include<iostream>
using namespace System::Drawing;
class CAgente
{
private:
	int x, y;
	int dx, dy;
	int ancho, alto;
	int idx, idy;
public:
	CAgente(int ancho, int alto) {
		this->ancho = ancho;
		this->alto = alto;
		idx = idy = 0;
		dx = dy = 6;
		x = rand() % 700 + 5;
		y = 610;
	}
	~CAgente(){}


	void dibujar(Graphics^ g, Bitmap^ bmp) {
		Rectangle sectionShow = Rectangle(idx * ancho, idy * alto, ancho, alto);
		Rectangle zoom = Rectangle(x, y, (double)ancho * 1.0, (double)alto * 1.0);
		g->DrawImage(bmp, zoom, sectionShow, GraphicsUnit::Pixel);
	}
	void mover(Graphics^ g) {
		
		//movimient vertical
		if (y + alto * 1.0 > g->VisibleClipBounds.Height || y < 200)dy *= -1;

		if (dy > 0)idy = 0;
		else idy = 3;
		y += dy;

		idx++;
		if (idx > 3)idx = 0;
	}

	int getX() { return x; }
	int getY() { return y; }
	double getAncho() { return ancho; }
	double getAlto() { return alto; }
};
