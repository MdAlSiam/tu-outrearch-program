// This sketch blinks an LED connected to pin 8 on and off.
bool LED_switch = true; // This variable is our virtual light switch.

void setup() {
    pinMode(8, OUTPUT); // Make pin 8 an output.
}

void loop() {
    digitalWrite(8, LED_switch); // Turn the LED on or off.
    delay(500); // Delay for half a second.
    LED_switch = !LED_switch; // Flip the value between true and false.
}
