#include <Arduino.h>

int LedPins[] = {2, 3, 4, 5, 6, 7};

int size = sizeof(LedPins) / sizeof(LedPins[0]);

unsigned long last_time;

int cur_led = 0;

void setup()
{
  for (int i = 0; i < size; i++)
  {
    pinMode(LedPins[i], OUTPUT);
  }

  digitalWrite(LedPins[cur_led], HIGH);
}

void loop()
{
  if (millis() - last_time > 500)
  {
    last_time = millis();

    digitalWrite(LedPins[cur_led], LOW);

    cur_led++;

    if (cur_led >= size)
    {
      cur_led = 0;
    }

    digitalWrite(LedPins[cur_led], HIGH);
  }
}
