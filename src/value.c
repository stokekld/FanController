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

#include "value.h"
#include "insertar.h"


/////////////////////////////////////////////////////////////////////////////
//  Function: int setValue(int pin, int value)
//  Input:    número de pin, valor del pin
//  Output:   none
//  Overview: Inserta valor ("1" o "0") en el GPIO
/////////////////////////////////////////////////////////////////////////////
int setValue(int pin, int value)
{

	char path[100];
	char valueString[2];
	sprintf(path, "%sgpio%d/%s", GPIO, pin, "value");
	sprintf(valueString, "%d", value);
	insertar(path, valueString);
}

/////////////////////////////////////////////////////////////////////////////
//  Function: int getValue(int pin)
//  Input:    número de pin
//  Output:   valor int del pin ó -1 si hay error
//  Overview: Obtiene valor ("1" o "0") del GPIO
/////////////////////////////////////////////////////////////////////////////
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
