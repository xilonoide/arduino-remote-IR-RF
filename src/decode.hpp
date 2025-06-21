#include <IRremote.hpp>

void decode()
{
    if (IrReceiver.decode())
    {
        Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX); // Print "old" raw data
        IrReceiver.printIRResultShort(&Serial);                       // Print complete received data in one line
        IrReceiver.printIRSendUsage(&Serial);                         // Print the statement required to send this data

        IrReceiver.resume(); // Enable receiving of the next value
    }
}
