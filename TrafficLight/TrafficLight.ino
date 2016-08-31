int red = 13;
int yellow = 12;
int green = 11;

void setup(){
  pinMode(red,OUTPUT);
  pinMode(yellow,OUTPUT);
  pinMode(green,OUTPUT);

  digitalWrite(red, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(green, LOW);
}

void loop(){
  changeLights();
}

void changeLights(){
  digitalWrite(red, HIGH);
  delay(5000);

  digitalWrite(yellow, HIGH);
  delay(2000);

  //green light
  digitalWrite(red, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(green, HIGH);
  delay(4000);
  
  blinkGreen();

  digitalWrite(yellow, HIGH);
  delay(2000);

  digitalWrite(red, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(green, LOW);
}

void turnBlinkYellow(bool trafficLightOff = false){
  if(!trafficLightOff){
    digitalWrite(yellow, HIGH);
    delay(3000);
    digitalWrite(yellow, LOW);
  }
}

void blinkGreen(){
  for(int i = 0; i<4;i++){
    digitalWrite(green, LOW);
    delay(500);
    digitalWrite(green, HIGH);
    delay(500);
  }

  digitalWrite(green, LOW);
}

