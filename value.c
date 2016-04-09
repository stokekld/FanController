#include <stdio.h>

#include "value.h"
#include "insertar.h"

/**
* Inserta un valor en el pin
*/
int setValue(int pin, int value)
{
	char path[100];
	char cadena[2];

	sprintf(path, "%sgpio%d/%s", GPIO, pin, "value");
	sprintf(cadena, "%d", value);

	insertar(path, cadena);
}

/**
* Obtiene un valor en el pin
*/
int getValue(int pin)
{
	char path[100];

	sprintf(path, "%sgpio%d/%s", GPIO, pin, "value");

	FILE *fd;

	fd = fopen(path, "r");

	if (!fd)
	{
		printf("no existe el archivo\n");
		return -1;		
	}

	return fgetc(fd) - '0';

}