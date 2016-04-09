#include <stdio.h>
#include <unistd.h>

#include "reservacion.h"
#include "direccion.h"
#include "value.h"
#include "temperatura.h"


/**
* Variable globales
*/
int DEBUG = 1;
char *GPIO = "/sys/class/gpio/";
//char *GPIO = "./debug/sys/class/gpio/";
char *TEMP = "/sys/class/thermal/thermal_zone0/temp";

#define TEMPMAX 50
#define TEMPMIN 45

void main()
{
	int pin = 1, temp, status = 0;


	reservaPin(pin);
	setDireccion(pin, "out");

	while(1)
	{
		temp = leeTemp();
		printf("%d\n", temp);

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