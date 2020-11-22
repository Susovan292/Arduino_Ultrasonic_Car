/*
This beautiful code is created by Susovan das on 8th july 2020 for those people who wanted to make a ultra sonic car using Arduino And HC SR04 Ultra Sonic Sensor.
*/
#include <servo.h>//we need servo library
#define TriggerPin  5 //define_Trigger___________Pin
#define EchoPin     4 //define_Echo______________Pin
#define m1p1       10 //define_right_motor_+ve___Pin
#define m1p2        9 //define_right_motor_-ve___Pin
#define m2p1        8 //define_left__motor +ve___pin
#define m2p2        7 //define_left__motor_-ve___pin
#define m1s        11 //define_right_motor_speed_Pin
#define m2s         6 //define_left__motor_speed_Pin
#define myServoPin  3 //define_servo_____________Pin
#define frontpos   85 //defining_servo_front__degree
#define leftpos   180 //defining_servo_left___degree
#define rightpos    0 //defining_servo_right__degree
#define dt        350 //defining__________delay_Time
Servo myservo;
float frontdistance;
float leftdistance;
float rightdistance;
float frontduration;
float leftduration;
float rightduration;

void setup(){
  
    myservo.attach(myServoPin);
    pinMode(m1p1,OUTPUT);
    pinMode(m1p2,OUTPUT);
    pinMode(m2p1,OUTPUT);
    pinMode(m2p2,OUTPUT);
    pinMode(m1s ,OUTPUT);
    pinMode(m2s ,OUTPUT);
    pinMode(TriggerPin,OUTPUT);
    pinMode(EchoPin,INPUT);
    
}

void loop(){
  //front distance
  myservo.write(frontpos);
  delay(10);
  digitalWrite(TriggerPin,LOW);
  delayMicroseconds(2);
  digitalWrite(TriggerPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(TriggerPin,LOW);
  frontduration=pulseIn(EchoPin,HIGH);
  frontdistance=frontduration*0.0343/2; 
  if(frontdistance<=5){frontdistance=0;}
  delay(dt-100);
    
 while(frontdistance>50 ){
 forwardspd3();
 //front distance       
 
 digitalWrite(TriggerPin,LOW);
 delayMicroseconds(2);
 digitalWrite(TriggerPin,HIGH);
 delayMicroseconds(10);
 digitalWrite(TriggerPin,LOW); 
 frontduration=pulseIn(EchoPin,HIGH);
 frontdistance=frontduration*0.0343/2;
 if(frontdistance<=5){frontdistance=0;}  
 delay(1);}   
    
while(frontdistance>40 ){
 forwardspd2();
 //front distance       
  
 digitalWrite(TriggerPin,LOW);
 delayMicroseconds(2);
 digitalWrite(TriggerPin,HIGH);
 delayMicroseconds(10);
 digitalWrite(TriggerPin,LOW); 
 frontduration=pulseIn(EchoPin,HIGH);
 frontdistance=frontduration*0.0343/2;
 if(frontdistance<=5){frontdistance=0;}  
 delay(1);}

 while(frontdistance>30 ){
 forwardspd1();
 //front distance       

 digitalWrite(TriggerPin,LOW);
 delayMicroseconds(2);
 digitalWrite(TriggerPin,HIGH);
 delayMicroseconds(10);
 digitalWrite(TriggerPin,LOW); 
 frontduration=pulseIn(EchoPin,HIGH);
 frontdistance=frontduration*0.0343/2;
 if(frontdistance<=5){frontdistance=0;}  
 delay(1);}
    
    
 while(frontdistance<=25 ){
        stop();
        delay(250);
        backward();
        delay(700);
         //front distance       
    myservo.write(frontpos);
    digitalWrite(TriggerPin,LOW);
    delayMicroseconds(2);
    digitalWrite(TriggerPin,HIGH);
    delayMicroseconds(10);
    digitalWrite(TriggerPin,LOW); 
    frontduration=pulseIn(EchoPin,HIGH);
    frontdistance=frontduration*0.0343/2;
    if(frontdistance<=5){frontdistance=0;}
    delay(10);
        }
  stop();   
        //right distance       
  myservo.write(rightpos);   
  delay(250);
  digitalWrite(TriggerPin,LOW);
  delayMicroseconds(2);
  digitalWrite(TriggerPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(TriggerPin,LOW); 
  rightduration=pulseIn(EchoPin,HIGH);
  rightdistance=rightduration*0.0343/2;
  delay(dt-100);
    
    
           myservo.write(frontpos);
    
               delay(100);    

    //left distance      
    
    myservo.write(leftpos);  
    delay(250); 
    digitalWrite(TriggerPin,LOW);
    delayMicroseconds(2);
    digitalWrite(TriggerPin,HIGH);
    delayMicroseconds(10);
    digitalWrite(TriggerPin,LOW); 
    leftduration=pulseIn(EchoPin,HIGH);
    leftdistance=leftduration*0.0343/2;
    delay(dt-100);
    myservo.write(frontpos);
    delay(100);   
            
     if(leftdistance<rightdistance){  right();
                                      delay(600);
                                   }
else if(leftdistance>rightdistance){  left();
                                      delay(600);
                                   }
           }

void forwardspd1(){//forward first  speed
    analogWrite (m1s , 160);
    analogWrite (m2s , 160);
    digitalWrite(m1p1, LOW);
    digitalWrite(m1p2,HIGH);
    digitalWrite(m2p1, LOW);
    digitalWrite(m2p2,HIGH);
}
void forwardspd2(){//forward second speed
    analogWrite (m1s , 200);
    analogWrite (m2s , 200);
    digitalWrite(m1p1, LOW);
    digitalWrite(m1p2,HIGH);
    digitalWrite(m2p1, LOW);
    digitalWrite(m2p2,HIGH);
}
void forwardspd3(){//forward third  speed
    analogWrite (m1s , 255);
    analogWrite (m2s , 255);
    digitalWrite(m1p1, LOW);
    digitalWrite(m1p2,HIGH);
    digitalWrite(m2p1, LOW);
    digitalWrite(m2p2,HIGH);
}
void backward(){
    analogWrite (m1s , 200);
    analogWrite (m2s , 200);
    digitalWrite(m1p1,HIGH);
    digitalWrite(m1p2, LOW);
    digitalWrite(m2p1,HIGH);
    digitalWrite(m2p2, LOW);
}
void left(){
    analogWrite (m1s , 255);
    analogWrite (m2s , 255);
    digitalWrite(m1p1, LOW);
    digitalWrite(m1p2,HIGH);
    digitalWrite(m2p1,HIGH);
    digitalWrite(m2p2, LOW);
}
void right(){
    analogWrite (m1s , 255);
    analogWrite (m2s , 255);
    digitalWrite(m1p1,HIGH);
    digitalWrite(m1p2, LOW);
    digitalWrite(m2p1, LOW);
    digitalWrite(m2p2,HIGH);
    
    }
void stop(){
    analogWrite (m1s , 0 );
    analogWrite (m2s , 0 );
    digitalWrite(m1p1,LOW);
    digitalWrite(m1p2,LOW);
    digitalWrite(m2p1,LOW);
    digitalWrite(m2p2,LOW);
}
