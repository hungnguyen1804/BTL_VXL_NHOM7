#include <DHT.h>
#include <Wire.h> 
#include <LiquidCrystal.h>
LiquidCrystal lcd (12,11,5,4,3,2);
const int DHTPIN = 8;
const int DHTTYPE = DHT11;

DHT dht(DHTPIN, DHTTYPE);
byte degree[8]={
   0B01110,
   0B01010,
   0B01110,
   0B00000,
   0B00000,
   0B00000,
   0B00000
};
void setup() {
  Serial.begin(9600);
  dht.begin(); 
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (isnan(t)||isnan(h)){
    Serial.println("False to read from DHT11");
  }
  else{
  lcd.begin(16,2);
  lcd.print("nhiet do: ");
  lcd.print(t);
  lcd.setCursor(0,1);
  lcd.print("do am: ");
  lcd.print(h);
  lcd.setCursor(1,1);
  delay(2000);
  }
}
