# FanController

Es un comando básico para el control de un ventilador dependiendo de la tempreratura del procesador de la tarjeta.

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

### Especificaciones Técnicas

El Fan Controller requiere del uso de un GPIO de la tarjeta. Dadas las limitaciones de corriente que pueden proveer los GPIOS, de aproximadamente 12 mA a 3.3 v, es necesario alimentar el ventilador con los pines de +5v y GND, ya que el ventilador consume una corriente de 120 mA. Para esto se usa un transistor N2222 y una resistencia de 6.2K ohms conectada entre la base del transistor y el GPIO para limitar la corriente. Al alimentar el GPIO el transistor se va a saturación dejando pasar corriente entre emisor y colector, alimentando así al ventilador con 5v. El esquemático se anexa en el proyecto. Las adecuaciones de la caja se quedan a consideración del usuario ya que dependen de la forma de la caja.

#### Materiales

- Ventilador de 25mm x 25mm a 5v 120 mA
- Transistor NPN N2222
- Resistencia de 6.2K ohms
- cable
