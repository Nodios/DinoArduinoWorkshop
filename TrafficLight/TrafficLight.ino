int red = 13;
int yellow = 12;
int green = 11;

int inPort = 2;
int turnYellow = 4;

bool trafficLightOff = false;

void setup(){
  pinMode(red,OUTPUT);
  pinMode(yellow,OUTPUT);
  pinMode(green,OUTPUT);

  pinMode(inPort, INPUT);
  pinMode(turnYellow, INPUT);

  digitalWrite(red, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(green, LOW);

  Serial.begin(9600);
}

void loop(){
  turnBlinkYellow();
  Serial.print(trafficLightOff);
  if(digitalRead(turnYellow) == HIGH){
    trafficLightOff = !trafficLightOff;
  }else{
  digitalWrite(red, HIGH);
  int val = digitalRead(inPort);
  if(val==HIGH){
    delay(2000);
    changeLights();
  }
  }
  //changeLights();
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

void turnBlinkYellow(){
  if(trafficLightOff){
    digitalWrite(yellow, HIGH);
    delay(250);
    digitalWrite(yellow, LOW);
    delay(250);
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

