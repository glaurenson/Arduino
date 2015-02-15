// Commentaire de test pour GIT
// Rajout commentaire pour Gary
const int LED = 5;
const int RESIN = 9;
const int RESOUT = 8;

int bpState;
int oldBpState;
int lastState = 1;
int i = 0;
int delayVal = 0;
int capI;

void setup() {
  pinMode(RESOUT, OUTPUT);     // output pin
  pinMode(RESIN, INPUT);
  pinMode(LED, OUTPUT);
}

void loop () {
  capI = 0;
  digitalWrite(RESOUT, HIGH);
  bpState = digitalRead(RESIN);
  
  while (bpState != HIGH) {
    capI++;
    bpState = digitalRead(RESIN);    // re-read the input to be checked 
  }
  digitalWrite(RESOUT, LOW);
  
  if(capI > 5) {
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
