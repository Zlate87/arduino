#if defined(ARDUINO) && ARDUINO > 18
#include <SPI.h>
#endif
#include <Ethernet.h>
#include <Twitter.h>
 
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
 
Twitter twitter("457519377-Bm1w1tccofzcORr0E3ao2LewqZ1gsFemtm42xyMA");
float temperature = -100;
 
void setup()
{
  Ethernet.begin(mac);
  Serial.begin(9600);
  pinMode(9, OUTPUT);
}
 
void loop()
{
  delay(1000);
  Serial.println("connecting ...");
  float newTemperature = readTemperature();
  if (temperature != newTemperature) {
    String message = "My current home temperature is " + String((int)newTemperature) + "°C. Power by Arduino :)";
    char charBuf[message.length()];
    message.toCharArray(charBuf, message.length()+1);
    if (twitter.post(charBuf)) {
      int status = twitter.wait(&Serial);
      if (status == 200) {
        Serial.println("OK.");
        beep(200);
      } else {
        Serial.print("failed : code ");
        Serial.println(status);
        beep(200);
        beep(200);
      }
    } else {
      Serial.println("connection failed.");
      beep(200);
      beep(200);
      beep(200);
    }
    temperature = newTemperature;
  } else {
    beep(200);
    beep(200);
    beep(200);
    beep(200);
  }
  delayInMinutes(30);
}

int readTemperature() {
  float newTemperature = analogRead(3);           //read the value from the sensor
  newTemperature = (5.0 * newTemperature * 100.0) / 1024.0;  //convert the analog data to temperature
  Serial.print("newTemperature = ");
  Serial.println((int)newTemperature);
  return (int)newTemperature;
}

void beep(unsigned char delayms){
  analogWrite(9, 20);      // Almost any value can be used except 0 and 255
                           // experiment to get the best tone
  delay(delayms);          // wait for a delayms ms
  analogWrite(9, 0);       // 0 turns it off
  delay(delayms);          // wait for a delayms ms   
}

void delayInMinutes(int minutes) {
  for(int i = 0; i < minutes; i++) {
    delay(60000);
  }
}
