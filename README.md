# FanController

Es un comando básico para el control de un ventilador dependiendo de la tempreratura del procesador de la tarjeta.

Visita el manual tecnico para la [Hummingboard](https://github.com/stokekld/FanController/blob/Hummingboard/ManualTecnico.mkd)


### Variables importantes

Dentro del archivo *main.c* se encuentran algunas variables que pueden establecerse para el buen funcionamiento, como son:

+ **GPIO**: Es el directorio donde se configura el *gpio* de la tarjeta.
+ **TEMP**: Es el archivo donde se puede verificar la temperatura del procesador.
+ **TEMPMAX**: Es la temperatura máxima donde empezaría a funcionar el ventilador.
+ **TEMPMIN**: Es la temperatura mínima donde se apagaría el ventilador.

### Inicio del comando desde el encendido de la tarjeta

Para que el comando inicie desde el encendido de la tarjeta es necesario hacer lo siguiente:

+ Copiar el comando en el directorio */etc/init.d/*.
+ copiar el archivo fanController.service a */etc/systemd/system*.
+ Ejecutar el comando *systemctl start fanController.service* de la siguiente manera.
+

	```
	# sudo systemctl start fanController.service
	```
