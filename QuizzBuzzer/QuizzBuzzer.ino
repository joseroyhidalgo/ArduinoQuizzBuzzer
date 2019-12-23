/*
  Button

  Turns on and off a light emitting diode(LED) connected to digital pin 13,
  when pressing a pushbutton attached to pin 2.

  The circuit:
  - LED attached from pin 13 to ground
  - pushbutton attached to pin 2 from +5V
  - 10K resistor attached to pin 2 from ground

  - Note: on most Arduinos there is already an LED on the board
    attached to pin 13.

  created 2005
  by DojoDave <http://www.0j0.org>
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Button
*/

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 4;     // the number of the pushbutton pin
const int ledPin =  11;      // the number of the LED pin

const int buttonPin2 = 2;     // the number of the pushbutton pin
const int ledPin2 =  12;      // the number of the LED pin

const int buttonPin3 = 6;     // the number of the pushbutton pin
const int ledPin3 =  10;      // the number of the LED pin

const int buttonPinGo = 7;
const int ledGo =  5;

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int buttonState2 = 0; 
int buttonState3 = 0; 
int buttonStateGo = 0; 

const int soundPin = 3;
long randNumber = 0;
int ledGoState = false;
int ledPinState = true;
int ledPin2State = true;
int ledPin3State = true;

unsigned long currentMillis;
unsigned long randomDelay;
void(* resetFunc) (void) = 0;//declare reset function at address 0

#define NOTE_E7  2637
#define NOTE_C7  2093
#define NOTE_G7  3136
#define NOTE_G6  1568

#define NOTE_G4  392
#define NOTE_G5  783
#define NOTE_A4  440
#define NOTE_B4  493
#define NOTE_C4  262
#define NOTE_DS4 311
#define NOTE_F4  349
#define NOTE_E4  330
#define NOTE_D4  293

int melody[] = {
  NOTE_E7, NOTE_E7, 0, NOTE_E7,
  0, NOTE_C7, NOTE_E7, 0,
  NOTE_G7, 0, 0,  0,
  NOTE_G6, 0, 0
};
//Mario main them tempo
int tempo[] = {
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12
};

int melody2[] = {
  NOTE_G4, NOTE_C4, NOTE_DS4,NOTE_F4,
  NOTE_G4, NOTE_C4, NOTE_DS4,NOTE_F4,
  NOTE_G4, NOTE_C4, NOTE_E4,NOTE_F4,
  NOTE_G4, NOTE_C4, NOTE_E4,NOTE_F4,
  NOTE_G4, 
  0, NOTE_C4, NOTE_DS4, NOTE_F4,
  NOTE_G4, NOTE_C4, NOTE_DS4, NOTE_F4,
  NOTE_D4
};
//Mario main them tempo
int tempo2[] = {
  8, 13, 12, 9,
  8, 13, 12, 9,
  8, 13, 12, 9,
  8, 13, 12, 9,
  8,
  5, 5, 13, 12,
  5, 5, 13, 12,
  5
};

int melody3[] = {
  NOTE_G4, NOTE_G4, NOTE_A4,
  NOTE_G4, NOTE_C4, NOTE_B4,
  NOTE_G4, NOTE_G4, NOTE_A4,
  NOTE_G4, NOTE_D4, NOTE_C4,
  NOTE_G4, NOTE_G4, NOTE_G5,
  NOTE_E4, NOTE_C4, NOTE_C4,
  NOTE_B4, NOTE_A4, NOTE_F4,
  NOTE_F4, NOTE_E4, NOTE_C4,
  NOTE_D4, NOTE_C4
};
//Mario main them tempo
int tempo3[] = {
  12,12,5, 
  8,8,2, 
  12,12,5, 
  8,8,2,
  12,12,5,
  6,8,8,
  6,2,8,
  8,5,6,
  8,2
  
};

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);

   // initialize the LED pin as an output:
  pinMode(ledPin2, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin2, INPUT);
  
  // initialize the LED pin as an output:
  pinMode(ledPin3, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin3, INPUT);
  
  pinMode(soundPin, OUTPUT);
  pinMode(ledGo, OUTPUT);
  pinMode(buttonPinGo, INPUT);
  
  Serial.begin(9600);
  randomSeed(analogRead(0));
  
  // print a random number from 3sec to 10sec
  randNumber = random(3000,10000);
  Serial.println("randNumber_=");
  Serial.println(randNumber);
  randomDelay = randNumber;
}

//void(* resetFunc) (void) = 0

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  buttonStateGo = digitalRead(buttonPinGo);
  currentMillis = millis();
  
//  if (buttonState2 == HIGH) {
//    pinWin(2);
//  }
  
//  if( currentMillis > randomDelay){
//    Serial.println(currentMillis);
//    Serial.println("randNumber=");
//    Serial.println(randomDelay);
//  }
//ledGoState = currentMillis > randomDelay ? true : false;
  ledGoState =  buttonStateGo == HIGH ? true : false;
  
  digitalWrite(ledGo, ledGoState ? HIGH : LOW);
  
  randNumber = 0;

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH && ledGoState && ledPinState ) {
    ledPinState = true;
    ledPin2State = false;
    ledPin3State = false;
    pinWin(1);
  } else if(buttonState == HIGH && !ledGoState) {
    ledPinState = false;
    digitalWrite(ledPin, LOW);
  }

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  else if (buttonState2 == HIGH && ledGoState && ledPin2State) {
    ledPinState = false;
    ledPin2State = true;
    ledPin3State = false;
    pinWin(2);
  } else if(buttonState2 == HIGH && !ledGoState) {
    ledPin2State = false;
    digitalWrite(ledPin2, LOW);
  }
  
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  else if (buttonState3 == HIGH && ledGoState && ledPin3State) {
    ledPinState = false;
    ledPin2State = false;
    ledPin3State = true;
    pinWin(3);
  } else if(buttonState3 == HIGH && !ledGoState) {
    ledPin3State = false;
    digitalWrite(ledPin3, LOW);
  }
  
  if(ledPinState == LOW && ledPin2State==LOW && ledPin3State == LOW ){
     resetFunc();
  }
}

void sing() {
  int i = 1;
  int repeat = 1;
  while( i <= repeat ){
    int size = sizeof(melody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {
      int noteDuration = 1000 / tempo[thisNote];

      buzz(soundPin, melody[thisNote] * i/repeat, noteDuration);
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      // stop the tone playing:
      buzz(soundPin, 0, noteDuration);
    }
    i = i+1;
    delay(700);
  } 
}

void sing2() {
  int i = 1;
  int repeat = 1;
  while( i <= repeat ){
    int size = sizeof(melody2) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {
      int noteDuration = 1000 / tempo2[thisNote];

      buzz(soundPin, melody2[thisNote] * i/repeat, noteDuration);
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      // stop the tone playing:
      buzz(soundPin, 0, noteDuration);
    }
    i = i+1;
    delay(700);
  } 
}

void sing3() {
  int i = 1;
  int repeat = 1;
  while( i <= repeat ){
    int size = sizeof(melody3) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {
      int noteDuration = 1000 / tempo3[thisNote];

      buzz(soundPin, melody3[thisNote] * i/repeat, noteDuration);
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      // stop the tone playing:
      buzz(soundPin, 0, noteDuration);
    }
    i = i+1;
    delay(700);
  } 
}

void buzz(int targetPin, long frequency, long length) {
  long delayValue = 1000000 / frequency / 2; // calculate the delay value between transitions
  long numCycles = frequency * length / 1000; // calculate the number of cycles for proper timing
  for (long i = 0; i < numCycles; i++) { // for the calculated length of time...
    digitalWrite(targetPin, HIGH); // write the buzzer pin high to push out the diaphram
    delayMicroseconds(delayValue); // wait for the calculated delay value
    digitalWrite(targetPin, LOW); // write the buzzer pin low to pull back the diaphram
    delayMicroseconds(delayValue); // wait again or the calculated delay value
  }
  digitalWrite(13, LOW);
}

void pinWin(int s){
  digitalWrite(ledPin, ledPinState ? HIGH : LOW);
  digitalWrite(ledPin2, ledPin2State ? HIGH : LOW);
  digitalWrite(ledPin3, ledPin3State ? HIGH : LOW);
  
  s==1?sing():s==2?sing2():sing3();
  delay(5000);
  
  ledGoState = 0;
  digitalWrite(ledPin, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);
  digitalWrite(ledGo, LOW);
  randNumber = random(3000,10000);
  randomDelay = randNumber;
  resetFunc(); //call reset 
  
}

