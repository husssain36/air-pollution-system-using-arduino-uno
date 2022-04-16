
//NodeMCU code
#define BLYNK_PRINT Serial
//Include Lib for Arduino to Nodemcu
#include <SoftwareSerial.h>
#include <ArduinoJson.h>
#include <BlynkSimpleEsp8266.h>
//#include <SimpleTimer.h>

//D6 = Rx & D5 = Tx
SoftwareSerial nodemcu(D6, D5);
//SimpleTimer timer;
char auth[] = "8kcBuQMz4CYTkeAQWrRL5VNZpdhGAHdO";            // You should get Auth Token in the Blynk App.
                                           // Go to the Project Settings (nut icon).

char ssid[] = "realme5pro";    // Your WiFi credentials.
char pass[] = "jonsnowgot";  // Set password to "" for open networks.


void setup() {
  // Initialize Serial port
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass,"blynk.iot-cm.com", 8080);
  nodemcu.begin(9600);
  while (!Serial) continue; 
  
  
}

void loop() {
  sendUptime();

  Blynk.run();
//  timer.run();
}

void sendUptime(){

    
  StaticJsonBuffer<1000> jsonBuffer;
  JsonObject& data = jsonBuffer.parseObject(nodemcu);

  if (data == JsonObject::invalid()) {
    //Serial.println("Invalid Json Object");
    jsonBuffer.clear();
    return;
  }
  
  Serial.println("JSON Object Recieved");
  Serial.print("Recieved C02 PPM:  ");
  float co2 = data["CO2"];
  Serial.println(co2);
  Serial.print("Recieved CH4 PPM:  ");
  float ch4 = data["CH4"];
  Serial.println(ch4);
  Serial.print("Recieved NH3 PPM:  ");
  float nh3 = data["NH3"];
  Serial.println(nh3);
  Serial.print("Recieved Sound:  ");
  float sound = data["SOUND"];
  Serial.println(sound);
  Serial.println("-----------------------------------------");
  Blynk.virtualWrite(V0, co2);
  Blynk.virtualWrite(V1, ch4);
  Blynk.virtualWrite(V2, nh3);
  Blynk.virtualWrite(V3, sound);
}
