#include <IRremote.hpp>

void tv()
{
    IrSender.sendNEC(0x4, 0x8, 3); // on / off TV
}
