const int PRESSURE_PIN = A0;
const int LED_PIN = 3;
const int VIBRO_PIN = 6;


double intensity = 0;
int count = 1;
double fadeRate = 5;
int awake = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  pinMode(VIBRO_PIN, OUTPUT);
}

void loop() {
  int pressureVal = analogRead(PRESSURE_PIN);
  analogWrite(VIBRO_PIN, 1023);
  long intensityVal = map(pressureVal, 0, 1023, 0, 255);

  if (pressureVal > 400){
    count += 1;
  }

  if (count > 150) {
    analogWrite(VIBRO_PIN, 0);
    analogWrite(LED_PIN, 0);
    delay(3000);
    count = 0;
    analogWrite(VIBRO_PIN, 1023);
    analogWrite(LED_PIN,255);
  }
  /*else{
    if (intensityVal > 0){
      intensity = 255;
    }
    else if (intensity > 5){
      intensity += fadeRate;   
    }
  }*/
  
  
  analogWrite(LED_PIN, 255-intensityVal);
  //analogWrite(VIBRO_PIN, pressureVal);
  Serial.print(count);
  Serial.print(",");
  Serial.print(intensity);
  Serial.print(",");
  Serial.println(pressureVal);
  // put your main code here, to run repeatedly:
  
}
