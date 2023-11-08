#include <Arduino.h>
#include <NanitLib.h>
#include <EncButton.h>

#include "config.h"
#include "sound.h"





Button btn(BUTTON_PIN);



bool dirOpenDoor = false; // false - відкрити, true - закрити
bool stateMotor = false; // false - STOP, true - RUN

void setup() {
  Serial.begin(9600);
  Nanit_Base_Start();
  pinMode(BUZZER_PIN, OUTPUT);

  play_sound(loading_sound, 6);
}

void loop() {
  btn.tick();

  if (btn.press()) {
    Serial.println("Button pressed");
    tone(BUZZER_PIN, 400, 200);
  }

  if(btn.hold()) {
    Serial.println("Button hold");
    tone(BUZZER_PIN, 300);
    stateMotor = true;
  }

  if(btn.hasClicks(2)){
    Serial.println("Button double click");
    tone(BUZZER_PIN, 500, 100);
    dirOpenDoor = !dirOpenDoor;
  }


  if (btn.release()) {
    Serial.println("Button released");
    tone(BUZZER_PIN, 360, 100);
    stateMotor = false;
  }



}
