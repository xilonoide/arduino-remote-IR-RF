// conectar receptor y emisor a GND y a 5V
// receptor a pin 2 Digital y emisor a pin 3 Digital en arduino nano

#define RAW_BUFFER_LENGTH 750 // For air condition remotes it may require up to 750. Default is 200.

#include <Arduino.h>
#include "PinDefinitionsAndMore.h"
#include <IRremote.hpp>
#include "decode.hpp"
#include "devices/airedespacho.hpp"
#include "devices/teclado.hpp"
#include "devices/tv.hpp"
#include "scenes/musica.hpp"
#include "scenes/gaming.hpp"

const int botonPin = 12;
bool estadoAnterior = HIGH;
bool estadoActual;
unsigned long ultimoCambio = 0;
const unsigned long debounceDelay = 50;

void start()
{
    MusicaAire26();
}

void stop()
{
    MusicaAire26Off();
}

void controlaBoton()
{
    bool estadoActual = digitalRead(botonPin);
    unsigned long ahora = millis();

    // al pulsar el botón
    if (estadoAnterior == HIGH && estadoActual == LOW && (ahora - ultimoCambio) > debounceDelay)
    {
        ultimoCambio = ahora;
        start();
    }

    // al soltar el botón
    if (estadoAnterior == LOW && estadoActual == HIGH && (ahora - ultimoCambio) > debounceDelay)
    {
        ultimoCambio = ahora;
        stop();
    }

    estadoAnterior = estadoActual;
}

void setup()
{
    pinMode(botonPin, INPUT_PULLUP);

    Serial.begin(9600);

    IrReceiver.begin(2, ENABLE_LED_FEEDBACK, USE_DEFAULT_FEEDBACK_LED_PIN);
    IrSender.begin();
}

void loop()
{
    // decode();

    controlaBoton();
}
