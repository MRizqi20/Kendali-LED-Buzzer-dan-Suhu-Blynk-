#define BLYNK_TEMPLATE_ID "TMPLjZCALM59"
#define BLYNK_DEVICE_NAME "KENDALI RELAY 3"
#define BLYNK_AUTH_TOKEN "qFdE2VnnAflbg3J6uaGzq1qkNrrHRZSY"
#define BLYNK_PRINT Serial // inisialisasi komunikasi serial blynk
#include <ESP8266WiFi.h> // include library
#include <BlynkSimpleEsp8266.h> // include library
char auth[] = "qFdE2VnnAflbg3J6uaGzq1qkNrrHRZSY"; // masukan auth token yng didapatkan dari  
char ssid[] = "Hotspot"; //masukan nama hotspot/Wifi yang digunakan
char pass[] = "12345678"; //password WiFi
#define LED D7
#define buzzer D6


//pengiriman data untuk Virtual pin di blynk iot
BLYNK_WRITE(V0)
{
int pinValue = param.asInt();
digitalWrite(LED,pinValue);
}

BLYNK_WRITE(V1)
{
int pinValue1 = param.asInt();
digitalWrite(buzzer,pinValue1);
}


void setup()
{
// Debug console
Serial.begin(9600);
pinMode(LED,OUTPUT);
pinMode(buzzer,OUTPUT);
Blynk.begin(auth, ssid, pass); //memulai Blynk
}
void loop()
{
Blynk.run();
}