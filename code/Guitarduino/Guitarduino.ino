#include <toneAC.h>

const int stringInput = A4; // The input pin for the string-like soft pot.
int stringValue = 0;  // variable to store the value coming from the sensor

const int pickX = A1; // The input pin for the joystick's X axis.
int pickXCenter = 0;
int pickXValue = 0;   // The value of the joystick's X axis.

const int pickY = A2; // Same as above, but for Y.
int pickYCenter = 0;
int pickYValue = 0;

const int pickClick = A3; // Digital pin 2 for detecting clicked joystick.
bool pickClicked = false;

int ledPin = 13;      // select the pin for the LED

// public variables:
float volume = 0;
int clickNumber = 0;
int stringLowValue = 825;
int stringHighValue = 60;
long frequency = 0;
float lowFreq = 80.628;
float highFreq = 287.767;

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);
  Serial.begin(38400);

  delay(100);

  // Calibrate Joysticks:
  pickXCenter = analogRead(pickX);
  pickYCenter = analogRead(pickY);
}

void loop() {
  
  // read the values from the sensors:
  stringValue = analogRead(stringInput);
  if (stringValue < 2) { // Handle open strings:
    stringValue = stringLowValue;
  }
  pickXValue = analogRead(pickX);
  pickYValue = analogRead(pickY);
  updateButton();

  // update the variables
  volume = volumeFromTwoInputs(pickXValue, pickYValue);
  frequency = map(long(stringValue), long(stringLowValue), long(stringHighValue), long(lowFreq), long(highFreq));

  Serial.println("Attempting to play freq: " + String(frequency) + " and value: " + String(volume) + " from str val: " + String(stringValue));

  toneAC(frequency, volume * 10);
}

// For detecting button presses only at initial press
void updateButton() {
  bool clicked = digitalRead(pickClick);
  if (clicked && !pickClicked) {
    click();  
  }
  pickClicked = clicked;
}

void click() {
  Serial.println("The button was clicked.");
  clickNumber++;
  
}

float volumeFromTwoInputs (int x, int y) {
  int xDiff = abs(x - pickXCenter);
  int yDiff = abs(y - pickYCenter);
  return float(float(xDiff + yDiff) / 1023);
}

