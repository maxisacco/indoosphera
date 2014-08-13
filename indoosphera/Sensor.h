/*
 * Sensor.h
 *
 *  Created on: 13/08/2014
 *      Author: msacco
 */

#ifndef SENSOR_H_
#define SENSOR_H_

class Sensor {
private:
	unsigned long valorLast;
	int pin;
public:
	Sensor(int numPin);
	virtual ~Sensor();
	virtual unsigned long getValorRaw(void);
	virtual float getMagnitud(void);
};


class SensorHumedadTierra : Sensor {
public:
	float getMagnitud(void);
	unsigned long getValorRaw(void);
};
class SensorDistancia : Sensor {
	int pinTrigger;
public:
	SensorDistancia (int numPinTri, int numPinPul)
	float getMagnitud(void);
	unsigned long getValorRaw(void);

};
class SensorTemperatura : Sensor {
public:
	float getMagnitud(void);
	unsigned long getValorRaw(void);
};

#endif /* SENSOR_H_ */
