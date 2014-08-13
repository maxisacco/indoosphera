/*
 * Sensor.cpp
 *
 *  Created on: 13/08/2014
 *      Author: msacco
 */
#include <Arduino.h>
#include "Sensor.h"

Sensor::Sensor(int numPin) {
	this->pin=numPin;
	this->valorLast=0;
}

SensorDistancia::SensorDistancia(int numPinTri, int numPinPul){
	this->pinTrigger=numPinTri;
	this->pin=numPinPul;
}
unsigned long SensorTemperatura::getValorRaw(void){
	this->valorLast=analogRead(this->pin);
	return this->valorLast;
}
float SensorTemperatura::getMagnitud(void){
	this->valorLast=analogRead(this->pin);
	return 4100/(log(10000*((1023.0/this->valorLast)-1)/0.01066))-273.15;
}
unsigned long SensorHumedadTierra::getValorRaw(void){
	this->valorLast=analogRead(this->pin);
	return this->valorLast;
}
float SensorHumedadTierra::getMagnitud(void){
	this->valorLast=analogRead(this->pin);
	return 100.0-(this->valorLast/10,24);
}
unsigned long SensorDistancia::getValorRaw(void){
	//Initialize the sensor
	  digitalWrite(this->pinTrigger,LOW);
	  delayMicroseconds(5);
	//We start the measurements
	//We send out a signal activating the trigger output for 10 microseconds
	  digitalWrite(this->pinTrigger,HIGH);
	  delayMicroseconds(10);
	  digitalWrite(this->pinTrigger,LOW);
	//We acquire the data and We convert the measurement to meters
	 this->valorLast=pulseIn(pin,HIGH); //We measure the pulse width
	                              //(When the pin is HIGH It will measure
	                              //the amount of time until it is LOW)
	return this->valorLast;
}
float SensorDistancia::getMagnitud(void){
	return 0.0001657*this->getValorRaw();
}
