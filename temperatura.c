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

	temp[0] = fgetc(fd);
	temp[1] = fgetc(fd);

	real = (temp[0] - '0') * 10 + (temp[1] - '0');

	return real;
}