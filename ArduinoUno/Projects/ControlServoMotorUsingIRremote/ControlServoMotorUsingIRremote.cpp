// C++ code
// Control Servo Motor using IR Remote

#include<IRremote.h>
#include<Servo.h>

// for IR 
int RECV_PIN = 11;
IRrecv ir_recv(RECV_PIN);
decode_results results;

// for Servo 
Servo servo_motor;
int SERVO_PIN = 10;
int servo_pos = 0;

void setup()
{
  // start Serial Monitor
  Serial.begin(9600);
  
  // start recevier
  ir_recv.enableIRIn();
  
  // bind servo with pin and set angle to 0
  servo_motor.attach(SERVO_PIN);
  servo_motor.write(0);
  
}

void loop()
{
  if (ir_recv.decode(&results))
    {
        // print HEX value of key pressed in serial monitor
        Serial.println(results.value, HEX);
    	
    	// if vol up key is pressed then increase the servo pos
    	if (results.value == 0xFD50AF)
        {
			for(; servo_pos<=180; servo_pos++)
              servo_motor.write(servo_pos);
        }
    	
    	// if vol down key is pressed then decrease the servo pos
    	if (results.value == 0xFD10EF)
        {          
			for(; servo_pos>=0; servo_pos--)
              servo_motor.write(servo_pos);	
        }
    
    	ir_recv.resume();
    }
}