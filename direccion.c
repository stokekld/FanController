#include <stdio.h>

#include "direccion.h"
#include "insertar.h"

/**
* Inserta la dirección del pin,
* puede ser in, out.
*/
int setDireccion(int pin, char *direction)
{
	// Cadena para path
	char path[100];

	// Escribiendo en variable el path al archivo direccion
	sprintf(path, "%sgpio%d/%s", GPIO, pin, "direction");

	// Inserta direccion en el archivo
	insertar(path, direction);
}