/*
 Version 0.4 - April 26 2019
*/ 

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <WebSocketsClient.h> //  https://github.com/kakopappa/sinric/wiki/How-to-add-dependency-libraries
#include <ArduinoJson.h> // https://github.com/kakopappa/sinric/wiki/How-to-add-dependency-libraries (use the correct version)
#include <StreamString.h>

int device_1 = 5;
int device_2 = 4;
int device_3 = 0;
int device_4 = 2;
int device_5 = 14;
int device_6 = 12;
int device_7 = 13;
int device_8 = 15;

ESP8266WiFiMulti WiFiMulti;
WebSocketsClient webSocket;
WiFiClient client;

#define MyApiKey "YOUR_API_KEY" // TODO: Change to your sinric API Key. Your API Key is displayed on sinric.com dashboard
#define MySSID "YOUR_WIFI_SSID" // TODO: Change to your Wifi network SSID
#define MyWifiPassword "YOUR_WIFI_PASSWORD" // TODO: Change to your Wifi network password

#define HEARTBEAT_INTERVAL 300000 // 5 Minutes 

uint64_t heartbeatTimestamp = 0;
bool isConnected = false;


// deviceId is the ID assgined to your smart-home-device in sinric.com dashboard. Copy it from dashboard and paste it here

void turnOn(String deviceId) {
  if (deviceId == "5d9358b0de917d27fed3d2a1") // Device ID of first device
  {  
    Serial.print("Turn on device id: ");
    Serial.println(deviceId);
    digitalWrite(device_1, LOW);
  } 
  else if (deviceId == "5d9358e4de917d27fed3d2ae") // Device ID of second device
  { 
    Serial.print("Turn on device id: ");
    Serial.println(deviceId);
    digitalWrite(device_2, LOW);
  }
  else if (deviceId == "5d9358ebde917d27fed3d2b4") // Device ID of Third device
  { 
    Serial.print("Turn on device id: ");
    Serial.println(deviceId);
    digitalWrite(device_3, LOW);
  }
  else if (deviceId == "5d9358f6de917d27fed3d2b9") // Device ID of Fourth device
  { 
    Serial.print("Turn on device id: ");
    Serial.println(deviceId);
    digitalWrite(device_4, LOW);
  }
  else if (deviceId == "5d935900de917d27fed3d2be") // Device ID of Fifth device
  { 
    Serial.print("Turn on device id: ");
    Serial.println(deviceId);
    digitalWrite(device_5, LOW);
  }
  else if (deviceId == "5d935907de917d27fed3d2c0") // Device ID of Sixth device
  { 
    Serial.print("Turn on device id: ");
    Serial.println(deviceId);
    digitalWrite(device_6, LOW);
  }
  else if (deviceId == "5d93590fde917d27fed3d2c5") // Device ID of Seventh device
  { 
    Serial.print("Turn on device id: ");
    Serial.println(deviceId);
    digitalWrite(device_7, LOW);
  }
  else if (deviceId == "5d935916de917d27fed3d2ca") // Device ID of Eighth device
  { 
    Serial.print("Turn on device id: ");
    Serial.println(deviceId);
    digitalWrite(device_8, LOW);
  }
  else {
    Serial.print("Turn on for unknown device id: ");
    Serial.println(deviceId);    
  }     
}

