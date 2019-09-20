#include <Keyboard.h>

#define DOT_PIN   9
#define DASH_PIN  A0

#define HIT 0
#define RELEASE 1

int dot, dash;

void setup() {
  Keyboard.begin();
  
  pinMode(DOT_PIN, INPUT_PULLUP);
  pinMode(DASH_PIN, INPUT_PULLUP);

  dot = 0;
  dash = 0;
}

void loop() {
  dot = digitalRead(DOT_PIN);
  dash = digitalRead(DASH_PIN);

  Serial.print(dot);
  Serial.print(", ");
  Serial.println(dash);
  if(dot==HIT) {
    Keyboard.press('z');
  } else {
    Keyboard.release('z');
  }

  if(dash==HIT) {
    Keyboard.press('x');
  } else {
    Keyboard.release('x');
  }

  delay(10);
}
