#define BLYNK_TEMPLATE_ID "TMPL6eQ4rBXhP"
#define BLYNK_TEMPLATE_NAME "KONTROL LED BUZZER DAN MONITORING SUHU DHT11"
#define BLYNK_AUTH_TOKEN "oIV_vaz3vg6hGB2vMB1Ds19bOS-Wr7Pp"
#define BLYNK_PRINT Serial // inisialisasi komunikasi serial blynk
#include <ESP8266WiFi.h> // include library
#include <BlynkSimpleEsp8266.h> // include library
#include <DHT.h> //Library untuk DHT
char auth[] = BLYNK_AUTH_TOKEN ; // masukan auth token yng didapatkan
dari
char ssid[] = "iPhone"; //masukan nama hotspot/Wifi yang digunakan
char pass[] = "11223344"; //password WiFi
#define LED D7
#define buzzer D6
#define DHTPIN D2 //deklarasi pin D3 untuk output dari DHT11
#define DHTTYPE DHT11 //Tipe DHT11
DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;
//pengiriman data untuk Virtual pin di blynk iot
BLYNK_WRITE(V0)
{
int pinValue = param.asInt();
digitalWrite(LED,pinValue);
}
BLYNK_WRITE(V1)
5
{
int pinValue1 = param.asInt();
digitalWrite(buzzer,pinValue1);
}
//function untuk pengiriman sensor
void sendSensor()
{
float t = dht.readTemperature(); //pembacaan sensor
float h = dht.readHumidity();
//menampilkan temperature pada Serial monitor
Serial.print("% Temperature: ");
Serial.print(t);
Serial.println("C ");
Serial.print("% Kelembaban: ");
Serial.print(h);
Serial.println("% ");
Blynk.virtualWrite(V2, t); //mengirimkan data temperatur ke Virtual pin VO di
Blynk Cloud
Blynk.virtualWrite(V3, h); //mengirimkan data kelemaban ke Virtual pin V1 di
Blynk Cloud
}
void setup()
{
// Debug console
Serial.begin(9600);
pinMode(LED,OUTPUT);
pinMode(buzzer,OUTPUT);
Blynk.begin(auth, ssid, pass); //memulai Blynk
timer.setInterval(1000L, sendSensor); //Mengaktifkan timer untuk pengiriman
data 1000ms
}
void loop()
{
Blynk.run();
timer.run();
}