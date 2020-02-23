const int trigger = 7, echo = 6, led1 = 5, led2 = 4, led3 = 3, led4 = 2, ldrpin = A0;
long duration, distance;
int count=0;
int f=0;
void setup() {
   pinMode(echo, INPUT);  
   pinMode(ldrpin, INPUT); 
   pinMode(trigger, OUTPUT);
   Serial.begin(9600); 
   pinMode(led1, OUTPUT);
   pinMode(led2, OUTPUT);
   pinMode(led3, OUTPUT);
   pinMode(led4, OUTPUT);
}

void loop() {
  if(ldr()<=450){
   checkultrasonic();
   if (distance<30){
    trigled();
    f=1;
   }
   delay(100);
  }
  else if (f==1){
    Serial.println(count);
    delay(20000 );
    count=0;
    
  }
}

void trigled(){
  start:
  if(ldr()<=450)
  {
  count++;
  analogWrite(led1, 255);
  analogWrite(led2, 255);
  analogWrite(led3, 255);
  analogWrite(led4, 255);
  delay(2000); 
  checkultrasonic();
  if (distance<30 || ldr()>450){
    goto start;
  } 
  digitalWrite(led1, LOW);
  delay(2000);
  checkultrasonic();
  if (distance<30 || ldr()>450){
    goto start;
  }
  digitalWrite(led2, LOW);
  delay(2000);
  checkultrasonic();
  if (distance<30 || ldr()>450){ 
    goto start;
  }
  digitalWrite(led3, LOW);
  delay(2000);
  checkultrasonic();
  if (distance<30 || ldr()>450){
    goto start;
  }
  digitalWrite(led4, LOW);
  }
  else{
   digitalWrite(led1, LOW); 
   digitalWrite(led2, LOW);
   digitalWrite(led3, LOW);
   digitalWrite(led4, LOW);  }
}
void checkultrasonic(){
     digitalWrite(trigger, LOW);
   delayMicroseconds(5);
   digitalWrite(trigger, HIGH);
   delayMicroseconds(10);
   digitalWrite(trigger, LOW);
   duration = pulseIn(echo, HIGH);
   distance = duration*0.034/2;
}
int ldr(){
  return analogRead(ldrpin);
}
