
#define echoPin 12 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 11 //attach pin D3 Arduino to pin Trig of HC-SR04
#define yellowLed 8
#define greenLed 9
#define blueLed 10
#define redLed 7

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement
int distancePreviousLoop; //keep track of distance for toggle
boolean redLedOn = false;
boolean blueLedOn = false;
boolean greenLedOn = false;
boolean yellowLedOn = false;

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  
}
void loop() {
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distancePreviousLoop = distance;
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  if(distance > 0 && distance < 8 && !(distancePreviousLoop > 0 && distancePreviousLoop < 8))
  {
    if(!yellowLedOn){
      digitalWrite(yellowLed, HIGH);
      yellowLedOn = true;
    }
    else {
      digitalWrite(yellowLed, LOW);
      yellowLedOn = false;
    }
    
  }
  else if(distance > 8 && distance < 16)
  {
    if(!greenLedOn){
      digitalWrite(greenLed, HIGH);
      greenLedOn = true;
    }
    else {
      digitalWrite(greenLed, LOW);
      greenLedOn = false;
    }
    

  }
  else if(distance > 16 && distance < 24)
  {
    if(!blueLedOn){
      digitalWrite(blueLed, HIGH);
      blueLedOn = true;
    }
    else {
      digitalWrite(blueLed, LOW);
      blueLedOn = false;
    }
    

  }
  else if(distance > 24 && distance < 32)
  {
  
    if(!redLedOn){
      digitalWrite(redLed, HIGH);
      redLedOn = true;
    }
    else {
      digitalWrite(redLed, LOW);
      redLedOn = false;
    }
    
  }
}
