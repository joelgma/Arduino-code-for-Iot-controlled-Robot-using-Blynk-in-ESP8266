#define BLYNK_TEMPLATE_ID "TMPL3228DG3JX"
#define BLYNK_TEMPLATE_NAME "New Robot"
#define BLYNK_AUTH_TOKEN "Ht48C1Fm4YG8MtFNEibGAQK9lNNZfhKm"
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] = "RedmiNote9ProMax";
char pass[] = "Joelg12345@J";
char auth[] = "Ht48C1Fm4YG8MtFNEibGAQK9lNNZfhKm";

int Hand1F = 0;
int Hand1R = 1;
int Hand2F = 2;
int Hand2R = 3;
int Grip1F = 4; 
int Grip1R = 5;
int Grip2F = 6;
int Grip2R = 7;
void setup() {
  Serial.begin(9600);

  // Connect to Wi-Fi
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");

  // Connect to Blynk
  Blynk.begin(auth, ssid, pass);

  pinMode(Hand1F, OUTPUT);
  pinMode(Hand1R, OUTPUT);

  pinMode(Hand2F, OUTPUT);
  pinMode(Hand2R, OUTPUT);

  pinMode(Grip1F, OUTPUT);
  pinMode(Grip1R, OUTPUT);

  pinMode(Grip2F, OUTPUT);
  pinMode(Grip2R, OUTPUT);
 
}

void loop() {
  // Run Blynk background tasks
  Blynk.run();
}

BLYNK_WRITE(V1) {
 int pinValue1 = param.asInt();
  // set motor direction based on value from Blynk app
  if (pinValue1 == 0) {
    digitalWrite(Hand1F, HIGH);
    digitalWrite(Hand1R, LOW);
  }
  else if (pinValue1 == 255) {
    digitalWrite(Hand1F, LOW);
    digitalWrite(Hand1R, HIGH);
  }

  else  {
    digitalWrite(Hand1F, LOW);
    digitalWrite(Hand1R, LOW);
  }


}




BLYNK_WRITE(V2) {
 int pinValue1 = param.asInt();
  // set motor direction based on value from Blynk app
  if (pinValue1 == 0) {
    digitalWrite(Hand2F, HIGH);
    digitalWrite(Hand2R, LOW);
  }
  else if (pinValue1 == 255) {
    digitalWrite(Hand2F, LOW);
    digitalWrite(Hand2R, HIGH);
  }

  else {
    digitalWrite(Hand2F, LOW);
    digitalWrite(Hand2R, LOW);
  }


}





BLYNK_WRITE(V3) {
 int pinValue1 = param.asInt();
  // set motor direction based on value from Blynk app
  if (pinValue1 == 0) {
    digitalWrite(Grip1F, HIGH);
    digitalWrite(Grip1R, LOW);
  }
  else if (pinValue1 == 255) {
    digitalWrite(Grip1F, LOW);
    digitalWrite(Grip1R, HIGH);
  }

  else{
    digitalWrite(Grip1F, LOW);
    digitalWrite(Grip1R, LOW);
  }


}




BLYNK_WRITE(V4) {
 int pinValue1 = param.asInt();
  // set motor direction based on value from Blynk app
  if (pinValue1 == 0) {
    digitalWrite(Grip2F, HIGH);
    digitalWrite(Grip2R, LOW);
  }
  else if (pinValue1 == 255) {
    digitalWrite(Grip2F, LOW);
    digitalWrite(Grip2R, HIGH); 
  }

  else{
    digitalWrite(Grip2F, LOW);
    digitalWrite(Grip2R, LOW);
  }


}
