#pragma once
#include<iostream>
#include<vector>
#include"CAgente.h"
#include"CAliado.h"
#include"CCiudadano.h"
#include"CLider.h"
#include"Dependencias.h"

using namespace System::Drawing;
class CControlador
{
private:
	CLider* lider;
	vector<CAliado*>enfermeras;
	vector<CAgente*>virus;

public:
	CControlador(Bitmap^bmpLider) {
		lider = new CLider(bmpLider->Width / 3, bmpLider->Height / 4);//Width=ancho del sprite//Height=alto del sprite
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

	void moverEnfermeras(Graphics^ g) {
		for (int i = 0; i < enfermeras.size(); i++)
		{
			enfermeras[i]->mover(g);
			
		}
	}

	void moverVirus(Graphics^ g) {
		for (int i = 0; i < virus.size(); i++)
		{
			virus[i]->mover(g);
		}
	}

	CLider* getLider() { return lider; }
};


