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
	this->cadena[0]='\0';
	this->etiqueta->setText(this->cadena);
}
void EtiquetaR::setValor(int valor){
	if (this->valorInt!=valor){
		this->valorInt=valor;
		unsigned int colorFore=this->etiqueta->getForeColor();
		this->etiqueta->setForeColor(this->etiqueta->getBackColor());
		this->etiqueta->draw();
		((String)valor).toCharArray(cadena,CADENALONG);
		this->etiqueta->setForeColor(colorFore);
		this->etiqueta->draw();
	}
}

void EtiquetaR::setValor(float valor){
	if (this->valorFloat!=valor){
		this->valorFloat=valor;
		unsigned int colorFore=this->etiqueta->getForeColor();
		this->etiqueta->setForeColor(this->etiqueta->getBackColor());
		this->etiqueta->draw();
		((String)valor).toCharArray(cadena,CADENALONG);
		this->etiqueta->setForeColor(colorFore);
		this->etiqueta->draw();
	}
}
void EtiquetaR::setValor(char * valor){
	if (!strcmp(this->valorChar,valor)){
		this->valorChar=valor;
		unsigned int colorFore=this->etiqueta->getForeColor();
		this->etiqueta->setForeColor(this->etiqueta->getBackColor());
		this->etiqueta->draw();
		strcpy(cadena,valorChar);
		this->etiqueta->setForeColor(colorFore);
		this->etiqueta->draw();
	}
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
