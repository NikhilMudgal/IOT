int led=12;
int led1=10;
int led2=8;
int led3=7;
void setup() {
  // put your setup code here, to run once:
pinMode(led,OUTPUT);
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(led3,OUTPUT);
Serial.begin(9600);
}
void set()
{
  digitalWrite(led,LOW);
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);
}
void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available())
{ 
 char data=Serial.read();
 if(data=='1'){
  set(); 
  digitalWrite(led,HIGH);
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);
 }
 else if(data=='2')
 {
  set();
  digitalWrite(led,LOW);
  digitalWrite(led1,HIGH);
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);
 }
 else if(data=='3')
 {
  set();
  digitalWrite(led,LOW);
  digitalWrite(led1,LOW);
  digitalWrite(led2,HIGH);
  digitalWrite(led3,LOW);
 }
 else if(data=='4')
 {
  set();
  digitalWrite(led,LOW);
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  digitalWrite(led3,HIGH);
 }
 
 else if(data=='0')
 set();
 
}
}


