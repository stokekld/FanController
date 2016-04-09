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

	fprintf(fd, "%s\n", string);
	fclose(fd);
	
}