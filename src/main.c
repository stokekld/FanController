  /*<Fan Crontoller, control a fan based on the current temperature>
    Copyright (C) <2016>  <Carlos Acosta,Jesus Flores, Rodrigo Galeano,Roberto Guerrero >

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.*/
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
char *TEMP ="/sys/fan_controller/sensor/temp";// "/sys/class/thermal/thermal_zone0/temp";

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
