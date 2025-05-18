#include "Arduino.h"

int toggle(int);

// LEDs are connected to GPIO 2 .. 6
const int max_pin = 6;
const int min_pin = 2;

long randNumber;
int curr_pin = min_pin;
int state[max_pin];

int total = 600;

void setup()
{
	Serial.begin(9600);
	pinMode(LED_BUILTIN, OUTPUT);
	for(int i = min_pin; i <= max_pin; i++)
	{
		pinMode(i, OUTPUT);
		state[i] = LOW;
	}

	// if analog input pin 0 is unconnected, random analog
	// noise will cause the call to randomSeed() to generate
	// different seed numbers each time the sketch runs.
	// randomSeed() will then shuffle the random function.
	randomSeed(analogRead(0));
}

// the loop function runs over and over again forever
void loop()
{
	digitalWrite(LED_BUILTIN, state[min_pin]);

	curr_pin = random(min_pin, (max_pin + 1));
	Serial.println(curr_pin);
	state[curr_pin] = toggle(state[curr_pin]);
	digitalWrite(curr_pin, state[curr_pin]);
	delay(random(0, 600 / (max_pin - min_pin + 1)));
}

int toggle(int st)
{
	if(st == LOW)
	{
		return (HIGH);
	}
	return (LOW);
}
