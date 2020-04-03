#define A1 D9 //moter A 
#define A2 D6 //moter A 
#define B1 D5 //moter B
#define B2 D3 //moter B 

#define leftsensor D12 //sensorซ้าย
#define rightsensor D4 //sensorขวา
#define backsensor D10 //sensorหลัง

#define RED 1
#define YELLOW 2
#define BLACK 3
#define NOCOLOR 0
#define maxSpd 255    // motor max speed

#include <HCSR04.h>
HCSR04 hc(D7,D8); 

int analogPin = A7; 

int led = D13;
int switchPin = D11;
int val=0;
int old_val=0;
int state=0;

int color=0;
int getColor() {
  int NO_color = analogRead(analogPin);            
  if ((NO_color>2500)&&(NO_color<2900))       
    return YELLOW ;
  else if ((NO_color>3000)&&(NO_color<3500))  
    return RED ;
  else if ((NO_color>3600)&&(NO_color<3900))  
    return BLACK;
  else                                        
    return NOCOLOR;
}

void setup() {
  
  pinMode(leftsensor, INPUT);
  pinMode(rightsensor, INPUT);
  pinMode(switchPin, INPUT);
  pinMode(led, OUTPUT); 
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(B1, OUTPUT);
  pinMode(B2, OUTPUT);
  Serial.begin(115200);
}

void loop() 
{ 
 color = getColor();
 val = digitalRead(switchPin);
 if( (val==HIGH) && (old_val==LOW)) 
 {
  state=!state;
 }
 old_val=val;
 if (state==1) //เมื่อกดสวิทซ์ 1 ครั้ง ใช้กลยุทธ์รุก
 {
  digitalWrite(led, HIGH);
  if((hc.dist()>10)&&((digitalRead(leftsensor)==HIGH)||(digitalRead(rightsensor)==HIGH))&&(color == NOCOLOR))  // เดินหน้า
  {
  MotorAForward(maxSpd);
  MotorBForward(maxSpd);
  }
  
  if((hc.dist()<10)&&((digitalRead(leftsensor)==HIGH)||(digitalRead(rightsensor)==HIGH))&&(digitalRead(backsensor) == LOW)&&(color == NOCOLOR))  // หยุด 
  {
  MotorABreakTime(500);
  MotorBBreakTime(500); 
  }

  if((hc.dist()<10)&&((digitalRead(leftsensor)==LOW)||(digitalRead(rightsensor)==LOW))&&(digitalRead(backsensor) == HIGH)&&(color == NOCOLOR))  // เดินถอยหลัง 
  {
  MotorARewardTime(3000);
  MotorBRewardTime(3000);
  }
   if(color == YELLOW)  // รถหยุด 
  {
  MotorAStop();
  MotorBStop();
  }
  if(color == RED)  // กลับรถ 
  {
  MotorAForwardTime(3000);
  MotorBRewardTime(3000);
  }

 }
 else
 {
  digitalWrite (led,LOW);
  if((hc.dist()>5)&&((digitalRead(leftsensor)==HIGH)||(digitalRead(rightsensor)==HIGH))&&(color == NOCOLOR))  // ถอยหลัง
  {
  MotorAReward(maxSpd);
  MotorBReward(maxSpd);
  }

   if((hc.dist()<5)&&((digitalRead(leftsensor)==HIGH)||(digitalRead(rightsensor)==HIGH))&&(color == NOCOLOR)) // เดินหน้า
  {
  MotorAForwardTime(3000);
  MotorBForwardTime(3000);
  }
  
  if((digitalRead(leftsensor)==LOW)||(digitalRead(rightsensor)==LOW)&&(color == NOCOLOR))  // หยุด 
  {
  MotorABreakTime(500);
  MotorBBreakTime(500); 
  } 
    
  if(color == BLACK)  // กลับรถ 
  {
  MotorAForwardTime(5000);
  MotorBRewardTime(5000);
  }
  
  }
  delay(20);
       
}

void MotorAStop()
{
  digitalWrite(A1, LOW);   
  digitalWrite(A2, LOW);    
}

void MotorABreak()
{
  digitalWrite(A1, HIGH);   
  digitalWrite(A2, HIGH);    
}

void MotorBStop()
{
  digitalWrite(B1, LOW);   
  digitalWrite(B2, LOW);    
}

void MotorBBreak()
{
  digitalWrite(B1, HIGH);   
  digitalWrite(B2, HIGH);    
}

void MotorAForward(int speed)
{
  digitalWrite(A2, LOW);   
  analogWrite(A1, speed);   
}

void MotorBForward(int speed)
{
  digitalWrite(B2, LOW);   
  analogWrite(B1, speed);   
}

void MotorAReward(int speed)
{
  digitalWrite(A1, LOW);   
  analogWrite(A2, speed);   
}

void MotorBReward(int speed)
{
  digitalWrite(B1, LOW);   
  analogWrite(B2, speed);   
}

void MotorARewardTime(int time)
{
  digitalWrite(A1, LOW);   
  analogWrite(A2, maxSpd);
  delay (time);   
}

void MotorBRewardTime(int time)
{
  digitalWrite(B1, LOW);   
  analogWrite(B2, maxSpd);
  delay (time);    
}

void MotorAForwardTime(int time)
{
  digitalWrite(A2, LOW);   
  analogWrite(A1, maxSpd);
  delay (time);    
}

void MotorBForwardTime(int time)
{
  digitalWrite(B2, LOW);   
  analogWrite(B1, maxSpd);
  delay (time);    
}

void MotorABreakTime(int time)
{
  digitalWrite(A1, HIGH);   
  digitalWrite(A2, HIGH);
  delay (time);    
}

void MotorBBreakTime(int time)
{
  digitalWrite(B1, HIGH);   
  digitalWrite(B2, HIGH);
  delay (time);
      
}
