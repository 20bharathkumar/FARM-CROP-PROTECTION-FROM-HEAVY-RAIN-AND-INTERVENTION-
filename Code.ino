int count = 0;
int rain = A0;
int motor1_forward = 3;
int motor1_reverse = 5;
int motor2_forward = 6;
int motor2_reverse = 9;
int led = 7;
int switch1 = 2;
int buzz = 8;
int switch2 = 10;
int trig1 = 11;
int echo1 = 12;
int pump = 13;
int pump1 = 4;
int fire = A2;
int m_s = A1;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
pinMode(motor1_forward, OUTPUT);
pinMode(motor1_reverse, OUTPUT);
pinMode(motor2_forward, OUTPUT);
pinMode(motor2_reverse, OUTPUT);
pinMode(switch1, INPUT);
pinMode(rain, INPUT);
pinMode(switch2, INPUT);
pinMode(led, OUTPUT);
pinMode(trig1, OUTPUT);
pinMode(echo1, INPUT);
pinMode(pump, OUTPUT);
pinMode(pump1, OUTPUT);
pinMode(buzz, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int rs = digitalRead(rain);
  int s1 = digitalRead(switch1);
  int s2 = digitalRead(switch2);
  int ms = digitalRead(m_s);
  int fs = digitalRead(fire);
  Serial.println("moisture");
  Serial.println(ms);
  Serial.println("rain sensor");
  Serial.println(rs);


  
if(rs == 0)
{
{
count=count+1;
}
switch(count)
{
  case 1:
 // Serial.println("rain has detected, covering sheets on crops");
  forward();
  delay(200);
  case 2:
  stop();
}}
if(s1 == 1)
{
  //Serial.println("rain has stoped, taking sheets off from crops");
reverse();
delay(100);
}
else
{
  stop();
}
//ultra sonic sensor
if(s2 == 1)
{
  long duration1;
int distance1;
digitalWrite(trig1, HIGH);
delayMicroseconds(1000);
digitalWrite(trig1, LOW);
duration1 = pulseIn(echo1, HIGH);
distance1 = duration1*0.034/2;
Serial.println("distance");
Serial.println(distance1);
delay(10);

if (distance1 < 19)
{
  //Serial.println("farm is breached by an animal"); 
  digitalWrite(led, 1);
  
  
}
else
{
  
  digitalWrite(led, 0);
}
}
//sensing moisture and turning on the water pump
if(ms == 1)
{
  //Serial.println("soil maisture is low turning on the pump");
  digitalWrite(pump, 1);
  
}
else
{
  digitalWrite(pump, 0);
  
}
//fire sensor
if (fs == 0)
{
  Serial.println("fire");
  Serial.println(fs);
  digitalWrite(pump1, 1);
  digitalWrite(buzz, 1);
}
else
{
  digitalWrite(pump1, 0);
  digitalWrite(buzz, 0);
}
}
void forward()
{
  analogWrite(motor1_forward, 50);
  digitalWrite(motor1_reverse, 0);
  analogWrite(motor2_forward, 50);
  digitalWrite(motor2_reverse, 0); 
  
}
void reverse()
{
  analogWrite(motor1_forward, 0);
  digitalWrite(motor1_reverse, 50);
  analogWrite(motor2_forward,0);
  digitalWrite(motor2_reverse, 50); 
  
}
void stop()
{
  digitalWrite(motor1_forward, 0);
  digitalWrite(motor1_reverse, 0);
  digitalWrite(motor2_forward, 0);
  digitalWrite(motor2_reverse, 0);
}
