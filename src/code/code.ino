#include<ESP8266WiFi.h>

// Info de connexion 
#define SSID "iPhone"  // wifi_name
#define PASSWORD "sabrine1999" // wifi_password

#define Red D1
#define Green D2
#define Buzzer D3
#define Sensor A0


void setup(){
  Serial.begin(9600);
  
  // Mode de connexion
  WiFi.mode(WIFI_STA);
  
  // Démarrage de la connexion
  WiFi.begin(SSID,PASSWORD);

  pinMode(Red,OUTPUT);
  pinMode(Green,OUTPUT);
  pinMode(Buzzer,OUTPUT);
  pinMode(Sensor,INPUT);
}

void notification(){
  int sensor = analogRead(Sensor);
 // Serial.println(sensor);
  if(sensor > 500){
    digitalWrite(Green,LOW);
    digitalWrite(Red,HIGH);
    digitalWrite(Buzzer,HIGH);
    Serial.println("Alerte : il y'a une fuite");
  }else{
    digitalWrite(Red,LOW);
    digitalWrite(Green,HIGH);
    digitalWrite(Buzzer,LOW);
    Serial.println("il n y'a pas de fuite");
}
}

void loop(){
  // Tester la connexion
  if (WiFi.isConnected()){
    Serial.println("Connecté");
  }else{
    Serial.println("Déconnecté");
  }

  notification();
  
}
