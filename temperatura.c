#include <stdio.h>

#include "temperatura.h"

int leeTemp()
{
	FILE *fd;
	char temp[2];
	int real;

	fd = fopen(TEMP, "r");

	if (!fd)
	{
		printf("no existe el archivo\n");
		return -1;		
	}

	// obteniendo digitos del archivo
	temp[0] = fgetc(fd);
	temp[1] = fgetc(fd);

	// convirtiendo string a entero
	real = (temp[0] - '0') * 10 + (temp[1] - '0');
	fclose(fd);
	return real;
}
