/*
 * Actuador.h
 *
 *  Created on: 13/08/2014
 *      Author: msacco
 */

#ifndef ACTUADOR_H_
#define ACTUADOR_H_

virtual class Actuador {
private:
	unsigned char pin;
public:
	Actuador(unsigned char numPin);
	~Actuador();
	void actuar(unsigned long parametro);
};

class Riego : Actuador {};
class Ventilador: Actuador{};
class Luz : Actuador{};
#endif /* ACTUADOR_H_ */
