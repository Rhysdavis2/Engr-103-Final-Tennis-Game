//Initializing variables and library
#include <Adafruit_CircuitPlayground.h>
volatile int score = 0;
volatile int light;
bool isLeft;
bool isHit=0;

void setup() {
CircuitPlayground.begin();
Serial.begin(9600);
attachInterrupt(digitalPinToInterrupt(5), Lint, RISING);
attachInterrupt(digitalPinToInterrupt(4), Rint, RISING);
}

void loop() {
leftServe();
scoreCheck();
rightServe();
scoreCheck();
}

void leftServe() {
Serial.println("Serving Left");
isLeft=1;

for (int i=2; i<8; i++) {
light=i;
CircuitPlayground.setPixelColor(light-1, 0, 0, 0);
CircuitPlayground.setPixelColor(light, 0, 255, 0);
delay(1000-score*100);
}

}

void rightServe() {
Serial.println("Serving Right");
isLeft=0;

for (int i=7; i>1; i--) {
light=i;
CircuitPlayground.setPixelColor(light+1, 0, 0, 0);
CircuitPlayground.setPixelColor(light, 0, 255, 0);
delay(1000-score*100);
} 

}

void Lint() {
Serial.println("Left Button Pressed");
delay(5);
if (light==7) {

if (isHit==0) {
CircuitPlayground.playTone(50, 200); }
isHit=1;
}

else {
CircuitPlayground.playTone(500, 200);
}

}

void Rint() {
Serial.println("Right Button Pressed");
delay(5);
if (light==2) {

if (isHit==0) {
CircuitPlayground.playTone(50, 200); }

isHit=1;

}

}

void scoreCheck() {

if (isHit==1) {
  Serial.println("Hit");
  score++;
  isHit=0;
}

else {
  Serial.println("Miss");
 score=0;
 light=1;
 CircuitPlayground.playTone(500, 200);
 CircuitPlayground.setPixelColor(2, 0, 0, 0);
 CircuitPlayground.setPixelColor(7, 0, 0, 0);
 delay(2000);
}

if (score==10) {
Serial.println("Win!");
CircuitPlayground.playTone(200, 200);
CircuitPlayground.playTone(100, 300);
CircuitPlayground.playTone(400, 600);
delay(2000);
score=0;
}

Serial.println("Score:");
Serial.println(score);
}