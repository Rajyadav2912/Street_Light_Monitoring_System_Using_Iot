#define BLYNK_TEMPLATE_ID "TMPL0j2kriWt"
#define BLYNK_TEMPLATE_NAME "STREET LIGHT MONITORING SYSTEM USING IOT"
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


// WiFi credentials
char auth[] = "5jQsNQLRkr8OMrWsM_QA94GSjvJ9JqaZ";
char ssid[] = "OPPO A5 2020";
char pass[] = "rajyadav29";

int IR_Sensor1 = D0;
int LED_1 = D5;

int IR_Sensor2 = D1;
int LED_2 = D6;

int IR_Sensor3 = D2;
int LED_3 = D7;

int IR_Sensor4 = D3;
int LED_4 = D8;

int ldr = A0;
int val = 0;

BlynkTimer timer;

void setup() {
  Serial.begin(9600);

  Blynk.begin (auth, ssid, pass);
  pinMode(IR_Sensor1, INPUT);
  pinMode(LED_1, OUTPUT);

  pinMode(IR_Sensor2, INPUT);
  pinMode(LED_2, OUTPUT);
  
  pinMode(IR_Sensor3, INPUT);
  pinMode(LED_3, OUTPUT);

  pinMode(IR_Sensor4, INPUT);
  pinMode(LED_4, OUTPUT);

  pinMode(A0, INPUT);

  //timer.setInterval (1000L, lightStatus);
}

void loop() {
  int S1 = digitalRead(IR_Sensor1);
  int S2 = digitalRead(IR_Sensor2);
  int S3 = digitalRead(IR_Sensor3);
  int S4 = digitalRead(IR_Sensor4);

  val = analogRead(A0);
  Blynk.virtualWrite(V4, val);
  
  //  Blynk.virtualWrite(V0, IR_Sensor1);
  //  Blynk.virtualWrite(V1, IR_Sensor2);

  //  Serial.print(S1);
  //  Serial.print(":");
  //  Serial.print(S2);
  //  Serial.print(":");

  Serial.println(val);
  Serial.println(S1);
  Serial.println(S2);
  Serial.println(S3);
  Serial.println(S4);
  if (val < 100)
  {
    if (S1 == 1)
    {
      digitalWrite(LED_1, LOW);
      Blynk.virtualWrite(V0, 0);
      Blynk.virtualWrite(V5, "OFF");
    }
    else
    {
      digitalWrite(LED_1, 1);
      Blynk.virtualWrite(V0, 1);
      Blynk.virtualWrite(V5, "ON");
    }
    if (S2 == 1)
    {
      digitalWrite(LED_2, LOW);
      Blynk.virtualWrite(V1, 0);
      Blynk.virtualWrite(V6, "OFF");
    }
    else
    {
      digitalWrite(LED_2, 1);
      Blynk.virtualWrite(V1, 1);
      Blynk.virtualWrite(V6, "ON");
    }
     if (S3 == 1)
    {
      digitalWrite(LED_3, LOW);
      Blynk.virtualWrite(V2, 0);
      Blynk.virtualWrite(V7, "OFF");
    }
    else
    {
      digitalWrite(LED_3, 1);
      Blynk.virtualWrite(V2, 1);
      Blynk.virtualWrite(V7, "ON");
    }
    if (S4 == 1)
    {
      digitalWrite(LED_4, LOW);
      Blynk.virtualWrite(V3, 0);
      Blynk.virtualWrite(V8, "OFF");
    }
    else
    {
      digitalWrite(LED_4, 1);
      Blynk.virtualWrite(V3, 1);
      Blynk.virtualWrite(V8, "ON");
    }
 }
 else
  {
    digitalWrite(LED_1, LOW);
    digitalWrite(LED_2, LOW);
    digitalWrite(LED_3, LOW);
    digitalWrite(LED_4, LOW);
  }
  delay(100);
  Blynk.run();
}
