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
#include <stdlib.h>

/**
* Inserta un string a un archivo, 
* si no existe sale completamente
*/
int insertar(char *path, char *string)
{
	FILE *fd;

	fd = fopen(path, "w");

	if (!fd)
	{
		printf("no existe el archivo\n");
		exit(0);		
	}

	// Inserta cadena al archivo
	fprintf(fd, "%s\n", string);
	fclose(fd);
	
}