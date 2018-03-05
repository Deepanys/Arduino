#include <SPI.h>
byte Input, Output, Check=1;
int j;
void setup(){
  pinMode(13, OUTPUT);//clock
  pinMode(11, OUTPUT);//data
  pinMode(4, OUTPUT);//latch
  pinMode(2, INPUT);//Input from buttons


  
  
SPI.setBitOrder(MSBFIRST);
SPI.setDataMode(SPI_MODE0);
SPI.setClockDivider(SPI_CLOCK_DIV2);
SPI.begin();
 
  //SPI.transfer(0);
   //SPI.transfer(0);
  
 // digitalWrite(4, HIGH);
 // digitalWrite(4, LOW);
 // Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
  SPI.transfer(0);
   SPI.transfer(0);
  
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
  delay(100);
  SPI.transfer(0);
   SPI.transfer(0);
  
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);

}
