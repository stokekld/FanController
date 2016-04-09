#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include "reservacion.h"
#include "insertar.h"

/**
* Reserva el pin del gpio
*/
int reservaPin(int pin)
{
	char path[100];
	char cadena[10];

	sprintf(path, "%s%s", GPIO, EXPORT);
	sprintf(cadena, "%d", pin);

	insertar(path, cadena);
}

/**
* Libera el pin del gpio
*/
int liberaPin(int pin)
{
	char path[100];
	char cadena[10];

	sprintf(path, "%s%s", GPIO, UNEXPORT);
	sprintf(cadena, "%d", pin);

	insertar(path, cadena);
}