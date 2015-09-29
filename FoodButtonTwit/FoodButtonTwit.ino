/* Post a simple message to Twitter  */
#include <SPI.h>
#include <Ethernet.h>
#include <Twitter.h>

byte mac[] = { 0x90, 0xA2, 0xDA, 0x0E, 0x92, 0xA4 };
byte ip[] = { 192, 168, 100, 9 };

Twitter twitter("3810814037-KusNwUKamf8cBPcGB78RuzlbmQFqizZGwjvUGo0");
char msg[] = "I am currently eating some delicious food!";

void setup()
{
  Ethernet.begin(mac, ip);
  Serial.begin(9600);

  delay(1000);

  Serial.println("connecting ...");
  if (twitter.post(msg)) {
    int status = twitter.wait(&Serial);
    if (status == 200) {
      Serial.println("OK.");
    } else {
      Serial.print("failed : code ");
      Serial.println(status);
    }
  } else {
    Serial.println("connection failed.");
  }
}

void loop()
{
}
