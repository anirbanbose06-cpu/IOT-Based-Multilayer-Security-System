const int irSensorpin = 2;
const int ldrPin = A1; 
const int buzzer= 8;
#include <LiquidCrystal_I2C.h>
#include<Wire.h>

LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {

  pinMode(buzzer,OUTPUT);
  pinMode(irSensorpin, INPUT);
  pinMode(ldrPin,  INPUT); 
  Serial.begin(9600);
  Wire.begin();
  Wire.setClock(100);
}


void loop() {
  lcd.init();                   
  lcd.backlight();
  int sensorvalue = digitalRead(irSensorpin);

  if (sensorvalue == LOW) {
   Serial.println("obstacle detected");
   lcd.setCursor(0,1);
  lcd.print("obstacle detected");
    
  } else {
  
    Serial.println("No obstacle");
     lcd.setCursor(0,1);
  lcd.print("No obstacle");
  }
int  ldrStatus = analogRead(ldrPin);  
Serial.println(ldrStatus);
  //Serial.println(ldrStatus);
   if (ldrStatus <=700) {

      Serial.println("Trespassing"); 
      lcd.setCursor(0,0);
      lcd.print("Trespassing");
      digitalWrite(buzzer,HIGH);
      tone(buzzer,1000,1000);
    }
    else {

      Serial.println("No Trespassing");  
       lcd.setCursor(0,0);
       lcd.print("No Trespassing");  
       digitalWrite(buzzer,LOW);     
    }
  delay(500);

}
