
/*********TACHLOG powered********
*********www.troncart.com*******
**electronics components online**
***********Temperature Controlled Heater**************
***********13-07-2019**************
*/
#include <SoftwareSerial.h>
#include <LiquidCrystal.h>         

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //Digital pins to which you connect the LCD
const int inPin = A5;                   // A0 is where you connect the sensor

  void setup()
  {
    Serial.begin(9600);
    pinMode(10,OUTPUT);//pin to relay
    pinMode(9,OUTPUT);//pin to green led
    pinMode(8,OUTPUT);//pin to red led
    lcd.begin(16,2);
  }
  
    void loop()
    {
      int value = analogRead(inPin); // read the value from the sensor
      lcd.setCursor(0,1);
      float millivolts = (value / 1025.0) * 5000; 
      float celsius = millivolts/10;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(celsius);
      Serial.print(celsius);
      Serial.print("c");
      lcd.print("C");
      lcd.setCursor(0,1);
      lcd.print((celsius * 9)/5 + 32); //turning the celsius into fahrehait
      lcd.print("F");
      Serial.print((celsius * 9)/5 + 32);
      Serial.print("f");
      delay(300);
      if(celsius>37)
        {
          digitalWrite(10,HIGH);
          digitalWrite(8,LOW);
          digitalWrite(9,HIGH);
          Serial.println("Circuit Break due to overheat");   
        }
      else if(celsius<37)
        {
  
          digitalWrite(10,LOW);
          digitalWrite(9,LOW);
          digitalWrite(8,HIGH);    
          Serial.println("Circuit checked");
        }
    }
