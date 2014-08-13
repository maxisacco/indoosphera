/*
 * periodo.h
 *
 *  Created on: 08/08/2014
 *      Author: msacco
 */

#ifndef PERIODO_H_
#define PERIODO_H_

class periodo {
private:
	int temperaturaMin;
	int temperaturaMax;
	int humedadMin;
	int humedadMax;
	int tiempoMax;
	int alturaMax;
	int horasLuz;
public:
	periodo();
	~periodo();

	int getAlturaMax() const {
		return alturaMax;
	}

	void setAlturaMax(int alturaMax) {
		this->alturaMax = alturaMax;
	}

	int getHorasLuz() const {
		return horasLuz;
	}

	void setHorasLuz(int horasLuz) {
		this->horasLuz = horasLuz;
	}

	int getHumedadMax() const {
		return humedadMax;
	}

	void setHumedadMax(int humedadMax) {
		this->humedadMax = humedadMax;
	}

	int getHumedadMin() const {
		return humedadMin;
	}

	void setHumedadMin(int humedadMin) {
		this->humedadMin = humedadMin;
	}

	int getTemperaturaMax() const {
		return temperaturaMax;
	}

	void setTemperaturaMax(int temperaturaMax) {
		this->temperaturaMax = temperaturaMax;
	}

	int getTemperaturaMin() const {
		return temperaturaMin;
	}

	void setTemperaturaMin(int temperaturaMin) {
		this->temperaturaMin = temperaturaMin;
	}

	int getTiempoMax() const {
		return tiempoMax;
	}

	void setTiempoMax(int tiempoMax) {
		this->tiempoMax = tiempoMax;
	}
};

#endif /* PERIODO_H_ */
