#include <stdio.h>

#include "direccion.h"
#include "insertar.h"

/**
* Inserta la dirección del pin,
* puede ser in, out.
*/
int setDireccion(int pin, char *direction)
{
	char path[100];

	sprintf(path, "%sgpio%d/%s", GPIO, pin, "direction");

	insertar(path, direction);
}