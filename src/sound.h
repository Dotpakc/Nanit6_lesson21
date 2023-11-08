#include <Arduino.h>
#include <NanitLib.h>
#include "config.h"


const int loading_sound[6] ={364, 246, 440, 412, 392, 440};


void play_sound(const int* sound, int length) {
    for (int i = 0; i < length; i++) {
        tone(BUZZER_PIN, sound[i], 100);
        delay(100);
    }
}