char m;
int LED=10;
void setup() {
  // put your setup code here, to run once:
pinMode(LED,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available()){
  m=Serial.read();
  Serial.println(m);
}  if(m=='a'){
    digitalWrite(LED,HIGH);
    delay(5);
    digitalWrite(LED,LOW);
    delay(15);
  }
 else if(m=='b'){
    digitalWrite(LED,HIGH);
    delay(10);
    digitalWrite(LED,LOW);
    delay(10);
  }
 else if(m=='c'){
    digitalWrite(LED,HIGH);
    delay(15);
    digitalWrite(LED,LOW);
    delay(5);
  }
 else if(m=='d'){
    digitalWrite(LED,HIGH);
    delay(20);
    digitalWrite(LED,LOW);    
  }
else
digitalWrite(LED,LOW);
}
