// Commentaire de test pour GIT
// Rajout commentaire pour Gary

const int BP  = 2;
const int LED = 5;

int bpState;
int oldBpState;
int lastState = 1;
int i = 0;
int delayVal = 0;

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
      delay(100);
      lastState++;
      if(lastState > 3) lastState = 1;
      
      int toCalc = 255;
      switch(lastState) {
        case 1: toCalc = i; break;
        case 2: toCalc = abs(20-i); break;
        case 3: toCalc = abs(255-i); break;
      }
      
      delayVal = (int)(1000/toCalc);
    }
    oldBpState = bpState;
  }

  switch(lastState) {
    case 1 :
      if(i>0) i--;
      break;
      
    case 2 :
      if(i < 20) i++;
      if(i > 20) i--;
      break;

    case 3 :
      if(i < 255) i++;
      break;
  }

  analogWrite(LED, i);
  delay(delayVal);
}
