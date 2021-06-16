#pragma once
#include<iostream>
#include"Dependencias.h"
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
		Rectangle zoom = Rectangle(x, y, ancho * 0.8, alto * 0.8);
		g->DrawImage(bmp, zoom, sectionShow, GraphicsUnit::Pixel);
	}
	void mover(char i) {
		switch (i)
		{
		case 'A':
			if (x > 110) {
				x -= dx;
				idy = 1;
			}
			break;
		case 'W':
			if (y > 100) {
				y -= dy;
				idy = 3;
			}
			break;
		}
		idx++;
		if (idx > 3)idx = 0;
	}
	int getX() { return x; }
	int getY() { return y; }
	int getAncho() { return ancho; }
	int getAlto() { return alto; }
};
