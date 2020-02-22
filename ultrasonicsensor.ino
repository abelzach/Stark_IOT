const int trigger = 7; 
const int echo = 6; 
long duration, distance;
bool check;
void setup() {
   pinMode(echo, INPUT);   
   pinMode(trigger, OUTPUT);
   Serial.begin(9600); 
}

void loop() {

   digitalWrite(trigger, LOW);
   delayMicroseconds(5);
   digitalWrite(trigger, HIGH);
   delayMicroseconds(10);
   digitalWrite(trigger, LOW);
   duration = pulseIn(echo, HIGH);
   distance = duration*0.034/2;
   Serial.print(distance);
   Serial.print("cm");
   if (distance<30){
   check=true;
   }
   else{
   check=false;
   }
   Serial.print(check);
   Serial.println();
   delay(100);
}
