
//Arduino code

//MQ135 Lib
#include "MQ135.h"

//Arduino to NodeMCU Lib
#include <SoftwareSerial.h>
#include <ArduinoJson.h>

//Initialise Arduino to NodeMCU (5=Rx & 6=Tx)
SoftwareSerial nodemcu(5, 6);
//SoftwareSerial espSerial(5, 6);

#define ANALOGPIN A0    //  Define Analog PIN on Arduino Board
#define RZERO 206.85    //  Define RZERO Calibration 
MQ135 gasSensor = MQ135(ANALOGPIN);
float ppm;
float co2;
float ch4;
float nh3;
float sound;
String str;

void setup() {
  Serial.begin(9600);
  nodemcu.begin(9600);
  float rzero = gasSensor.getRZero();
  
  delay(1000);

  Serial.println("Program started");
  Serial.print("MQ135 RZERO Calibration Value : ");
  Serial.println(rzero);
}

void loop() {

  StaticJsonBuffer<1000> jsonBuffer;
  JsonObject& data = jsonBuffer.createObject();

  //Obtain Temp and Hum data
  sensorData();


  //Assign collected data to JSON Object
  data["CO2"] = co2;
  data["CH4"] = ch4; 
  data["NH3"] = nh3;
  data["SOUND"] = sound; 

  //Send data to NodeMCU
  data.printTo(nodemcu);
  jsonBuffer.clear();

  delay(2000);
}

void sensorData() {
  //Obtain Temp and Hum data
  ppm = gasSensor.getPPM();
  sound = analogRead(1);
  co2 = ppm;
  ch4 = ppm/84;
  nh3 = ppm/298;
  
  Serial.print("CO2 ppm value : ");
  Serial.println(ppm);
  Serial.print("Ch4 ppm value : ");
  Serial.println(ch4);
  Serial.print("nh3 ppm value : ");
  Serial.println(nh3);
  Serial.print("Sound value : ");
  Serial.println(sound);



}
