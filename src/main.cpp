#include <Arduino.h>

// IR
#define RAW_BUFFER_LENGTH 750 // For air condition IR remotes it may require up to 750. Default is 200.
#define IR_RECEIVER_PIN 5     // Pin for IR receiver
#define IR_SEND_PIN 3         // Pin for IR emitter
#include <IRremote.hpp>

// RF
#define RF_RECEIVER_INTERRUPT 0 // Interrupt for RF receiver (pin D2 on Arduino Nano)
#define RF_SEND_PIN 7           // Pin for RF sender
#include <RCSwitch.h>

// Decoder
#include "decoder.hpp"

// Scenes
#include "devices/airedespacho.hpp"
#include "devices/teclado.hpp"
#include "devices/tv.hpp"
#include "scenes/musica.hpp"
#include "scenes/gaming.hpp"

RCSwitch mySwitch = RCSwitch();

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

    // IR
    IrReceiver.begin(IR_RECEIVER_PIN, ENABLE_LED_FEEDBACK, USE_DEFAULT_FEEDBACK_LED_PIN);
    IrSender.begin();

    // RF
    mySwitch.enableReceive(RF_RECEIVER_INTERRUPT);
    mySwitch.enableTransmit(RF_SEND_PIN);
}

void loop()
{
    // decodeIR();
    // decodeIRDump();
    // decodeRF(mySwitch);

    controlaBoton();
}
