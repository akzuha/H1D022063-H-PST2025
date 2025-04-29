#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
int SDA_PIN = D2; 
int SCL_PIN = D3; 

void setup() {  
  Wire.begin(SDA_PIN, SCL_PIN); 
  Serial.begin(9600);
  lcd.init(); 
  lcd.backlight(); 
  lcd.setCursor(0, 0); 
  lcd.print("IMSYAK= 04:20");
  lcd.setCursor(0, 1);
  lcd.print("SHUBUH= 04:34");
}

void loop() {
  lcd.scrollDisplayLeft();
  delay(200);
}