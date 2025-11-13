#if __has_include(<Arduino.h>)
#include <Arduino.h>
#endif





// Joystick example with helper function + protection against redundant writes


const int VRx = A0;  
const int VRy = A1;  
const int SW  = A2;  


// Output pins
const int LowerCornerLeft_Pin  = 8;
const int UpperCornerLeft      = 10;
const int LowerCornerRight_Pin = 13;
const int UpperCornerRight_pin = 12;
const int Front_Pin            = 11; 
const int Back_Pin             = 9;


const int DEADZONE = 100;   // Center tolerance
const int EDGEZONE = 200;   // Edge tolerance


// Track current state of each pin
int currentStates[6] = {LOW, LOW, LOW, LOW, LOW, LOW};


// Function to update all pins in one call
void setAllPins(int state) {
  int pins[6] = {LowerCornerLeft_Pin, UpperCornerLeft, LowerCornerRight_Pin, UpperCornerRight_pin, Front_Pin, Back_Pin};


  for (int i = 0; i < 6; i++) {
    if (currentStates[i] != state) {   // only update if different
      digitalWrite(pins[i], state);
      currentStates[i] = state;        // store new state
    }
  }
}


// Function to set one pin safely (only if state changes)
void setPin(int index, int state) {
  int pins[6] = {LowerCornerLeft_Pin, UpperCornerLeft, LowerCornerRight_Pin, UpperCornerRight_pin, Front_Pin, Back_Pin};
  
  if (currentStates[index] != state) {
    digitalWrite(pins[index], state);
    currentStates[index] = state;
  }
}


void setup() {
  Serial.begin(9600);


  pinMode(LowerCornerLeft_Pin, OUTPUT);
  pinMode(UpperCornerLeft, OUTPUT);
  pinMode(LowerCornerRight_Pin, OUTPUT);
  pinMode(UpperCornerRight_pin, OUTPUT);
  pinMode(Front_Pin, OUTPUT);
  pinMode(Back_Pin, OUTPUT);
  pinMode(SW, INPUT_PULLUP);


  setAllPins(LOW); // turn off all at start
}


void loop() {
  int xValue = analogRead(VRx);
  int yValue = analogRead(VRy);


  Serial.print("X: ");
  Serial.print(xValue);
  Serial.print(" | Y: ");
  Serial.println(yValue);


  setAllPins(LOW);  // reset all first


  if (abs(xValue - 512) < DEADZONE && yValue < EDGEZONE)
    setPin(4, HIGH);   // Front (index 4)


  else if (abs(xValue - 512) < DEADZONE && yValue > (1023 - EDGEZONE))
    setPin(5, HIGH);   // Back (index 5)


  else if (xValue < EDGEZONE && yValue < EDGEZONE)
    setPin(1, HIGH);   // Upper left


  else if (xValue < EDGEZONE && yValue > (1023 - EDGEZONE))
    setPin(0, HIGH);   // Lower left


  else if (xValue > (1023 - EDGEZONE) && yValue < EDGEZONE)
    setPin(3, HIGH);   // Upper right


  else if (xValue > (1023 - EDGEZONE) && yValue > (1023 - EDGEZONE))
    setPin(2, HIGH);   // Lower right


  else if (digitalRead(SW) == LOW) {
    setAllPins(HIGH); // button -> all ON
  }
}




