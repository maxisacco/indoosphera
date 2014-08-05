/*
 * Clock.h
 *
 *  Created on: 02/08/2014
 *      Author: msacco
 */

#ifndef CLOCK_H_
#define CLOCK_H_

class Clock {
public:
	Clock();
	~Clock();
	void setMinute(int valor);
	void setHora(int valor);
	void setDia(int valor);
	int getMinute(void);
	int getHora(void);
	int getDia(void);
	void tick(void);
//	String getTexto(void);
private:
	int hora;
	int minuto;
	int segundo;
	int dias;
};

#endif /* CLOCK_H_ */
