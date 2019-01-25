#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
byte sensorPin[] = {8, 9, 10};
byte ledPin[] = {11, 12, 13}; // number of leds = numbers of sensors
const byte sensors = 3;
int level = 0; 
int motor = A4;

void setup() 
{
  for(int i = 0; i < sensors; i++) 
  {
     pinMode(sensorPin[i], INPUT); 
     pinMode(ledPin[i], OUTPUT);
  }
  pinMode(motor, OUTPUT);
  lcd.begin(16, 2);   
}

void loop() 
{
  level = 0; 
  for(int i = 0; i < sensors; i++) 
  {
     if(digitalRead(sensorPin[i]) == LOW)
     {
        digitalWrite(ledPin[i], HIGH);
        level = sensors - i;
     } 
     else
     {
       digitalWrite(ledPin[i], LOW);       
     }    
  }
  lcd.clear();
  lcd.print("Water level");
  lcd.setCursor(0,1);  
  switch(level)
  {
     case 1:
      lcd.print("HIGH");
      digitalWrite(motor, HIGH);
      break;
     case 2:
       lcd.print("AVERAGE");
       digitalWrite(motor, LOW);
       break;
     case 3:
       lcd.print("LOW");
       digitalWrite(motor, LOW);
       break;
     default:
      lcd.print("NO WATER"); 
      digitalWrite(motor, LOW);   
      break;
  }
  delay(50);  
 }
