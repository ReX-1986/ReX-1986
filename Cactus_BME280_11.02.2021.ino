#include <Wire.h>
#include "cactus_io_BME280_I2C.h"


char t;
int state = 0;
BME280_I2C bme(0x76);

void setup() {

pinMode(4,OUTPUT);  
pinMode(5,OUTPUT);   
pinMode(6,OUTPUT); 
pinMode(7,OUTPUT); 
pinMode(13,OUTPUT);   //Led

Serial.begin(9600);

if (!bme.begin()) {
Serial.println("");
while (1);
}
bme.setTempCal(-1);
}

void loop() 
{

if(Serial.available()){
  t = Serial.read();
  Serial.print(t);
}
 
if(t == 'w'){            //nach vorne
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
}
 
else if(t == 's'){      //Rückwärts
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
}
 
else if(t == 'd'){      //rechts
  digitalWrite(4,HIGH);
}
 
else if(t == 'a'){      //links
  digitalWrite(6,HIGH);
}

else if(t == 'q'){    //LED an off
  digitalWrite(13,HIGH);
}
else if(t == 'q'){
  digitalWrite(13,LOW);
}
 
else if(t == 'e'){      //STOP (all motors stop)
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
}
{

//BME280 Sensor
bme.readSensor();

//Serial.print("Temperatur: ");
Serial.print(bme.getTemperature_C());
Serial.print("|");

//Serial.print("Temperatur: F");
//Serial.print(bme.getTemperature_F());

//Serial.print("Feuchtigkeit: ");
Serial.print(bme.getHumidity());
Serial.print("|");

//Serial.print("Druck: ");
Serial.print(bme.getPressure_MB());
Serial.print("|");
//Serial.println("");

delay(1000);

}
}
