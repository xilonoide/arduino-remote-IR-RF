#include <IRremote.hpp>

void tecladoGaming()
{
    for (int i = 0; i < 10; i++)
    {
        IrSender.sendNEC(0x80, 0x4, 3);
        delay(100);
    }
}

void tecladoPortatil()
{
    for (int i = 0; i < 10; i++)
    {
        IrSender.sendNEC(0x80, 0x3, 3);
        delay(100);
    }
}
