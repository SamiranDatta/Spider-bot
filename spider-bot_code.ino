#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
// you can also call it with a different address you want
//Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x41);

// Depending on your servo make, the pulse width min and max may vary, you 
// want these to be as small/large as possible without hitting the hard stop
// for max range. You'll have to tweak them as necessary to match the servos you
// have!
#define SERVOMIN  130 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  580 // this is the 'maximum' pulse length count (out of 4096)

// our servo # counter
uint8_t servonum = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("16 channel Servo test!");
  pwm.begin();
  
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates

  //yield();
}

// the code inside loop() has been updated by Robojax
void loop() {

//pwm.setPWM(0,0,580);
//pwm.setPWM(0, 0, angleToPulse(90) );
  for( int angle =10; angle<=90; angle +=5){
    delay(2);
    pwm.setPWM(1, 0, angleToPulse(angle) );
  }
  delay(10);
  for( int angle =90; angle>=0; angle -=5){
    delay(2);
    pwm.setPWM(3, 0, angleToPulse(angle) );
  }
  delay(10);
  for( int angle =0; angle<=90; angle +=5){
    delay(2);
    pwm.setPWM(5, 0, angleToPulse(angle) );
  }
  delay(10);
  for( int angle =90; angle>=0; angle -=5){
    delay(2);
    pwm.setPWM(7, 0, angleToPulse(angle) );
  }
  delay(10);
  /*for( int angle =180; angle>70; angle -=5){
    delay(2);
    pwm.setPWM(0, 0, angleToPulse(angle) );
  }
  for( int angle =180; angle>70; angle -=5){
    delay(2);
    pwm.setPWM(1, 0, angleToPulse(angle) );
  }
  for( int angle =180; angle>70; angle -=5){
    delay(2);
    pwm.setPWM(2, 0, angleToPulse(angle) );
  }
  for( int angle =180; angle>70; angle -=5){
    delay(2);
    pwm.setPWM(3, 0, angleToPulse(angle) );
  }
*/
  delay(1000);
/*for( int angle =70; angle< 181; angle +=5){
    delay(2);
    pwm.setPWM(0, 0, angleToPulse(angle) );
  }*/
 
}

/*
 * angleToPulse(int ang)
 * gets angle in degree and returns the pulse width
 * also prints the value on seial monitor
 * written by Ahmad Nejrabi for Robojax, Robojax.com
 */
int angleToPulse(int ang){
   int pulse = map(ang,0, 180, SERVOMIN,SERVOMAX);// map angle of 0 to 180 to Servo min and Servo max 
   Serial.print("Angle: ");Serial.print(ang);
   Serial.print(" pulse: ");Serial.println(pulse);
   return pulse;
}
