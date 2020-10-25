#include <Servo.h>

Servo myservo;

int angulo;

void setup()
{
  myservo.attach(13);
}

void loop()
{
  angulo = 180;
  myservo.write(angulo);
  delay(2000);
  
  angulo = 90;
  myservo.write(angulo);
  delay(2000);
  
  angulo = 0;
  myservo.write(angulo);
  delay(2000);
}