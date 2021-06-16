#pragma once
#include<iostream>
#include"CCiudadano.h"
using namespace System::Drawing;

class CAliado 
{
private:
	int x, y;
	int dx, dy;
	int ancho, alto;
	int idx, idy;
	int posCiudadanoElegido;
	bool MisionCumplid;
	bool posFinaX;
	bool posFinaY;
public:
	CAliado(int ancho, int alto)  {
		this->ancho = ancho;
		this->alto = alto;
		idx = idy = 0;
		dx = dy = 7;
		x = 275;
		y = 260;
		posCiudadanoElegido = rand() % 3 + 0;

		MisionCumplid = false;
		posFinaX = false;
		posFinaY = false;
	}
	~CAliado(){}
	void dibujar(Graphics^ g, Bitmap^ bmp) {
		Rectangle sectionShow = Rectangle(idx * ancho, idy * alto, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho * 0.7, alto * 0.7);
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
			break;
		}
		idx++;
		if (idx > 3)idx = 0;
	}
	void cumplirMision(CCiudadano* Ciudadano) {
		
		//ir a la posición del ciudadano elegido
		if (x == Ciudadano->getX()) {
			x += 0;
		}
		else if (x > Ciudadano->getX()) {
			x -= dx;
			idy = 1;
		}
		else if (x < Ciudadano->getX()) {
			x += dx;
			idy = 2;
		}

		if (y == Ciudadano->getY()) {
			y += 0;
		}
		else if (y > Ciudadano->getY()) {
			y -= dy;
			idy = 3;
		}
		else if (y < Ciudadano->getY()) {
			y += dy;
			idy = 0;
		}

		idx++;
		if (idx > 3)idx = 0;
	}
	void TerminarMision(int tx, int ty) {

		//dirigirse al hospital
		if (x == tx) {
			x += 0;
			posFinaX = true;
		}
		else if (x > tx) {
			x -= dx;
			idy = 1;
		}
		else if (x < tx) {
			x += dx;
			idy = 2;
		}

		if (y == ty) {
			y += 0;
			idy = 3;
			posFinaY = true;
		}
		else if (y > ty) {
			y -= dy;
			idy = 3;
		}
		else if (y < ty) {
			y += dy;
			idy = 0;
		}
		idx++;
		if (idx > 3)idx = 0;
	}
	void setMisionCumplid(bool b) { MisionCumplid = b; }
	bool getMisionCumplid() { return MisionCumplid; }
	bool getPosFinal() {
		if (posFinaX == posFinaY == true) { return true; }
		else { return false; }
	}
	int getX() { return x; }
	int getY() { return y; }
	int getAncho() { return ancho; }
	int getAlto() { return alto; }
	int getposCiudadanoElegido() { return posCiudadanoElegido; }

};

