/*
 * Programa.h
 *
 *  Created on: 08/08/2014
 *      Author: msacco
 */


#ifndef PROGRAMA_H_
#define PROGRAMA_H_
#include "periodo.h"
#include <Time/Time.h>

class Programa {
private:
	char id[10];
	periodo *germinacion;
	periodo *crecimiento;
	periodo *floracion;
	periodo * periodoActual;
	int tiempoEjecucion; // #dias
	time_t tiempoComienzo;

public:
	Programa();
	~Programa();

	periodo* getCrecimiento() {
		return crecimiento;
	}

	void setCrecimiento(periodo* crecimiento) {
		this->crecimiento = crecimiento;
	}

	periodo* getFloracion() {
		return floracion;
	}

	void setFloracion(periodo* floracion) {
		this->floracion = floracion;
	}

	 periodo* getGerminacion() {
		return germinacion;
	}

	void setGerminacion(periodo* germinacion) {
		this->germinacion = germinacion;
	}

	char* getId() {
		return id;
	}

	periodo* getPeriodoActual() {
		return periodoActual;
	}

	void setPeriodoActual(periodo* periodoActual) {
		this->periodoActual = periodoActual;
	}

	time_t getTiempoComienzo()  {
		return tiempoComienzo;
	}

	void setTiempoComienzo(time_t tiempoComienzo) {
		this->tiempoComienzo = tiempoComienzo;
	}

	int getTiempoEjecucion() {
		return tiempoEjecucion;
	}

	void setTiempoEjecucion(int tiempoEjecucion) {
		this->tiempoEjecucion = tiempoEjecucion;
	}
};

#endif /* PROGRAMA_H_ */
