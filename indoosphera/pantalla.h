/*
 * pantalla.h
 *
 *  Created on: 03/08/2014
 *      Author: msacco
 */
#include "EtiquetaR.h"
#ifndef PANTALLA_H_
#define PANTALLA_H_

class pantalla {
private:
	pantalla *anterior;
	TouchScreenMenuItem * menuItems;
	TouchScreenMenu * pantallaActual;
	pantalla * (*accion)(pantalla * este,TouchScreenMenuItem *);
	pantalla * (*accionBoton)(pantalla * este);
	bool refrescable;
	TouchScreenArea * botones;
	int botonesLen;
	EtiquetaR * etiquetasR;
	int etiquetasRLen;
	TouchScreenLabel * label;
	int labelLen;

public:
	pantalla(void);
	pantalla(pantalla * ant,             // puntero a pantalla anterior en el arbol de menues
			TouchScreenMenuItem * Items, // puntero a arreglo con los Item de este menu
			pantalla * (*pf)(pantalla * este,TouchScreenMenuItem *item), //puntero a funcion acciones x Item
			TouchScreenMenu * actual,    // puntero al menu
			TouchScreenArea * boton,
			int botonLen,
			pantalla * (*aBoton)(pantalla * este),
			EtiquetaR * etiqR,
			int etiqRLen,
			TouchScreenLabel * lbl,
			int lblLen);   // puntero a arreglo de botones
	virtual ~pantalla();
	void dibujar(void);
	void refrescar(void);
	pantalla *ejecutar(void);
	pantalla*& getAnterior() ;
	void setAnterior( pantalla* anterior);
	bool getRefrescable(void);
	int getBotonesLen(void);
	TouchScreenArea * getBotones(void);
};

#endif /* PANTALLA_H_ */
