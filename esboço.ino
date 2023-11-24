
 int led =13;            // led is connected to esp32 D13
 int pirdata =15 ;       // pir D is connected to D15
 int pirstate =LOW ;      // assuming no motion 
 int value =0;            // to read pin status 

void setup() {
  pinMode(led, OUTPUT);      //  Led as output
  pinMode(pirdata, INPUT);     // PIR sensor as input

  Serial.begin(9600);
}

void loop() {
  value = digitalRead(pirdata);  
  if (value == HIGH) {           
    digitalWrite(led, HIGH);  
    if (pirstate == LOW) {
     
      Serial.println("Motion detected!");
      
      pirstate = HIGH;
    }
  } else {
    digitalWrite(led, LOW); 
    if (pirstate == HIGH) {
      
      Serial.println("Motion ended!");
     
      pirstate = LOW;
    }
  }
}
