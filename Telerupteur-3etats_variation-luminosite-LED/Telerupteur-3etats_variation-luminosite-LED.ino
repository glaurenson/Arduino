// Commentaire de test pour GIT
// Rajout commentaire pour Gary

const int BP  = 2;
const int LED = 5;

int bpState;
int oldBpState;
int lastState = 1;
int i = 0;

void setup() {
  pinMode(BP, INPUT);
  pinMode(LED, OUTPUT);
}

void loop () {
  digitalWrite(BP , HIGH);
  bpState = digitalRead(BP);
  
  if(bpState != oldBpState) {
    oldBpState = !bpState;
    if(!bpState) {
      lastState++;
      
      if(lastState > 3) {
        lastState = 1;
      }
      oldBpState = bpState;
    }
  }

  switch(lastState) {
    case 1 :
      if(i>0) i--;
      break;
      
    case 2 :
      if(i < 40) i++;
      if(i > 40) i--;
      break;
      
    case 3 :
      if(i < 255) i++;
      break;
  }

  analogWrite(LED, i);
  delay(5);
}
