#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  130 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  580 // this is the 'maximum' pulse length count (out of 4096)

//rfs1 - 0,30,60
//rfs2 - H0, V90
//rfl - H0, V90

//rhs1 - 100, 130, 160
//rhs2 - H90, V0
//rhl - H90, V0

//lfs1 - 60, 30, 0
//lfs2 - H90, VU0
//lfl - H90, VD0

//lhl - H0, V90
//lhs2 - H0, V90
//lhs1 - 120, 90, 60


// our servo # counter
uint8_t servonum = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("16 channel Servo test!");
  pwm.begin();
  
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates

  //yield();
}
int angleToPulse(int ang){
   int pulse = map(ang,0, 180, SERVOMIN,SERVOMAX);// map angle of 0 to 180 to Servo min and Servo max 
   Serial.print("Angle: ");Serial.print(ang);
   Serial.print(" pulse: ");Serial.println(pulse);
   return pulse;
}
void initialize(void)
{
  for( int angle =0; angle<=90; angle +=5){
    pwm.setPWM(0, 0, angleToPulse(angle) ); //RFS2
    pwm.setPWM(1, 0, angleToPulse(90-angle) ); //LFS2
    pwm.setPWM(2, 0, angleToPulse(angle) ); //LHS2
    pwm.setPWM(3, 0, angleToPulse(90-angle) ); //RHS2
}
   pwm.setPWM(8, 0, angleToPulse(30) ); //RFS2
   pwm.setPWM(9, 0, angleToPulse(30) ); //LFS2
   pwm.setPWM(10, 0, angleToPulse(90) ); //LHS2
   pwm.setPWM(11, 0, angleToPulse(130) ); //RHS2
}

void stand(void)
{
  for( int angle =0; angle<=90; angle +=5){
    pwm.setPWM(4, 0, angleToPulse(angle) ); //RFL
    pwm.setPWM(5, 0, angleToPulse(90-angle) ); //LFL
    pwm.setPWM(6, 0, angleToPulse(angle) ); //LHL
    pwm.setPWM(7, 0, angleToPulse(90-angle) ); //RHL
    pwm.setPWM(0, 0, angleToPulse(90-angle) ); //RFS2
    pwm.setPWM(1, 0, angleToPulse(angle) ); //LFS2
    pwm.setPWM(2, 0, angleToPulse(90-angle) ); //LHS2
    pwm.setPWM(3, 0, angleToPulse(angle) ); //RHS2
    delay(100);
}}

void sit(void)
{
  for( int angle =0; angle<=90; angle +=5){
    pwm.setPWM(0, 0, angleToPulse(angle) ); //RFS2
    pwm.setPWM(1, 0, angleToPulse(90-angle) ); //LFS2
    pwm.setPWM(2, 0, angleToPulse(angle) ); //LHS2
    pwm.setPWM(3, 0, angleToPulse(90-angle) ); //RHS2
    pwm.setPWM(4, 0, angleToPulse(90-angle) ); //RFL
    pwm.setPWM(5, 0, angleToPulse(angle) ); //LFL
    pwm.setPWM(6, 0, angleToPulse(90-angle) ); //LHL
    pwm.setPWM(7, 0, angleToPulse(angle) ); //RHL
    delay(500);
}}

void turn_left(void)
{
  for(int angle=30;angle<=60;angle+=5)
  {
    pwm.setPWM(8, 0, angleToPulse(angle) );
    delay(100);
  }
  for(int angle=0;angle<=90;angle+=5)
  {
    pwm.setPWM(0, 0, angleToPulse(angle) );
    delay(100);
  }
  for(int angle=90;angle>=0;angle-=5)
  {
    pwm.setPWM(0, 0, angleToPulse(angle) );
    delay(100);
  }
  for(int angle=60;angle>=30;angle-=5)
  {
    pwm.setPWM(8, 0, angleToPulse(angle) );
    delay(100);
  }
  delay(500);
  for(int angle=130;angle<=160;angle+=5)
  {
    pwm.setPWM(11, 0, angleToPulse(angle) );
    delay(100);
  }
  for(int angle=90;angle>=0;angle-=5)
  {
    pwm.setPWM(3, 0, angleToPulse(angle) );
    delay(100);
  }
  for(int angle=0;angle<=90;angle+=5)
  {
    pwm.setPWM(3, 0, angleToPulse(angle) );
    delay(100);
  }
  for(int angle=160;angle>=130;angle-=5)
  {
    pwm.setPWM(11, 0, angleToPulse(angle) );
    delay(100);
  }
  delay(500);
  for(int angle=90;angle<=120;angle+=5)
  {
    pwm.setPWM(10, 0, angleToPulse(angle) );
    delay(100);
  }
  for(int angle=0;angle<=90;angle+=5)
  {
    pwm.setPWM(2, 0, angleToPulse(angle) );
    delay(100);
  }
  for(int angle=90;angle>=0;angle-=5)
  {
    pwm.setPWM(2, 0, angleToPulse(angle) );
    delay(100);
  }
  for(int angle=120;angle>=90;angle-=5)
  {
    pwm.setPWM(10, 0, angleToPulse(angle) );
    delay(100);
  }
  delay(500);
  for(int angle=30;angle<=60;angle+=5)
  {
    pwm.setPWM(9, 0, angleToPulse(angle) );
    delay(100);
  }
  for(int angle=90;angle>=0;angle-=5)
  {
    pwm.setPWM(1, 0, angleToPulse(angle) );
    delay(100);
  }
  for(int angle=0;angle<=90;angle+=5)
  {
    pwm.setPWM(1, 0, angleToPulse(angle) );
    delay(100);
  }
  for(int angle=60;angle>=30;angle-=5)
  {
    pwm.setPWM(9, 0, angleToPulse(angle) );
    delay(100);
  }
  delay(500);
}

void turn_right(void)
{
  for(int angle=30;angle>=0;angle-=5)
  {
    pwm.setPWM(9, 0, angleToPulse(angle) );
    delay(100);
  }
  for(int angle=90;angle>=0;angle-=5)
  {
    pwm.setPWM(1, 0, angleToPulse(angle) );
    delay(100);
  }
  for(int angle=0;angle<=90;angle+=5)
  {
    pwm.setPWM(1, 0, angleToPulse(angle) );
    delay(100);
  }
  for(int angle=0;angle<=30;angle+=5)
  {
    pwm.setPWM(9, 0, angleToPulse(angle) );
    delay(100);
  }
  delay(500);
  for(int angle=90;angle>=60;angle-=5)
  {
    pwm.setPWM(10, 0, angleToPulse(angle) );
    delay(100);
  }
  for(int angle=0;angle<=90;angle+=5)
  {
    pwm.setPWM(2, 0, angleToPulse(angle) );
    delay(100);
  }
  for(int angle=90;angle>=0;angle-=5)
  {
    pwm.setPWM(2, 0, angleToPulse(angle) );
    delay(100);
  }
  for(int angle=60;angle<=90;angle+=5)
  {
    pwm.setPWM(10, 0, angleToPulse(angle) );
    delay(100);
  }
  delay(500);
  for(int angle=130;angle>=100;angle-=5)
  {
    pwm.setPWM(11, 0, angleToPulse(angle) );
    delay(100);
  }
  for(int angle=90;angle>=0;angle-=5)
  {
    pwm.setPWM(3, 0, angleToPulse(angle) );
    delay(100);
  }
  for(int angle=0;angle<=90;angle+=5)
  {
    pwm.setPWM(3, 0, angleToPulse(angle) );
    delay(100);
  }
  for(int angle=100;angle<=130;angle+=5)
  {
    pwm.setPWM(11, 0, angleToPulse(angle) );
    delay(100);
  }
  delay(500);
  for(int angle=30;angle>=0;angle-=5)
  {
    pwm.setPWM(8, 0, angleToPulse(angle) );
    delay(100);
  }
  for(int angle=0;angle<=90;angle+=5)
  {
    pwm.setPWM(0, 0, angleToPulse(angle) );
    delay(100);
  }
  for(int angle=90;angle>=0;angle-=5)
  {
    pwm.setPWM(0, 0, angleToPulse(angle) );
    delay(100);
  }
  for(int angle=0;angle<=30;angle+=5)
  {
    pwm.setPWM(8, 0, angleToPulse(angle) );
    delay(100);
  }
  delay(500);
}

void crawl_forward(void)
{
  for(int angle=30;angle<=60;angle+=5)
  {
    pwm.setPWM(9, 0, angleToPulse(angle) );
    delay(100);
  }
  for(int angle=90;angle>=0;angle-=5)
  {
    pwm.setPWM(1, 0, angleToPulse(angle) );
    delay(100);
  }
  for(int angle=0;angle<=90;angle+=5)
  {
    pwm.setPWM(1, 0, angleToPulse(angle) );
    delay(100);
  }
  for(int angle=60;angle>=30;angle-=5)
  {
    pwm.setPWM(9, 0, angleToPulse(angle) );
    delay(100);
  }
  delay(500);
  for(int angle=130;angle>=100;angle-=5)
  {
    pwm.setPWM(11, 0, angleToPulse(angle) );
    delay(100);
  }
  for(int angle=90;angle>=0;angle-=5)
  {
    pwm.setPWM(3, 0, angleToPulse(angle) );
    delay(100);
  }
  for(int angle=0;angle<=90;angle+=5)
  {
    pwm.setPWM(3, 0, angleToPulse(angle) );
    delay(100);
  }
  for(int angle=100;angle<=130;angle+=5)
  {
    pwm.setPWM(11, 0, angleToPulse(angle) );
    delay(100);
  }
  delay(500);
  for(int angle=30;angle>=0;angle-=5)
  {
    pwm.setPWM(8, 0, angleToPulse(angle) );
    delay(100);
  }
  for(int angle=0;angle<=90;angle+=5)
  {
    pwm.setPWM(0, 0, angleToPulse(angle) );
    delay(100);
  }
  for(int angle=90;angle>=0;angle-=5)
  {
    pwm.setPWM(0, 0, angleToPulse(angle) );
    delay(100);
  }
  for(int angle=0;angle<=30;angle+=5)
  {
    pwm.setPWM(8, 0, angleToPulse(angle) );
    delay(100);
  }
  delay(500);
  for(int angle=90;angle<=120;angle+=5)
  {
    pwm.setPWM(10, 0, angleToPulse(angle) );
    delay(100);
  }
  for(int angle=0;angle<=90;angle+=5)
  {
    pwm.setPWM(2, 0, angleToPulse(angle) );
    delay(100);
  }
  for(int angle=90;angle>=0;angle-=5)
  {
    pwm.setPWM(2, 0, angleToPulse(angle) );
    delay(100);
  }
  for(int angle=120;angle>=90;angle-=5)
  {
    pwm.setPWM(10, 0, angleToPulse(angle) );
    delay(100);
  }
  delay(500);
}

void loop() {

  initialize();
  delay(5000);
  stand();
  delay(5000);
  sit()
  delay(5000);
  turn_right();
  delay(5000);
  turn_left();
  delay(5000);
  crawl_forward();
  //crawl_forward();
  delay(5000);
}

/*
 * angleToPulse(int ang)
 * gets angle in degree and returns the pulse width
 * also prints the value on seial monitor*/
