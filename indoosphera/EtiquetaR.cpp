/*
 * EtiquetaR.cpp
 *
 *  Created on: 04/08/2014
 *      Author: msacco
 */


#include "EtiquetaR.h"

EtiquetaR::EtiquetaR(TouchScreenLabel * lbl){
	this->valorInt=0;
	this->valorFloat=0.0;
	this->valorChar=NULL;
	this->etiqueta=lbl;
	this->_refrescar=false;
}
void EtiquetaR::setValor(int valor){
	if (this->valorInt!=valor){
		this->valorInt=valor;
		((String)valor).toCharArray(cadena,CADENALONG);
		this->etiqueta->setText(cadena);
		this->_refrescar=true;
	} else
		this->_refrescar=false;
}

void EtiquetaR::setValor(float valor){
	if (this->valorFloat!=valor){
		this->valorFloat=valor;
		((String)valor).toCharArray(cadena,CADENALONG);
		this->etiqueta->setText(cadena);
		this->_refrescar=true;
	} else
		this->_refrescar=false;
}
void EtiquetaR::setValor(char * valor){
	if (strcmp(this->valorChar,valor)){
		this->valorChar=valor;
		this->etiqueta->setText(this->valorChar);
		this->_refrescar=true;
	} else
		this->_refrescar=false;
}
int EtiquetaR::getValorInt(void){
	return this->valorInt;
}
float EtiquetaR::getValorFloat(void){
	return this->valorFloat;
}
char* EtiquetaR::getValorChar(void){
	return this->valorChar;
}
void EtiquetaR::refrescar(void){
	if (this->_refrescar)
		this->etiqueta->draw();

}
