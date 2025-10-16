
#define BLYNK_TEMPLATE_ID "RDPWSFNP"
#define BLYNK_TEMPLATE_NAME "IR sensor "
#define BLYNK_AUTH_TOKEN    "L-KIZpkRAPZgfdsSFHHRs"
XeKbMY_SVeT

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>



char ssid[] = "WiFi name";
char pass[] = "WiFi password";


int irPin = 23;      
int ledPin = 2;         

BlynkTimer timer;

void sendIRStatus() {
  int alarm=0;
  int sensorValue = digitalRead(irPin);  
{  
    alarm = 0;
  } else {
    alarm = 1;
  }

  Blynk.virtualWrite(V1, alarm);

  
  if (sensorValue == HIGH) {  
    digitalWrite(ledPin, HIGH);  
    Serial.println(">>> Object Detected - LED ON <<<");
  } else {
    digitalWrite(ledPin, LOW);   
    Serial.println(">>> No Object - LED OFF <<<");
  }
}

void setup() {
 
  Serial.begin(115200);
  delay(500);
  Serial.println(">>> Setup started <<<");

 
  pinMode(irPin, INPUT);
  pinMode(ledPin, OUTPUT);

 
  Serial.print("Connecting to WiFi: ");
  Serial.println(ssid);
  WiFi.begin(ssid, pass);

  unsigned long startAttempt = millis();
  while (WiFi.status() != WL_CONNECTED && millis() - startAttempt < 10000) {
    delay(500);
    Serial.print(".");
  }
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nWiFi connected");
    Serial.print("IP: ");
    Serial.println(WiFi.localIP());
  } else (){

  
  Serial.println("Connecting to Blynk...");
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);


  timer.setInterval(2000L, sendIRStatus);
}

{
  Blynk.run();
  timer.run();
}