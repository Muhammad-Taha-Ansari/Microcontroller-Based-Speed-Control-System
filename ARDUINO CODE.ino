#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// LCD address 0x27 or 0x3F (change if needed)
LiquidCrystal_I2C lcd(0x27, 16, 2);

volatile int pulseCount = 0; 
unsigned long lastTime = 0;
float rpm = 0;

const int sensorPin = 2;          // SENSOR CONNECTED TO D2 (INT0)
const int pulsesPerRevolution = 1;
const unsigned long interval = 10000; // 10 seconds

void setup() {
  pinMode(sensorPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(sensorPin), countPulse, FALLING);

  Serial.begin(9600);

  // LCD Setup
  lcd.init();
  lcd.backlight();

// Startup message
lcd.clear();
lcd.setCursor(0, 0);
lcd.print("COMPLEX ENG");   // First line
lcd.setCursor(0, 1);
lcd.print("PROBLEM");       // First line continued / second word
delay(2000);                // Show first message

lcd.clear();
lcd.setCursor(0, 0);
lcd.print("INSTRUCTOR:");
lcd.setCursor(0, 1);
lcd.print("SIR Javed");
delay(2000);                // Show instructor
  

  lastTime = millis();
}

void loop() {
  unsigned long currentTime = millis();

  if (currentTime - lastTime >= interval) {
    noInterrupts();          
    int count = pulseCount;
    pulseCount = 0;
    interrupts();            

    rpm = (count * 60.0) / pulsesPerRevolution / (interval / 1000.0);

    Serial.print("RPM: ");
    Serial.println(rpm, 2);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Motor RPM:");
    lcd.setCursor(0, 1);
    lcd.print(rpm, 2);

    lastTime = currentTime;
  }
}

void countPulse() {
  pulseCount++;
}
