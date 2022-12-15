#define BLYNK_TEMPLATE_ID "TMPLquOE6HUy"
#define BLYNK_DEVICE_NAME "Gas Leakage"
#define BLYNK_AUTH_TOKEN "qcLkDjZPwmLhA-fceZTO7LK3PgDz0BKv"

#define BLYNK_PRINT Serial
#define Buzzer D3
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

 
char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "iPhone";  
char pass[] = "sabrine1999";  
int smokeA0 = A0;
int data = 0;
int sensorThres = 100;


BlynkTimer timer;

void sendSensor(){
 
 int data = analogRead(smokeA0);
 Blynk.virtualWrite(V0, data);
  Serial.print("Pin A0: ");
  Serial.println(data);


  if(data > 20){
    Blynk.email("sabrineabdeljaoued27@gmail.com", "Alert", "Gas Leakage Detected!");
    Blynk.logEvent("gas_alert","Gas Leakage Detected");
    digitalWrite(Buzzer,HIGH);
  }else{
    digitalWrite(Buzzer,LOW);
  }
}

void setup(){
  pinMode(smokeA0, INPUT);
  pinMode(Buzzer,OUTPUT);
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(2500L, sendSensor);
}

void loop(){
  Blynk.run();
  timer.run();
}
