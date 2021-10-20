#include <Adafruit_CircuitPlayground.h>

void setup() {
  // Initialize the circuit playground
  CircuitPlayground.begin();
  //Serial.begin(9600);
  
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
  
 // while (!Serial);
  CircuitPlayground.irReceiver.enableIRIn();
 // Serial.println("Ready to receive IR signals");
}
void loop() {
if (CircuitPlayground.irReceiver.getResults()) {
CircuitPlayground.irDecoder.decode();
CircuitPlayground.irDecoder.dumpResults(false);
switch(CircuitPlayground.irDecoder.value) {
  case 0xFF18E7: 
    digitalWrite(A1, HIGH);
    digitalWrite(A2, LOW);
    digitalWrite(A4, HIGH);
    digitalWrite(A5, LOW);
   // Serial.println("motor on");
    break;
    
  case 0xFF10EF: 
    digitalWrite(A1, LOW);
    digitalWrite(A2, LOW);
    digitalWrite(A4, HIGH);
    digitalWrite(A5, LOW);
    delay(250);
    digitalWrite(A1, LOW);
    digitalWrite(A2, LOW);
    digitalWrite(A4, LOW);
    digitalWrite(A5, LOW);
    
   // Serial.println("motor off");
   break;

  case 0xFF4AB5: 
    digitalWrite(A1, LOW);
    digitalWrite(A2, HIGH);
    digitalWrite(A4, LOW);
    digitalWrite(A5, HIGH);
    break;

  case 0xFF5AA5: 
    digitalWrite(A1, HIGH);
    digitalWrite(A2, LOW);
    digitalWrite(A4, LOW);
    digitalWrite(A5, LOW);
    delay(250);
    digitalWrite(A1, LOW);
    digitalWrite(A2, LOW);
    digitalWrite(A4, LOW);
    digitalWrite(A5, LOW);
    break;

  case 0xFF38C7:
    digitalWrite(A1, LOW);
    digitalWrite(A2, LOW);
    digitalWrite(A4, LOW);
    digitalWrite(A5, LOW);
    break;
    
}
CircuitPlayground.irReceiver.enableIRIn(); 
}

}
