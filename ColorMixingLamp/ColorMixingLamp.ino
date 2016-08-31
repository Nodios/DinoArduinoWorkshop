const int greenLedPin = 9;
const int redLedPin = 11;
const int blueLedPin = 10;

const int redSensorPin = A0;
const int greenSensorPin = A1;
const int blueSensorPin = A2;

int redValue = 0;
int blueValue = 0;
int greenValue = 0;

int redSensorValue = 0;
int blueSensorValue = 0;
int greenSensorValue = 0;

void setup() {
  Serial.begin(9600);

  pinMode(greenLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);
}

void loop() {
  redSensorValue = analogRead(redSensorPin);
  delay(5);
  blueSensorValue = analogRead(blueSensorPin);
  delay(5);
  greenSensorValue = analogRead(greenSensorPin);
  delay(5);
  
//  Serial.print("Red: ");
//  Serial.print(redSensorValue);
//  Serial.print("Blue: ");
//  Serial.print(blueSensorValue);
//  Serial.print("Green: ");
//  Serial.print(greenSensorValue);

  redValue = redSensorValue / 4;
  blueValue = blueSensorValue / 4;
  greenValue = greenSensorValue / 4;

  Serial.print("Red: ");
  Serial.print(redValue);
  Serial.print("Blue: ");
  Serial.print(blueValue);
  Serial.print("Green: ");
  Serial.print(greenValue);

  
  
  analogWrite(redLedPin, redValue);
  analogWrite(blueLedPin, blueValue);
  analogWrite(greenLedPin, greenValue);
}
