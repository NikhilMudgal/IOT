float data;
void setup() {
Serial.begin(9600);
}

void loop() {
data=analogRead(A0);
float V=(data*5)/1024;
float milv=V*1000;
float C=milv/10;
float F=(C*9/5)+32;
float K=C+273;
Serial.println(C);
/*Serial.print(F);
Serial.print("F   ");
Serial.print(K);
Serial.println("K    ");*/
delay(1000);
}
