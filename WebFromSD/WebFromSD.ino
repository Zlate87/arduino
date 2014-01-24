/*
  Web Server
 
 A simple web server that shows the value of the analog input pins.
 using an Arduino Wiznet Ethernet shield. 
 
 Circuit:
 * Ethernet shield attached to pins 10, 11, 12, 13
 * Analog inputs attached to pins A0 through A5 (optional)
 
 created 18 Dec 2009
 by David A. Mellis
 modified 4 Sep 2010
 by Tom Igoe
 
 */

#include <SPI.h>
#include <Ethernet.h>
#include <SD.h>

// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network:
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192,168,0, 88);


// Initialize the Ethernet server library
// with the IP address and port you want to use 
// (port 80 is default for HTTP):
EthernetServer server(8888);

void setup()
{
  Serial.begin(9600);
  pinMode(10, OUTPUT);
  if (!SD.begin(4)) {
    Serial.println("SD initialization failed!");
  } else {
    Serial.println("SD initialization done.");
  }

  // start the Ethernet connection and the server:
  Ethernet.begin(mac, ip);
  server.begin();
  
}

void loop()
{
  // listen for incoming clients
  EthernetClient client = server.available();
  if (client) {
    // an http request ends with a blank line
    boolean currentLineIsBlank = true;
    String fileName = "";
    int spaces = 0;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        if (c == ' ') {
          spaces++;
        }
        
        if (spaces == 1) {
          fileName = fileName + c;
        }
        
        // if you've gotten to the end of the line (received a newline
        // character) and the line is blank, the http request has ended,
        // so you can send a reply
        Serial.print(c);
        if (c == '\n' && currentLineIsBlank) {
          fileName = fileName.substring(2);
          // send a standard http response header
          client.println("HTTP/1.1 200 OK");
          Serial.println(fileName.substring(fileName.indexOf('.')));
          if (fileName.substring(fileName.indexOf('.')) == ".html") {
            client.println("Content-Type: text/html");
          } else if (fileName.substring(fileName.indexOf('.')) == ".txt") {
            client.println("Content-Type: text/html");
          } else if (fileName.substring(fileName.indexOf('.')) == ".jpg") {
            client.println("Content-Type: image/jpeg");
          }
          client.println();

          
          char charBuf[fileName.length()];
          fileName.toCharArray(charBuf, fileName.length()+1);
          Serial.println(charBuf);

          File myFile = SD.open(charBuf);
          if (myFile) {
            Serial.println(fileName + ": Done!");
          } else {
            Serial.println(fileName + ": Problem");
          }
          // read from the file until there's nothing else in it:
          while (myFile.available()) {
            char z = myFile.read();
            client.print(z);
            //Serial.print(z);
          }
          myFile.close();
          
          
          break;
        }
        if (c == '\n') {
          // you're starting a new line
          currentLineIsBlank = true;
        } 
        else if (c != '\r') {
          // you've gotten a character on the current line
          currentLineIsBlank = false;
        }
      }
    }
    // give the web browser time to receive the data
    delay(1);
    // close the connection:
    client.stop();
  }
}
