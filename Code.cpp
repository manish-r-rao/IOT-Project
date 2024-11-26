#include "Servo.h";
Servo myservo;
Servo servoLdr;
int pos=0;
int posLdr=0;
void setup()
{
Serial.begin(9600);
myservo.attach(7);
servoLdr.attach(8);
}
void loop()
{
int s;
posLdr=0;
servoLdr.write(posLdr);
delay(1000);
s=analogRead(A0);
Serial.println(s);
if(s>250 && pos==0)
{
myservo.write(100);
delay(5000);
pos=1;
posLdr=90;
myservo.write(90);
servoLdr.write(posLdr);
}
else if(s<=250 && pos==1) {
myservo.write(70);
delay(5000);
pos=0;
posLdr=0;
myservo.write(90);
servoLdr.write(posLdr);
}
delay(10000)