/*
 * EtiquetaR.cpp
 *
 *  Created on: 04/08/2014
 *      Author: msacco
 */

#include <TouchScreenMenu.h>
#include <TouchScreen.h>
#include <TFT.h>
#include <WString.h>
#include "EtiquetaR.h"



//

EtiquetaR::EtiquetaR(int px,int py,int tam,int lon){
	this->valorInt=0;
	this->valorFloat=0.0;
	this->valorChar=NULL;
	this->longMaxima=lon;
	this->cadena[0]='\0';
	this->x=px;
	this->y=py;
	this->tamano=tam;
	this->R=255;
	this->G=255;
	this->B=255;
}
void EtiquetaR::setValor(int valor){
	this->valorInt=valor;
}
void EtiquetaR::setValor(float valor){
	this->valorFloat=valor;
}
void EtiquetaR::setValor(char * valor){
	this->valorChar=valor;
}
int EtiquetaR::getValorInt(void){
	return this->valorInt;
}
float EtiquetaR::getValorFloat(void){
	return this->valorFloat;
}
char* EtiquetaR::gatValorChar(void){
	return this->valorChar;
}
void EtiquetaR::setRGB(int rojo,int verde,int azul){
	this->R=rojo;
	this->G=verde;
	this->B=azul;
}
void EtiquetaR::refrescar(int valor){
	this->valorInt=valor;
	((String)valor).toCharArray(cadena,tamano);
	this->refrescar(cadena);
}
void EtiquetaR::refrescar(float valor){
	this->valorFloat=valor;
	((String)valor).toCharArray(cadena,tamano);
	this->refrescar(cadena);
}
void EtiquetaR::refrescar(char * valor){
	TSC.drawString(cadena,this->x,this->y,3,TSC.createColor(0,0,0));
	strcpy(cadena,valor);
	cadena[tamano]='\0';
	TSC.drawString(cadena,this->x,this->y,3,TSC.createColor(this->R,this->G,this->B));
}
