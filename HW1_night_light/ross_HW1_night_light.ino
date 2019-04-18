#include <Servo.h>

// servo
const int SERVO_PIN = 9;

const int MAX_ANGLE = 180;

// RGB
const int GREEN_RGB_PIN = 6;
const int BLUE_RGB_PIN = 5;
const int RED_RGB_PIN = 3;
const int MAX_INTENSITY = 255;

//photo sensor controls intensity
const int PHOTO_PIN = A0;
const int MAX_PHOTO_VAL = 1023;

// slider
const int SLIDER_PIN = A1;
const int MAX_SLIDER_VAL = 1023;

// didn't have time to make color change and intensity work together
// to see color slider mode == "COLOR_SLIDER"
// to change intensity based on photocell mode == "INTENSITY"

const String mode = "INTENSITY";
Servo servo;
int angle =0;

void setup() {
  // put your setup code here, to run once:
  servo.attach(SERVO_PIN);
  // set pin modes RGB Light
  pinMode(RED_RGB_PIN, OUTPUT);
  pinMode(GREEN_RGB_PIN, OUTPUT);
  pinMode(BLUE_RGB_PIN, OUTPUT);
  
  Serial.begin(9600);
}

void loop() { 
  // get raw input values
  int sliderVal = analogRead(SLIDER_PIN);
  int photoVal = analogRead(PHOTO_PIN);

  // convert to range of servo
  long angleVal = map(sliderVal, 0, MAX_SLIDER_VAL, 0, MAX_ANGLE);
  // turn motor
  servo.write(angleVal);

  //get color val or intensity based on the range of color or the range of intensity of light in test conditions
  long colorVal = map(sliderVal, 0, MAX_SLIDER_VAL, 0, 255);
  long intensityVal = map(photoVal, 230, 700, 0, 255);
 
  if (mode == "INTENSITY"){
    analogWrite(RED_RGB_PIN, intensityVal);
    analogWrite(BLUE_RGB_PIN, intensityVal);
  } else if (mode == "COLOR_SLIDER"){
    analogWrite(RED_RGB_PIN, 255-colorVal);
    analogWrite(GREEN_RGB_PIN, colorVal);
  }
  delay(10);
 
}
