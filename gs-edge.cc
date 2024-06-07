#include <LiquidCrystal.h>

const int PIN_RATE_BTN_0 = 8,
          PIN_RATE_BTN_1 = 9,
          PIN_RATE_BTN_2 = 10,
          PIN_RATE_BTN_3 = 11,
          PIN_RESET_BTN = 12;

LiquidCrystal lcd(3, 4, A2, A3, A4, A5);

void screenClear() {
  lcd.clear();
  lcd.setCursor(0, 0);
}

void screenPrintRate(int stars) {
  for (int i = 0; i < stars; i++) {
    lcd.print("*");
    delay(200);
  }
  
  delay(200);
}

  
void setup() {
  Serial.begin(9600);
  
  lcd.begin(16, 2);
  screenClear();
  
  pinMode(PIN_RATE_BTN_0, INPUT);
  pinMode(PIN_RATE_BTN_1, INPUT);
  pinMode(PIN_RATE_BTN_2, INPUT);
  pinMode(PIN_RATE_BTN_3, INPUT);
  pinMode(PIN_RESET_BTN, INPUT);
}

void loop() {
  int ratePin0 = digitalRead(PIN_RATE_BTN_0);
  int ratePin1 = digitalRead(PIN_RATE_BTN_1);
  int ratePin2 = digitalRead(PIN_RATE_BTN_2);
  int ratePin3 = digitalRead(PIN_RATE_BTN_3);
  int resetPin = digitalRead(PIN_RESET_BTN);

  if (resetPin == HIGH) {
    screenClear();
  }
  
  if (ratePin0 == HIGH) {
    screenClear();
    screenPrintRate(4);
  } else if (ratePin1 == HIGH) {
    screenClear();
    screenPrintRate(8);
  } else if (ratePin2 == HIGH) {
    screenClear();
    screenPrintRate(12);
  } else if (ratePin3 == HIGH) {
    screenClear();
    screenPrintRate(16);
  }
}
