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

#include "direccion.h"
#include "insertar.h"

/**
* Inserta la dirección del pin,
* puede ser in, out.
*/
int setDireccion(int pin, char *direction)
{
	char path[100];

	sprintf(path, "%sgpio%d/%s", GPIO, pin, "direction");

	insertar(path, direction);
}
