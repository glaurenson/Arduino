// Commentaire de test pour GIT

const int BP  = 2;
const int LED = 5;

int bpState;
int oldBpState;
int lastState = 1;
int i = 0;
boolean done = false;

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
      
      if(lastState > 3) {
        lastState = 1;
      }
      
      switch(lastState) {
        case 1 :
          if(!done) {
            digitalWrite(LED, LOW);
          } else {
            for(i = 255; i>= 0; i-=5) {
              analogWrite(LED, i);
              delay(3);
            }
          }
          
          break;
          
        case 2 :
          for(i = 0; i<= 40; i++) {
            analogWrite(LED, i);
            delay(15);
          }
          break;
          
        case 3 :
          for(i = 40; i<= 255; i++) {
            analogWrite(LED, i);
            delay(3);
          }
          done = true;
          break;
      }
    }

    oldBpState = bpState;
  }
}
