#include <stdio.h>
#include <unistd.h>

#include "reservacion.h"
#include "direccion.h"
#include "value.h"
#include "temperatura.h"


/**
* Variable globales
*/
int DEBUG = 0;
char *GPIO = "/sys/class/gpio/";
char *TEMP = "/sys/class/thermal/thermal_zone0/temp";

#define TEMPMAX 45 //Temperatura maxima RPi2
#define TEMPMIN 40 //Temperatura minima RPi2

void main()
{	/*Usamos el GPIO21 que corresponde a el pin 40 del conector*/
	int pin = 21, temp, status = 0;


	reservaPin(pin);
	setDireccion(pin, "out");

	while(1)
	{
		temp = leeTemp();

		if(temp >= TEMPMAX)
		{
			status = 1;
			setValue(pin, 1);
		}
		else if (temp <= TEMPMIN)
		{
			status = 0;
			setValue(pin, 0);
		}

		usleep(100000);
	}

}
