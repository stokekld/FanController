# FanController

<p align="justify">Es un comando básico para el control de un ventilador dependiendo de la tempreratura del procesador de la tarjeta.</p>

Visita el manual tecnico para la [Raspberry pi 2](https://github.com/stokekld/FanController/blob/RPi2/ManualTecnico.mkd)

### Variables importantes

<p align="justify">Dentro del archivo *main.c* se encuentran algunas variables que pueden establecerse para el buen funcionamiento, como son:</p>

+ **GPIO**: Es el directorio donde se configura el *gpio* de la tarjeta.
+ **TEMP**: Es el archivo donde se puede verificar la temperatura del procesador.
+ **TEMPMAX**: Es la temperatura máxima donde empezaría a funcionar el ventilador.
+ **TEMPMIN**: Es la temperatura mínima donde se apagaría el ventilador.

### Inicio del comando desde el encendido de la tarjeta

Para que el comando inicie desde el encendido de la tarjeta es necesario hacer lo siguiente:

+ La ruta donde se encuentra el comando por defecto es */home/pi/Documents/fanController/fanController*, si no es el caso modifica el archivo fanBash2.sh
+ Copiar el fanBash2.sh en el directorio */etc/init.d/*.
+ Ejecutar el comando *update-rc.d* de la siguiente manera.

	```
	# update-rc.d fanBash2 defaults
	```
