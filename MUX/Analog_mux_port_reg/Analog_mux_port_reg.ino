/*  Arduino sketch   */

int64_t wait= 1000;
void setup() 
{
  pinMode(7,OUTPUT);
  digitalWrite(7,LOW);
  DDRB = 0b00000111;  //PORT 8,9,10 as output
  PORTB = 0b00000000; //PORT 8,9,10 set to LOW
}

void loop() 
{
  PORTB=0b00000000; //Data falow - X0
  uint8_t Sensor0 =  analogRead(A0); //read data from X0
  delay(wait);
 
  PORTB=0b00000001;  //Data flow - X1
  uint8_t Sensor1 =  analogRead(A0); //read data from X1
  delay(wait);
  
  PORTB=0b00000010;  //Data flow - X2
  uint8_t Sensor2 =  analogRead(A0); //read data from X2
  delay(wait);
  
  digitalWrite(7,HIGH);  // Inhibit / stop all data
  delay(wait);  
  digitalWrite(7,LOW);  // Inhibit /  let data flow
}
