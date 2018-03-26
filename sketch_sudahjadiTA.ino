#include <FirebaseArduino.h>
//#include "DHT.h"

#include  <ESP8266WiFi.h>

#define FIREBASE_HOST "monitoring-sistem-kebakaran.firebaseio.com"
#define WIFI_SSID "jay" // Change the name of your WIFI
#define WIFI_PASSWORD "mercubuana" // Change the password of your WIFI


//inialisasi pin tombol
int relay1=D4;
int relay2=D3;
int baca;
int baca1;
int api=D6;
int asap=D7;



void setup() {
   WiFi.begin (WIFI_SSID, WIFI_PASSWORD);
   while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
   //dht.begin();
  Serial.println ("");
  Serial.println ("WiFi Connected!");
  Firebase.begin(FIREBASE_HOST);
 pinMode(api,INPUT);
 pinMode(asap,INPUT);
 pinMode(relay1, OUTPUT);
 pinMode(relay2, OUTPUT);
 Serial.begin(115200);
}

void loop() {
 baca=digitalRead(asap);
 baca1=digitalRead(api);
  //float baca = dht.readHumidity();
 // float baca1 = dht.readTemperature();  // Reading temperature as Celsius (the default)
  Firebase.setFloat ("API terdekteksi ",baca);
  Firebase.setFloat ("ASAP terdeteksi  ",baca1);

  
 if (baca1==LOW || baca==LOW ){
  digitalWrite(relay1,LOW);
  digitalWrite(relay2,LOW);
  
 
 }
 
 else{
  digitalWrite(relay1,HIGH);
  
 
 }

}
 
