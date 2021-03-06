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

/////////////////////////////////////////////////////////////////////////////
//  Function: int reservaPin(int pin)
//  Input:    número de pin
//  Output:   none
//  Overview: Genera cadena para reservar pin de los GPIOs e insertar en archivo
/////////////////////////////////////////////////////////////////////////////
int reservaPin(int pin)
{
	char path[100];
	char pinString[10];
	sprintf(path, "%s%s", GPIO, EXPORT);
	sprintf(pinString, "%d", pin);
	insertar(path, pinString);
}

/////////////////////////////////////////////////////////////////////////////
//  Function: int liberaPin(int pin)
//  Input:    número de pin
//  Output:   none
//  Overview: Genera cadena para liberar pin de los GPIOs e insertar en archivo
/////////////////////////////////////////////////////////////////////////////
int liberaPin(int pin)
{
	char path[100];
	char pinString[10];
	sprintf(path, "%s%s", GPIO, UNEXPORT);
	sprintf(pinString, "%d", pin);
	insertar(path, pinString);
}
