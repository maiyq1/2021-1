#pragma once
#include<iostream>
#include<vector>
#include"CAgente.h"
#include"CAliado.h"
#include"CCiudadano.h"
#include"CLider.h"
using namespace System::Drawing;
class CControlador
{
private:
	CLider* lider;
	vector<CAliado*>enfermeras;
	vector<CAgente*>virus;
	vector<CCiudadano*>ciudadanos;

public:
	CControlador(Bitmap^bmpLider, Bitmap^bmpCiudadano) {
		lider = new CLider(bmpLider->Width / 3, bmpLider->Height / 4);//Width=ancho del sprite//Height=alto del sprite
		for (int i = 0; i < 3; i++)
		{
			ciudadanos.push_back(new CCiudadano(bmpCiudadano->Width / 3, bmpCiudadano->Height / 4, i));
		}
	}
	~CControlador(){}

	void addAliado(Bitmap^bmpAliado) {
		enfermeras.push_back(new CAliado(bmpAliado->Width/4, bmpAliado->Height/4));
	}
	void addAgente(Bitmap^ bmpAgente) {
		virus.push_back(new CAgente(bmpAgente->Width / 4, bmpAgente->Height / 4));
	}
	void dibujarEnfermeras(Graphics^ g, Bitmap^ bmpAliado) {

		for (int i = 0; i < enfermeras.size(); i++)
		{
			enfermeras[i]->dibujar(g, bmpAliado);
		}

	}
	void dibujarVirus(Graphics^ g, Bitmap^ bmpAgente) {

		for (int i = 0; i < virus.size(); i++)
		{
			virus[i]->dibujar(g, bmpAgente);
		}
	}
	void dibujarCiudadanos(Graphics^ g, Bitmap^ bmpCiudadano) {
		for (int i = 0; i < ciudadanos.size(); i++)
		{
			ciudadanos[i]->dibujar(g,bmpCiudadano);
		}
	}
	void moverAliados(Graphics^ g) {
		for (int i = 0; i < enfermeras.size(); i++)
		{
			if (enfermeras[i]->getY() >= 260 && enfermeras[i]->getY() < 300 && enfermeras[i]->getX() == 275) {
				enfermeras[i]->mover(g, 'S');
			}
			else if (enfermeras[i]->getY() >= 300 && enfermeras[i]->getX() > 135 && enfermeras[i]->getX() <= 275) {
				enfermeras[i]->mover(g, 'A');
			}
			else if (enfermeras[i]->getX() <= 135 && enfermeras[i]->getY() > 150 && enfermeras[i]->getY() <= 310) {
				enfermeras[i]->mover(g, 'W');
			}
			else if (enfermeras[i]->getY() <= 150 && enfermeras[i]->getX() < 400) {
				enfermeras[i]->mover(g, 'D');
			}
			else if (enfermeras[i]->getX() >= 400) {
				colision(i);
				if (colision(i)==false) {
					enfermeras[i]->cumplirMision(ciudadanos[enfermeras[i]->getposCiudadanoElegido()]);
					
				}
				if (colision(i)) {
					enfermeras[i]->setMisionCumplid(true);
					//enfermeras[i]->TerminarMision(360, 430);
				}
			}
		}
		//for (int i = 0; i < enfermeras.size(); i++)
		//{
		//	if (enfermeras[i]->getPosFinal()) {
		//		enfermeras.erase(enfermeras.begin() + i);
		//	}
		//}
	}
	void moverVirus(Graphics^ g) {
		for (int i = 0; i < virus.size(); i++)
		{
			virus[i]->mover('W');
		}
	}
	void moverCiudadanos(Graphics^ g) {
		for (int i = 0; i < ciudadanos.size(); i++)
		{
			ciudadanos[i]->mover(g,i);
		}
	}
	bool colision(int i) {
		Rectangle rectObj1 = Rectangle(ciudadanos[enfermeras[i]->getposCiudadanoElegido()]->getX(), ciudadanos[enfermeras[i]->getposCiudadanoElegido()]->getY(), ciudadanos[enfermeras[i]->getposCiudadanoElegido()]->getAncho(), ciudadanos[enfermeras[i]->getposCiudadanoElegido()]->getAlto());
		Rectangle rectObj2 = Rectangle(enfermeras[i]->getX(), enfermeras[i]->getY(), enfermeras[i]->getAncho(), enfermeras[i]->getAlto());
		return rectObj1.IntersectsWith(rectObj2);
	}
	CLider* getLider() { return lider; }
};


