#include <Arduino.h>

#include "button.cpp"

// Scenes
#include "scenes/musica.hpp"
#include "scenes/gaming.hpp"

const int numButtons = 10;
const int pinsButtons[numButtons] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
Button *buttons[numButtons];

void setupButtons()
{
    buttons[0] = new Button(pinsButtons[0], MusicaAire26, MusicaAire26Off);
    buttons[1] = new Button(pinsButtons[1], GamingAire26, GamingAire26Off);

    for (int i = 2; i < numButtons; i++)
    {
        buttons[i] = new Button(pinsButtons[i], nullptr, nullptr);
    }
}

void buttonController()
{
    for (int i = 0; i < numButtons; i++)
    {
        buttons[i]->update();
    }
}