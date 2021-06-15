#pragma once
using namespace System::Drawing;

class CAliado 
{
private:
	int x, y;
	int dx, dy;
	int ancho, alto;
	int idx, idy;
public:
	CAliado(int ancho, int alto)  {
		this->ancho = ancho;
		this->alto = alto;
		idx = idy = 0;
		dx = dy = 8;
		x = rand() % 700 + 5;
		y = rand() % 400 + 100;
	}
	~CAliado(){}

	void dibujar(Graphics^ g, Bitmap^ bmp) {
		Rectangle sectionShow = Rectangle(idx * ancho, idy * alto, ancho, alto);
		Rectangle zoom = Rectangle(x, y, (double)ancho * 0.8, (double)alto * 0.8);
		g->DrawImage(bmp, zoom, sectionShow, GraphicsUnit::Pixel);
	}

	void mover(Graphics^ g) {
		
		// movimiento Horizontal
		if (x + ancho * 1.0 > g->VisibleClipBounds.Width || x < 0)dx *= -1;

		if (dx > 0)idy = 2;
		else idy = 1;
		x += dx;
		
		idx++;
		if (idx > 3)idx = 0;
	}

	int getX() { return x; }
	int getY() { return y; }
	double getAncho() { return ancho; }
	double getAlto() { return alto; }
};

