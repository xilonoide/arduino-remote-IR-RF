#include <IRremote.hpp>
#include <RCSwitch.h>

void decodeIR()
{
    if (IrReceiver.decode())
    {
        Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX); // Print "old" raw data
        IrReceiver.printIRResultShort(&Serial);                       // Print complete received data in one line
        IrReceiver.printIRSendUsage(&Serial);                         // Print the statement required to send this data

        IrReceiver.resume(); // Enable receiving of the next value
    }
}

void decodeRF(RCSwitch mySwitch)
{
    if (mySwitch.available())
    {
        Serial.print("Received ");
        Serial.print(mySwitch.getReceivedValue());
        Serial.print(" / ");
        Serial.print(mySwitch.getReceivedBitlength());
        Serial.print("bit ");
        Serial.print("Protocol: ");
        Serial.println(mySwitch.getReceivedProtocol());

        mySwitch.resetAvailable();
    }
}

void decodeIRDump()
{
    if (IrReceiver.decode())
    { // Grab an IR code
        // At 115200 baud, printing takes 200 ms for NEC protocol and 70 ms for NEC repeat
        Serial.println(); // blank line between entries
        Serial.println(); // 2 blank lines between entries
        IrReceiver.printIRResultShort(&Serial);
        // Check if the buffer overflowed
        if (IrReceiver.decodedIRData.protocol == UNKNOWN)
        {
            Serial.println(F("Received noise or an unknown (or not yet enabled) protocol"));
        }

        Serial.println();
        IrReceiver.printIRSendUsage(&Serial);
        Serial.println();
        Serial.println(F("Raw result in internal ticks (50 us) - with leading gap"));
        IrReceiver.printIRResultRawFormatted(&Serial, false); // Output the results in RAW format
        Serial.println(F("Raw result in microseconds - with leading gap"));
        IrReceiver.printIRResultRawFormatted(&Serial, true); // Output the results in RAW format
        Serial.println();                                    // blank line between entries
        Serial.print(F("Result as internal 8bit ticks (50 us) array - compensated with MARK_EXCESS_MICROS="));
        Serial.println(MARK_EXCESS_MICROS);
        IrReceiver.compensateAndPrintIRResultAsCArray(&Serial, false); // Output the results as uint8_t source code array of ticks
        Serial.print(F("Result as microseconds array - compensated with MARK_EXCESS_MICROS="));
        Serial.println(MARK_EXCESS_MICROS);
        IrReceiver.compensateAndPrintIRResultAsCArray(&Serial, true); // Output the results as uint16_t source code array of micros
        IrReceiver.printIRResultAsCVariables(&Serial);                // Output address and data as source code variables
        Serial.println();                                             // blank line between entries

        IrReceiver.compensateAndPrintIRResultAsPronto(&Serial);

        IrReceiver.resume();
    }
}