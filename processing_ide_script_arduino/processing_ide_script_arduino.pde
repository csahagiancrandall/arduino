import processing.serial.*;
Serial myPort;
String ledStatus="HEATER ON";

void setup() {
  size(450,500);
  myPort = new Serial(this, "COM9", 9600);// Starts the serial communications
  myPort.bufferUntil('\n'); // Defines up to which character the data ...
}

void serialEvent (Serial myPort) { // Checks for available data in the Serial ...
  ledStatus = myPort.readStringUntil('\n'); // Reeads teh data sent from the Arduino
}

void draw() {
  background(237, 240, 241);
  fill(20, 160, 133); // Green
  stroke(33);
  strokeWeight(1);
  rect(50, 100, 150, 50, 10); // Turn ON button
  rect(250, 100, 150, 50, 10); // Turn OFF button
  fill(255);
  
  textSize(32);
  text("Turn ON",60,135);
  text("Turn OFF",255,135);
  textSize(24);
  fill(33);
  text("Status:",180,200);
  textSize(30);
  textSize(16);
  
  text(ledStatus,155,240);
  
  // If button "TURN ON" is pressed
  if(mousePressed && mouseX>50 && mouseX<200 && mouseY>100 && mouseY<150) {
    myPort.write('1'); // Sends the character '1' and that will turn on the light?
    stroke(255,0,0);
    strokeWeight(2);
    noFill();
    rect(50,100,150,50,10);
  }
  // If button "TURN OFF" is pressed
  if(mousePressed && mouseX>250 && mouseX<400 && mouseY>100 && mouseY<150) {
    myPort.write('0'); // Sends character '0' and that turns off LED
    stroke(255,0,0);
    strokeWeight(2);
    noFill();
    rect(250,100,150,50,10);
  }
}
