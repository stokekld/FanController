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