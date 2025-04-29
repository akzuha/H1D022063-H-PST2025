#include <Arduino.h>
#include <Wire.h>

int SDA_PIN = D2; // SDA pin
int SCL_PIN = D3; // SCL pin

void setup() {
  Wire.begin(SDA_PIN, SCL_PIN); // Initialize I2C with custom pins
  Serial.begin(9600); // Start serial communication for debugging
}

void loop() {
  byte error, address;
  int nDevices = 0;
  Serial.println("Memindai...");

  for (address = 0; address<127; address++){
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
    if (error == 0) {
      Serial.print("Perangkat I2C ditemukan di alamat 0x");
      if (address<16) {
        Serial.print("0");
      }
      Serial.print(address, HEX);
      Serial.println("  !");
      nDevices++;
    } else if (error==4) {
      Serial.print("Error tidak diketahui pada alamat 0x");
      if (address<16) {
        Serial.print("0");
      }
      Serial.println(address, HEX);
    }
  }

  if (nDevices == 0) {
    Serial.println("Tidak ada perangkat I2C ditemukan\n");
  } else {
    Serial.println("Selesai\n");
  }
  delay(5000); 
}