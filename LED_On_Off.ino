int LED=8;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(LED,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available()){
  char a=Serial.read();
  Serial.println(a);
  if(a=='a'){
  digitalWrite(LED,HIGH);
  }
  else if(a=='b')
  {
  digitalWrite(LED,LOW);
  }
}
}
