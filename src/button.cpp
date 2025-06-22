#define DEBOUNCE_DELAY 50

#include <Arduino.h>

class Button
{
public:
    Button(int pin, void (*onPressFunc)(), void (*onReleaseFunc)())
        : pin(pin), onPressCallback(onPressFunc), onReleaseCallback(onReleaseFunc),
          lastState(HIGH), lastDebounceTime(0)
    {
        pinMode(pin, INPUT_PULLUP);
    }

    void update()
    {
        int reading = digitalRead(pin);
        unsigned long now = millis();

        if (reading != lastState && (now - lastDebounceTime) > DEBOUNCE_DELAY)
        {
            lastDebounceTime = now;

            if (reading == LOW && lastState == HIGH && onPressCallback)
            {
                onPressCallback();
            }
            else if (reading == HIGH && lastState == LOW && onReleaseCallback)
            {
                onReleaseCallback();
            }

            lastState = reading;
        }
    }

private:
    int pin;
    int lastState;
    unsigned long lastDebounceTime;
    void (*onPressCallback)();
    void (*onReleaseCallback)();
};