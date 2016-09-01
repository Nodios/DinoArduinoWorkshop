///////////////////////////////////////////////////////////////////////////////
/*                                                                           */
/*                                                                           */
/* (c) e-radionica.com 2014 - http://www.e-radionica.com/licenca             */
/* e.radionica@me.com                                                        */
/*                                                                           */
/* Mjerenje udaljenosti pomocu HC-SR04 ultrazvucnog modula                   */
/*                                                                           */
///////////////////////////////////////////////////////////////////////////////
 
const int trig = 11;        // Trig na PIN11
const int echo = 12;        // Echo na PIN12
 
void setup() {
   
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
   
  Serial.begin(9600);  // zapocinjem serijsku komunikaciju
  Serial.println("Mjerenje udaljenost s HC-SR04 senzorom");
  Serial.println("");
   
}
 
void loop() {
   
// buduci da ne koristimo library, dolje je napisan nacin komunikacije s modulom
   
  long vrijeme, udaljenost;
   
  digitalWrite(trig, HIGH);   // Slanje triga
  delayMicroseconds(10);      // Odaslani trig traje 10 μs = 0.1 ms
  digitalWrite(trig, LOW);
   
  vrijeme = pulseIn(echo, HIGH);       // Primanje reflektiranog triga
  udaljenost = (vrijeme*0.034)/2;       // Racunanje udaljenosti, u centimetrima
                                       // konacna udaljenost senzora od predmeta
                                       // u cm je varijabla "udaljenost"
     
    Serial.print(udaljenost);   
    Serial.println(" cm");
 
  delay(50);  // preporucena pauza izmedu ocitanja ne bi trebala biti manja od 50ms 
}
