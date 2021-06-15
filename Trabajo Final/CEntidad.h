#pragma once

class CEntidad
{
protected:
	int x, y; 
	int dx, dy;
	int ancho, alto;
	int idx, idy;

public:
	CEntidad(){}
	~CEntidad(){}

	virtual void mover() {}


};
