// Declare Constants
const int sensorPin = 2;           // PIR Sensor is attached to digital pin 2
const int ledPin = 13;             // Built-in LED
const int ledBlinkTime = 500;      // Blink one for half a second while calibrating

volatile int state = LOW;

// Wait for the seonsor to calibrate (20 - 60 seconds according to datasheet)
// 60 Seconds in milliseconds
const unsigned int calibrationTime = 60000;

void setup() {
  Serial.begin(115200);
  
  pinMode(sensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  
  // We need to wait one minute for the sensor to calibrate
  // Get out of view of the sensor for this duration!
  
  // Blink the LED while calibrating
  for (unsigned int i=0; i<calibrationTime; i+=ledBlinkTime*2) {
    digitalWrite(ledPin, HIGH);
    delay(ledBlinkTime);
    digitalWrite(ledPin, LOW);
    delay(ledBlinkTime);
  }
  
  attachInterrupt(0,motrip,CHANGE);
}

void loop() {
  
  // Turn the LED off
  digitalWrite(ledPin, LOW);
}

void motrip()
{
  state=!state;
  // Turn the LED on
  digitalWrite(ledPin, HIGH);
  delay(1000);
  // Tell the host computer we detected motion
  Serial.print(1);
}


