/*
 * Clock.cpp
 *
 *  Created on: 02/08/2014
 *      Author: msacco
 */
//#include <WString.h>
#include "Clock.h"


Clock::Clock() {
	hora=0;
	minuto=0;
	dias=0;
	segundo=0;
}

Clock::~Clock() {
	// TODO Auto-generated destructor stub
}

void Clock::setMinute(int valor){
	minuto=valor;
}
void Clock::setHora(int valor){
	hora=valor;
}
void Clock::setDia(int valor){
	dias=valor;
}
int Clock::getMinute(void){
	return minuto;
}
int Clock::getHora(void){
	return hora;
}
int Clock::getDia(void){
	return dias;
}
void Clock::tick(void){

	segundo++;
	if (segundo>=60){
		segundo=0;
		minuto++;
		if (minuto>=60) {
			minuto=0;
			hora++;
			if (hora>=24){
				hora=0;
				dias++;
			}
		}
	}
}
//String Clock::getTexto(void){
//	return String(hora)+":"+String(minuto)+":"+String(segundo);
//}
