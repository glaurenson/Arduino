const int BP  = 2;
const int LED = 5;

int bpState;
int oldBpState;
int lastState = 1;

void setup() {
  pinMode(BP, INPUT);
  pinMode(LED, OUTPUT);
}

void loop () {
  digitalWrite(BP , HIGH);
  bpState = digitalRead(BP);
  delay (100);
  
  if(bpState != oldBpState) {
    oldBpState = !bpState;
    if(!bpState) {
      lastState++;
    }
    
    if(lastState > 3) {
      lastState = 1;
    }
    oldBpState = bpState;
    
    switch(lastState) {
      case 1 :
        digitalWrite(LED, LOW);
        break;
        
      case 2 :
        analogWrite(LED, 40);
        break;
        
      case 3 :
        digitalWrite(LED, HIGH);
        break;
    }
  }
}
