// C++ code
// Servo Motor interfacing
// TinkerCad : https://www.tinkercad.com/things/afv4pyBR4Ft-servo-interfacing/editel

#include<Servo.h>

// Servo init
Servo my_servo;
int pos = 0;

void setup()
{
	my_servo.attach(2);
}

void loop()
{
  // switch pos from 0 to max
  for(pos = 0; pos<=180; pos++)
    my_servo.write(pos);
  
  delay(1500);
  
  // switch pos from max to 0
  for(pos=180; pos>=0; pos--)
    my_servo.write(pos);
  
  delay(1500);
}