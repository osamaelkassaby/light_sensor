#include <SoftwareSerial.h>
SoftwareSerial ArduinoUno(3,2);


int light;
int val ;
int r4 = 8;
int r3= 9;
int r2 = 10;
int r1 = 11;
 
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(13 , OUTPUT);
ArduinoUno.begin(4800);

pinMode(r4 , OUTPUT);
pinMode(r3 , OUTPUT);
pinMode(r2 , OUTPUT);
pinMode(r1 , OUTPUT);
digitalWrite(r1, HIGH); // sets the digital pin 13 on
digitalWrite(r2, HIGH); // sets the digital pin 13 on
digitalWrite(r3, HIGH); // sets the digital pin 13 on
digitalWrite(r4, HIGH); // sets the digital pin 13 on
}

void loop() {

  light = analogRead(A0);
  if(light > 150){
      delay(1000);
      Serial.print(0);
      digitalWrite(r1, HIGH);
            
    }else{
        delay(1000);
        Serial.print(1);
        digitalWrite(r1, LOW); 

      }
      while(ArduinoUno.available()>0){
      val= ArduinoUno.read();
      Serial.println(val);
      if(val == 1){
      digitalWrite(r1, LOW); 

      }else if(val == 2){
         digitalWrite(r2, LOW); 

        }else if(val == 3 ){
                digitalWrite(r3, LOW);

          }else if(val == 4){
                  digitalWrite(r4, LOW); 

            }else if(val == 11){
                                digitalWrite(r1, HIGH);

              }else if(val == 22){
                                digitalWrite(r2, HIGH); 

              }else if(val == 33){
                                digitalWrite(r3, HIGH); 
              }else if(val == 44){
                                digitalWrite(r4, HIGH); 

              }
            
          
        
  
}
delay(1000);
}
