// Countdown Program with Buttons

#include <LiquidCrystal_I2C.h>

const int CountButton = 2;
const int StopButton = 3;

// Initialize an LCD object.
LiquidCrystal_I2C lcd(0x27, 16, 2);
volatile bool do_countdown = false;

void setup() {
    // Turn on the LCD and the backlight.
    lcd.init();
    lcd.backlight();
    pinMode(CountButton, INPUT_PULLUP);
    pinMode(StopButton, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(CountButton), initiateCountdown, CHANGE);
    attachInterrupt(digitalPinToInterrupt(StopButton), stopCountdown, CHANGE);
}

void loop() {
    if (do_countdown) {  // If this is true, the countdown button was pressed.
        lcd.noAutoscroll(); // Turn off autoscrolling.
        for (int countdown = 10; countdown >= 1; countdown--) {
            if (do_countdown) {
                lcd.setCursor(0, 1);
                if (countdown < 10) {
                    lcd.print("00:00:0");
                } else {
                    lcd.print("00:00:");
                }
                lcd.print(countdown);
                delay(1000);
            } else {
                lcd.clear();
                lcd.print("Aborted");
                return; // Jump out of the loop.
            }
        }
        do_countdown = false; // Countdown is done.
    } else {
        lcd.clear();
    }
    delay(10);
}

void initiateCountdown() {
    do_countdown = true;
}

void stopCountdown() {
    do_countdown = false;
}
// This function is called when the CountButton is pressed.
// It sets the do_countdown variable to true, which starts the countdown in the loop.