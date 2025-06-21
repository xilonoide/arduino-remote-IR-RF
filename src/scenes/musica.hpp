#include "../devices/airedespacho.hpp"
#include "../devices/teclado.hpp"
#include "../devices/tv.hpp"

void MusicaAire26()
{
    enciendeAire();
    delay(1000); // Espera un segundo para que el aire se encienda
    Serial.println("Aire acondicionado encendido.");
    aire26();
    delay(1000); // Espera un segundo para que el aire se ajuste a 26 grados
    Serial.println("Aire acondicionado ajustado a 26 grados.");
    tecladoGaming();
    delay(1000); // Espera un segundo para que el teclado se envíe
    Serial.println("Teclado PC gaming conectado.");
    tv();
    delay(1000); // Espera un segundo para que la TV se encienda
    Serial.println("TV encendida.");
}

void MusicaAire26Off()
{
    apagaAire();
    delay(1000); // Espera un segundo para que el aire se apague
    Serial.println("Aire acondicionado apagado.");
    tv();
    delay(1000); // Espera un segundo para que la TV se apague
    Serial.println("TV apagada.");
}
