/*
 * pantalla.h
 *
 *  Created on: 03/08/2014
 *      Author: msacco
 */

#include <TouchScreenMenu.h>
#include <TouchScreen.h>
#include <TFT.h>
#include <WString.h>
#include <stddef.h>
#include "pantalla.h"
#include "EtiquetaR.h"

pantalla::pantalla (void){
	anterior=NULL;
	menuItems=NULL;
	accion=NULL;
	pantallaActual=NULL;
	botones=NULL;
	botonesLen=0;
	accionBoton=NULL;
	this->etiquetasR=NULL;
	this->etiquetasRLen=0;
	this->label = NULL;
	this->labelLen=0;
}
pantalla::pantalla(pantalla * ant,
					TouchScreenMenuItem * Items,
					pantalla * (*pf)(pantalla * este, TouchScreenMenuItem *item),
					TouchScreenMenu * actual,
					TouchScreenArea * boton,
					int botonLen,
					pantalla * (*aBoton)(pantalla * este),
					EtiquetaR * etiqR,
					int etiqRLen,
					TouchScreenLabel * lbl,
					int lblLen){
		anterior=ant;
		menuItems=Items;
		accion=pf;
		pantallaActual=actual;
		botones=boton;
		botonesLen=botonLen;
		accionBoton=aBoton;
		this->etiquetasR=etiqR;
		this->etiquetasRLen=etiqRLen;
		this->label=lbl;
		this->labelLen=lblLen;
}
pantalla::~pantalla(void){}

void pantalla::dibujar(void){
	pantallaActual->draw();
	for( int i=0; i<botonesLen; i++)
		botones[i].draw();
	for( int i=0; i<labelLen; i++)
		label[i].draw();
}




pantalla*& pantalla::getAnterior()  {
			return anterior;
		}

void pantalla::setAnterior( pantalla* anterior) {
			this->anterior = anterior;
		}


pantalla* pantalla::ejecutar(void){
	TouchScreenMenuItem *item = this->pantallaActual->process(false);
	if (item != NULL)
		return accion(this,item);


	return this->accionBoton(this);

}

int pantalla::getBotonesLen(void){
	return this->botonesLen;
}
TouchScreenArea * pantalla::getBotones(void){return this->botones;}
