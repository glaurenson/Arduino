int LED = 13;
int THRESHOLD = 5;
int capI;      // interval when sensor pin 5 returns LOW

void setup() {

  Serial.begin(9600);

  pinMode(LED, OUTPUT);

  pinMode(4, OUTPUT);     // output pin

  pinMode(5, INPUT);      // input pin

}




void loop() {

  capI = 0;      // clear out capacitance measure at each loop 




  // transition output pin4 LOW-to-HIGH  to 'activate' sensor pin5

  digitalWrite(4, HIGH);      




  // On activation, value of pin 5 stays LOW for a time interval T = R*C. 

  // C is big if the sensor is touched with a conductive object.

  // Increment capI for the interval while pin5 is LOW

  int val = digitalRead(5);  // read the input to be checked

  while (val != HIGH){    

    capI++;    

    val = digitalRead(5);    // re-read the input to be checked 

  }

  delay(1);

  

  // transition output pin4 HIGH-to-LOW to 'deactivate' sensor pin5

  digitalWrite(4, LOW);      

  Serial.println(capI, DEC);  // print out interval 




  if (capI > THRESHOLD)       // Turn LED on if capI is above threshold

    digitalWrite(LED, HIGH);

  else  

    digitalWrite(LED,  LOW);

}
