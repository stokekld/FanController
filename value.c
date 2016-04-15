#include <stdio.h>

#include "value.h"
#include "insertar.h"

/**
* Inserta un valor en el pin
*/
int setValue(int pin, int value)
{
	// Cadena para path de archivo
	char path[100];
	char valueString[2];

	// Escribiendo en la variable el path del archivo para insertar el valor
	sprintf(path, "%sgpio%d/%s", GPIO, pin, "value");
	// Convierte el valor a string para insertarlo en el archivo
	sprintf(valueString, "%d", value);

	// inserta valor
	insertar(path, valueString);
}

/**
* Obtiene un valor en el pin
*/
int getValue(int pin)
{
	// Cadena para path de archivo
	char path[100];

	// Escribiendo en la variable el path del archivo para obtener el valor
	sprintf(path, "%sgpio%d/%s", GPIO, pin, "value");

	FILE *fd;

	fd = fopen(path, "r");

	if (!fd)
	{
		printf("no existe el archivo\n");
		return -1;		
	}

	// Retornando el valor como entero
	return fgetc(fd) - '0';

}