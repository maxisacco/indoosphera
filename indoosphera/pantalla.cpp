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
	refrescable=false;
	accionBoton=NULL;
}
pantalla::pantalla(pantalla * ant,
					TouchScreenMenuItem * Items,
					pantalla * (*pf)(pantalla * este, TouchScreenMenuItem *item),
					TouchScreenMenu * actual,
					TouchScreenArea * boton,
					int botonLen,
					pantalla * (*aBoton)(pantalla * este),
					bool refresh){
		anterior=ant;
		menuItems=Items;
		accion=pf;
		pantallaActual=actual;
		botones=boton;
		botonesLen=botonLen;
		refrescable=refresh;
		accionBoton=aBoton;

}
pantalla::~pantalla(void){}
void pantalla::refrescar(void){
	if (this->refrescable)
		this->dibujar();
}
void pantalla::dibujar(void){
	pantallaActual->draw();
	for( int i=0; i<botonesLen; i++)
		botones[i].draw();
}




pantalla*& pantalla::getAnterior()  {
			return anterior;
		}

void pantalla::setAnterior( pantalla* anterior) {
			this->anterior = anterior;
		}


pantalla* pantalla::ejecutar(void){
	pantalla *res=this;
	TouchScreenMenuItem *item = this->pantallaActual->process(false);
	if (item != NULL)
		return accion(this,item);
	return res;
}

bool pantalla::gerRefrescable(void){return this->refrescable;}
