#include <Arduino.h>

// RF
#define RF_RECEIVER_INTERRUPT 0 // Interrupt for RF receiver (pin D2 on Arduino Nano)
#define RF_SEND_PIN 3           // Pin for RF sender
#include <RCSwitch.h>

// IR
#define RAW_BUFFER_LENGTH 750 // For air condition IR remotes it may require up to 750. Default is 200.
#define IR_RECEIVER_PIN 4     // Pin for IR receiver
#define IR_SEND_PIN 5         // Pin for IR emitter
#include <IRremote.hpp>

// Tools
#include "decoder.hpp"
#include "buttonController.hpp"

RCSwitch mySwitch = RCSwitch();

void setup()
{
    Serial.begin(9600);

    // RF
    mySwitch.enableReceive(RF_RECEIVER_INTERRUPT);
    mySwitch.enableTransmit(RF_SEND_PIN);

    // IR
    IrReceiver.begin(IR_RECEIVER_PIN, ENABLE_LED_FEEDBACK, USE_DEFAULT_FEEDBACK_LED_PIN);
    IrSender.begin();
}

void loop()
{
    // decodeRF(mySwitch);

    // decodeIR();
    // decodeIRDump();

    buttonController();
}
