/*
 * EtiquetaR.h
 *
 *  Created on: 04/08/2014
 *      Author: msacco
 */

#ifndef ETIQUETAR_H_
#define ETIQUETAR_H_

class EtiquetaR {
private:
	int valorInt;
	float valorFloat;
	char *valorChar;
	int longMaxima;
	char cadena[10];
	int x,y,tamano;
	int R,G,B;
public:
	EtiquetaR(int px,int py,int tam,int lon);
	void setValor(int valor);
	void setValor(float valor);
	void setValor(char * valor);
	int getValorInt(void);
	float getValorFloat(void);
	char* gatValorChar(void);
	void setRGB(int rojo,int verde,int azul);
	void refrescar(int valor);
	void refrescar(float valor);
	void refrescar(char * valor);
};

#endif /* ETIQUETAR_H_ */
