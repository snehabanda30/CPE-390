
void setup() {
  // put your setup code here, to run once:
  pinMode (10,OUTPUT);
  Serial.begin(9600);

}
void loop() {
  unsigned long duration;
  digitalWrite(10, HIGH);
  // put your main code here, to run repeatedly:
  // 11.5 cm length between two photogates 
  int voltage1=analogRead(A1);
  int voltage2=analogRead(A2); // what

  //Serial.println(voltage2);

  while(analogRead(A1) > 700 )
  {
    //Serial.print("voltage1"); 
   // Serial.println(voltage1);  

  }
 // delay(1000); 
  //Serial.print("exitt");
  
    duration = millis();
  while( analogRead(A2) > 500){
    //Serial.print("voltage2"); 

    //Serial.println(voltage2); 

  }
    duration = (millis()-duration)/1000;
  

 // while (voltage2 > 35) {}
  //duration = micros() - duration;

    unsigned long velocity = 11.5/duration;
    Serial.print("Velocity: ");
    Serial.println(velocity);
    Serial.print("Duration: ");
    Serial.println(duration);

  





/*while(voltage1 > 650)


  if (voltage1<=650) 
  {
    delay(500);
    //Serial.println ("BLOCKED");
  }
  else(voltage2==35);
  {
    delay(500);
    //duration = micros - duration;
  }
  duration = micros - duration;*/
  

  
}
