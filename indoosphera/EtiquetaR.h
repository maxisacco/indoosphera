/*
 * EtiquetaR.h
 *
 *  Created on: 04/08/2014
 *      Author: msacco
 */


#ifndef ETIQUETAR_H_
#define ETIQUETAR_H_

#include <TouchScreenMenu.h>
#include <TouchScreen.h>
#include <TFT.h>
#include <WString.h>
#define CADENALONG 10

class EtiquetaR {
private:
	int valorInt;
	float valorFloat;
	char *valorChar;
	TouchScreenLabel* etiqueta;
	bool _refrescar;
	char cadena[CADENALONG];
public:

	EtiquetaR(TouchScreenLabel * lbl);
	void setValor(int valor);
	void setValor(float valor);
	void setValor(char * valor);
	int getValorInt(void);
	float getValorFloat(void);
	char* getValorChar(void);
	bool getRefrescar(void);
	void refrescar(void);
};

#endif /* ETIQUETAR_H_ */
