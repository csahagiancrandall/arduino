#include <SoftwareSerial.h> 
  
SoftwareSerial mySerial(10,11);

void setup() {
  // creates a "virtual serial port/UART
  // connect BT module TX to D10
  // connect BT module RX to D11
  // connect BT module Vcc to 5V, GND to GND
  // put your setup code here, to run once:
  // set digital pint to control as an output
  pinMode(13,OUTPUT);
  // set datarate for the SoftwareSerial port
  digitalWrite(13,HIGH);
  // set the pin high initially for the relay
  mySerial.begin(9600);
  // Send test message to other device
  mySerial.println("Hello from Arduino");
}

// Store incoming character from other device 
char a; 

void loop() {
  // put your main code here, to run repeatedly:
  if (mySerial.available())
  // text arrived in from BT serial...
  {
    a=(mySerial.read());
    if (a=='1')
    {
      digitalWrite(13,HIGH);
      mySerial.println("HEATER ON");  
    }
    if (a=='0')
    {
      digitalWrite(13,LOW);
      mySerial.println("HEATER OFF");
    }
    if (a=='?')
    {
      mySerial.println("Send '1' to turn LED on");
      mySerial.println("Send '0' to turn LED off");
    }
    // you can add more "if" statements with other characters to add more commands
  }
}
