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
	// Cadena para path de archivo
	char path[100];
	char pinString[10];

	// Escribiendo en la variable el path del archivo para reservar
	sprintf(path, "%s%s", GPIO, EXPORT);
	// Convierte el pin a string para insertarlo en el archivo para reservar
	sprintf(pinString, "%d", pin);

	// Inserta en archivo
	insertar(path, pinString);
}

/**
* Libera el pin del gpio
*/
int liberaPin(int pin)
{
	// Cadena para path de archivo
	char path[100];
	char pinString[10];

	// Escribiendo en la variable el path del archivo para liberar
	sprintf(path, "%s%s", GPIO, UNEXPORT);
	// Convierte el pin a string para insertarlo en el archivo para liberar
	sprintf(pinString, "%d", pin);

	// Inserta en archivo
	insertar(path, pinString);
}