// Code to Control Bose Wave Radio II via Arduino by loganemakf

// Based on code from http://www.ladyada.net/learn/sensors/ir.html
// and work done by instructables user randofo
    // http://www.instructables.com/id/Clone-a-Remote-with-Arduino/
// this code is public domain, please enjoy!
 
int IRledPin =  2;    // LED connected to digital pin 13
int switchPin = 7;     // tact switch wired to pin 8
 
// The setup() method runs once, when the sketch starts
 /////////////////////////////////////////////////////////////////////////////
void setup()   {  
  Serial.begin(9600);
  
  // initialize the IR digital pin as an output:
  pinMode(IRledPin, OUTPUT); 
  pinMode(switchPin, INPUT);
  digitalWrite(switchPin, LOW);  
}
 /////////////////////////////////////////////////////////////////////////////
void loop()                     
{
  
  // An example of how to use commands
  if (digitalRead(switchPin) == HIGH){
    turnOn();
    Serial.println("GO");
  }
  delay(1000); 
 
}

// This procedure sends a 38KHz pulse to the IRledPin 
// for a certain # of microseconds. We'll use this whenever we need to send codes
void pulseIR(long microsecs) {
  // we'll count down from the number of microseconds we are told to wait

  cli();  // this turns off any background interrupts
  while (microsecs > 0) {
    // 38 kHz is about 13 microseconds high and 13 microseconds low
   digitalWrite(IRledPin, HIGH);  // this takes about 3 microseconds to happen
   delayMicroseconds(10);         // hang out for 10 microseconds
   digitalWrite(IRledPin, LOW);   // this also takes about 3 microseconds
   delayMicroseconds(10);         // hang out for 10 microseconds
 
   // so 26 microseconds altogether
   microsecs -= 26;
  }
 
  sei();  // this turns them back on
}
  
void turnOn() {
  delayMicroseconds(12020);
pulseIR(4480);
delayMicroseconds(4420);
pulseIR(560);
delayMicroseconds(1640);
pulseIR(560);
delayMicroseconds(1640);
pulseIR(580);
delayMicroseconds(1620);
pulseIR(580);
delayMicroseconds(520);
pulseIR(580);
delayMicroseconds(520);
pulseIR(580);
delayMicroseconds(520);
pulseIR(580);
delayMicroseconds(520);
pulseIR(560);
delayMicroseconds(540);
pulseIR(600);
delayMicroseconds(1600);
pulseIR(580);
delayMicroseconds(1620);
pulseIR(580);
delayMicroseconds(1620);
pulseIR(580);
delayMicroseconds(520);
pulseIR(580);
delayMicroseconds(520);
pulseIR(580);
delayMicroseconds(520);
pulseIR(580);
delayMicroseconds(520);
pulseIR(580);
delayMicroseconds(520);
pulseIR(580);
delayMicroseconds(1640);
pulseIR(560);
delayMicroseconds(1640);
pulseIR(560);
delayMicroseconds(1640);
pulseIR(580);
delayMicroseconds(520);
pulseIR(580);
delayMicroseconds(520);
pulseIR(560);
delayMicroseconds(540);
pulseIR(560);
delayMicroseconds(540);
pulseIR(560);
delayMicroseconds(540);
pulseIR(580);
delayMicroseconds(520);
pulseIR(560);
delayMicroseconds(540);
pulseIR(560);
delayMicroseconds(540);
pulseIR(560);
delayMicroseconds(1640);
pulseIR(580);
delayMicroseconds(1620);
pulseIR(580);
delayMicroseconds(1620);
pulseIR(580);
delayMicroseconds(1640);
pulseIR(560);
delayMicroseconds(1620);
pulseIR(580);
delayMicroseconds(46120);
pulseIR(4480);
delayMicroseconds(4420);
pulseIR(580);
delayMicroseconds(1620);
pulseIR(580);
delayMicroseconds(1620);
pulseIR(580);
delayMicroseconds(1620);
pulseIR(580);
delayMicroseconds(520);
pulseIR(580);
delayMicroseconds(520);
pulseIR(580);
delayMicroseconds(520);
pulseIR(580);
delayMicroseconds(520);
pulseIR(580);
delayMicroseconds(520);
pulseIR(580);
delayMicroseconds(1620);
pulseIR(580);
delayMicroseconds(1640);
pulseIR(560);
delayMicroseconds(1620);
pulseIR(580);
delayMicroseconds(540);
pulseIR(560);
delayMicroseconds(520);
pulseIR(580);
delayMicroseconds(520);
pulseIR(580);
delayMicroseconds(520);
pulseIR(580);
delayMicroseconds(520);
pulseIR(580);
delayMicroseconds(1640);
pulseIR(560);
delayMicroseconds(1640);
pulseIR(560);
delayMicroseconds(1640);
pulseIR(580);
delayMicroseconds(520);
pulseIR(580);
delayMicroseconds(520);
pulseIR(580);
delayMicroseconds(520);
pulseIR(560);
delayMicroseconds(540);
pulseIR(560);
delayMicroseconds(540);
pulseIR(580);
delayMicroseconds(520);
pulseIR(560);
delayMicroseconds(540);
pulseIR(560);
delayMicroseconds(540);
pulseIR(580);
delayMicroseconds(1620);
pulseIR(580);
delayMicroseconds(1620);
pulseIR(580);
delayMicroseconds(1620);
pulseIR(580);
delayMicroseconds(1620);
pulseIR(580);
delayMicroseconds(1640);
pulseIR(580);

}  
