// LCD Display Program

#include <LiquidCrystal_I2C.h>

// Initialize an LCD object.
LiquidCrystal_I2C lcd(0x27, 16, 2);
int message_counter = 1;

void setup() {
    // Turn on the LCD and the backlight.
    lcd.init();
    lcd.backlight();
}

void loop() {
    if (message_counter == 1) {   // Print 1st message to the LCD.
        // Print up to 16 characters at a time. Spaces and punctuation count.
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Hello, Ground");
        lcd.setCursor(4, 1);
        lcd.print("Control!");
        message_counter++;  // Increment the message counter.
    } else {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("It's a great day");
        lcd.setCursor(0, 1);
        lcd.print("to touch the sky");
        message_counter--;  // Decrement the message counter.
    }

    delay(3000);  // Pause for a few seconds.
}
