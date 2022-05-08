#define ledPin 7
int state = 0;

void setup() {
  // put your setup code here, to run once:

  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  Serial.begin(38400); // Default communication rate of the HC-05?
}

void loop() {
  // put your main code here, to run repeatedly:

  if(Serial.available() > 0) { // Checks whether data is coming in?
    state = Serial.read(); // Reads the data from the Serial Monitor
  }

  if (state == '0') {
    digitalWrite(ledPin, LOW); // Turn LED off
    Serial.println("LED: OFF"); // Send back to the phone
    state = 0;
  }

  else if (state == '1') {
    digitalWrite(ledPin, HIGH); // Turn LED on
    Serial.println("LED: ON"); // Send back to phone
    state = 0;
  }
}
