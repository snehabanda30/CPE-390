#define button1 1
#define button2 9
#define LED1 1
#define LED2 9 
void setup() {
  // put your setup code here, to run once:
  pinMode(button1, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(button2, INPUT);
  pinMode (LED2, OUTPUT); 

}

void loop() {
  // put your main code here, to run repeatedly:
  int u = digitalRead(button1);
  int v = digitalRead(button2);
  delay(200);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  delay(200);
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);

}
