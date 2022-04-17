# air-pollution-system-using-arduino-uno

This project has been developed as sem 6 sensor lab project.

The sensors used are MQ135 Gas sensor, LM393 Sound Sensor along with Arduino Uno as a Microcontroller. Now to feed the data to the internet we have used NodeMCU Board.
Note: We first went on with ESP8266 wifi module but connecting it is a very difficult task and also it doesn't work well so please go for a NodeMCU Board.

Now coming towards the connection part, I will upload the circuit diagram to help out new learners or other people who want to make similar things.

![project assets-01](https://user-images.githubusercontent.com/82446510/163727755-fd5e6cf8-646a-49cf-9201-8a3ed3d4b831.jpg)


The libraries used externally are (all the external libraries will be added in the code section):
1) MQ135 Master to get ppm values fro ch4, co3 and nh3.
2) Esp8266 Library along with board controller has been used.
3) A special library called ArduinoJson.h has been used to convert the ppm values into a json file so that it can be passed easily to the NodeMCU.
4) Blynk App has been used to display the pollution value in realtime.

Problems one might face: 
1) Not able to connect to wifi using esp8266 - solution: switch to NodeMCU.
2) Blynk App not working: Once you go to the login page you will see a small signal like icon click on it and enter port as 9443 and host address as: 49.229.108.138
