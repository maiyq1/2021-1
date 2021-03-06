#pragma once
using namespace System::Drawing;
class CLider
{
private:
	int x, y;
	int dx, dy;
	int ancho, alto;
	int idx, idy;
public:
	CLider(int ancho, int alto){
		
		this->ancho = ancho;
		this->alto = alto;
		idx = idy = 0;
		dx = dy = 7;
		x = 292;
		y = 105;
	}
	~CLider(){}
	void dibujar(Graphics^ g, Bitmap^ bmp) {
		Rectangle sectionShow = Rectangle(idx * ancho, idy * alto, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho * 1.0, alto * 1.0);
		g->DrawImage(bmp, zoom, sectionShow, GraphicsUnit::Pixel);
	}
	void mover(Graphics^ g, char i) {
		switch (i)
		{
		case 'A':
			if (x > 110) {
				x -= dx;
				idy = 1;
			}
			break;
		case 'D':
			if (x + ancho * 1.0 < g->VisibleClipBounds.Width - 50) {
				x += dx;
				idy = 2;
			}
			break;
		case 'W':
			if (y > 100) {
				y -= dy;
				idy = 3;
			}
			break;
		case 'S':
			if (y + alto * 1.0 < g->VisibleClipBounds.Height - 110) {
				y += dy;
				idy = 0;
			}
		}
		idx++;
		if (idx > 2)idx = 0;
	}
	int getX() { return x; }
	int getY() { return y; }
	int getAncho() { return ancho; }
	int getAlto() { return alto; }
};
