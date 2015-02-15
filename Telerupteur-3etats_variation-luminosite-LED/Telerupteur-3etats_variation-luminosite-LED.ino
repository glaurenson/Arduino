#include <CapacitiveSensor.h>
CapacitiveSensor pad = CapacitiveSensor(8, 9); // 8 > output, 9 > input
const int LED = 5;

int bpState;
int oldBpState;
int lastState = 1;
int i = 0;
int delayVal = 0;
boolean done = false;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop () {
  int val = pad.capacitiveSensor(30);
  Serial.println(val);
  
  if(val > 100) {
    if(!done) {
      done = true;
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
  } else {
    done = false;
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
