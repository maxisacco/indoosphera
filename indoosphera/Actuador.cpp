/*
 * Actuador.cpp
 *
 *  Created on: 13/08/2014
 *      Author: msacco
 */

#include "Actuador.h"

Actuador::Actuador(unsigned char numPin) {
	this->pin=numPin;
}

Actuador::~Actuador() {
	// TODO Auto-generated destructor stub
}

void Actuador::actuar(unsigned long parametro){
	analogWrite(this->pin,parametro);
}


void Riego::actuar(unsigned long parametro){
	digitalWrite(this->pin,HIGH);
	delay(parametro);
	digitalWrite(this->pin,LOW);
}

void Ventilador::actuar(unsigned long parametro){
	analogWrite(this->pin,parametro);
}
void Luz::actuar(unsigned long parametro){
	analogWrite(this->pin,parametro);
}
