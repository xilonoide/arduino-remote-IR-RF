#pragma once
#include <IRremote.hpp>

void aire26()
{
    uint32_t tRawData[] = {0xE091C3, 0x2000A0, 0x1002000, 0x15};
    IrSender.sendPulseDistanceWidthFromArray(38, 8950, 4450, 550, 1650, 550, 550, &tRawData[0], 104, PROTOCOL_IS_LSB_FIRST, 300, 3);
}

void aire26d5()
{
    uint32_t tRawData[] = {0x80E091C3, 0x2000A0, 0x1002000, 0x95};
    IrSender.sendPulseDistanceWidthFromArray(38, 8900, 4500, 600, 1650, 600, 550, &tRawData[0], 104, PROTOCOL_IS_LSB_FIRST, 300, 3);
}

void aire27()
{
    uint32_t tRawData[] = {0xE099C3, 0x2000A0, 0x2000, 0x1C};
    IrSender.sendPulseDistanceWidthFromArray(38, 8950, 4500, 600, 1650, 600, 550, &tRawData[0], 104, PROTOCOL_IS_LSB_FIRST, 300, 3);
}

void enciendeAire()
{
    uint32_t tRawData[] = {0xE099C3, 0x2000A0, 0x5002000, 0x21};
    IrSender.sendPulseDistanceWidthFromArray(38, 8900, 4500, 600, 1650, 600, 550, &tRawData[0], 104, PROTOCOL_IS_LSB_FIRST, 300, 3);
}

void apagaAire()
{
    uint32_t tRawData[] = {0x80E091C3, 0x2000A0, 0x5000000, 0x79};
    IrSender.sendPulseDistanceWidthFromArray(38, 8900, 4500, 600, 1650, 600, 550, &tRawData[0], 104, PROTOCOL_IS_LSB_FIRST, 300, 3);
}
