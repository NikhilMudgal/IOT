int data;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(11,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
data=analogRead(A0);
Serial.println(data);
if(data>950){
  analogWrite(11,255);
}
else if(data>945&&data<=950){
    analogWrite(11,191);
  }
else if(data>930&&data<=945)
{
  analogWrite(11,127);  
}
else if(data>910&&data<=930)
{
  analogWrite(11,64);
}
else if(data<=910)
{
  analogWrite(11,0);
}
delay(1000);
}
