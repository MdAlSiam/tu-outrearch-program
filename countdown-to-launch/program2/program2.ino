// Speaker program

#define BUZZER_PIN 9

// Tone selection 1: These will be the “success” tones.
int tones_1[] = {1047, 880, 784, 1047}; //C6, A5, G5, C6
const int tones_1_duration = 120;
int length_tones_1 = 4;

// Tone selection 2: These will be the “cancel launch” tones.
int tones_2[] = {880, 659, 523, 494, 440};
const int tones_2_duration = 80;
int length_tones_2 = 5;

// Tone selection 3: These are the initial rocket tones.
int rocket_tone_1 = 201; // Frequency in hertz (cycles per second).
int rocket_tone_2 = 149;

int tone_selection = 1;  // We’ll start with the success tones.

void setup() {
    pinMode(BUZZER_PIN, OUTPUT); // Set up the buzzer pin as output.
}

void loop() {
    if (tone_selection == 1) {   // Success!
        for (int thisNote = 0; thisNote < length_tones_1; thisNote++) {
            tone(BUZZER_PIN, tones_1[thisNote], tones_1_duration); // Play tones_1.
            delay(tones_1_duration); // Wait for the tone to finish.
            delay(20); // Silent break between notes.
        }
    } else if (tone_selection == 2) {    // Cancel launch!
        for (int thisNote = 0; thisNote < length_tones_2; thisNote++) {
            tone(BUZZER_PIN, tones_2[thisNote], tones_2_duration); // Play tones_2.
            delay(tones_2_duration); // Wait for the tone to finish.
        }
    } else {     // tone_selection == 3     Rocket tones!
        unsigned long start_time = millis(); // Retrieve the timer value.
        unsigned long end_time = start_time + 4000; // End after four seconds.
        while (millis() < end_time) {
            tone(BUZZER_PIN, rocket_tone_1, 10); // Play rocket_tone_1 for 10 ms.
            delay(10);  // Silent break between notes.
            tone(BUZZER_PIN, rocket_tone_2, 15); // Play rocket_tone_2 for 15 ms.
            delay(15);  // Silent break between notes.
            rocket_tone_1++; // Increment the tone frequency by 1 hertz.
            rocket_tone_2++;
        }
        rocket_tone_1 = 201;  // Reset the two rocket tone values.
        rocket_tone_2 = 149;
        tone_selection = 0;  // Reset the selection (start over).
    }
    tone_selection++;  // Increment the tone selection.
    delay(1000); // Delay 1 second.
}
