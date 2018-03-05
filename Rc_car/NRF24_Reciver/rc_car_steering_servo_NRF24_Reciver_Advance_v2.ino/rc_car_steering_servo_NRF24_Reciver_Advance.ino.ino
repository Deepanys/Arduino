/*  Receiver Code 
*   Code to receive data from RF24L01+ and use it to control a servo */

#include <SPI.h>
#include <RF24.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <IRremote.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x3F, 16, 2);



// Motor driver pins
//const int STBY_PIN = 9;
Servo steer;
const int AIN1_PIN = 2;
const int AIN2_PIN = 4;

const int BIN1_PIN = 7;
const int BIN2_PIN = 8;
const int BPWM_PIN = 6;

unsigned long previousMillis = 0;        // will store last time LED was updated

// constants won't change:
const long interval = 1000;      

int x = 0;
int y = 0;

// Parameters
const int deadzone = 20;  // Anything between -20 and 20 is stop

//Radio Configuration

bool radioNumber=0;
RF24 radio(9,10);
byte addresses[][6] = {"1Node","2Node"};
bool role = 0;  //Control transmit/receive

// Create variables to control servo value


 unsigned int ForeAft_Output;       // Expected range 0 - 180 degrees
 unsigned int LeftRight_Output;     // Expected range 0 - 180 degrees
 int output[2];
int RECV_PIN=5;
int speed=255;
int recdata=0;
IRrecv irrecv(5);
decode_results results;
void setup() { 

  //  pinMode(STBY_PIN, OUTPUT);
  pinMode(AIN1_PIN, OUTPUT);
  pinMode(AIN2_PIN, OUTPUT);
 
  pinMode(BIN1_PIN, OUTPUT);
  pinMode(BIN2_PIN, OUTPUT);
  pinMode(BPWM_PIN, OUTPUT);
  steer.attach(3);
  lcd.begin();

  // Enable motor driver
 // digitalWrite(STBY_PIN, HIGH); 
  
    Serial.begin(9600);        // Get ready to send data back for debugging purposes
    radio.begin();             // Initialize radio
    //radio.setPALevel(RF24_PA_LOW);    // Set the power output to low
      radio.setChannel(108);  // 2.508 Ghz - Above most Wifi Channels
  radio.setDataRate(RF24_250KBPS); // Fast enough.. Better range

  // Set the Power Amplifier Level low to prevent power supply related issues since this is a
  // getting_started sketch, and the likelihood of close proximity of the devices. RF24_PA_MAX is default.
  // PALevelcan be one of four levels: RF24_PA_MIN, RF24_PA_LOW, RF24_PA_HIGH and RF24_PA_MAX
  radio.setPALevel(RF24_PA_LOW);
  //   radio.setPALevel(RF24_PA_MAX);
   // radio.openWritingPipe(addresses[0]);
    radio.openReadingPipe(role,addresses[1]);
    radio.startListening();
     Serial.begin(9600);
    irrecv.enableIRIn();
    
   
}
void loop() {
       if(irrecv.decode(&results)){
Serial.print(results.value,HEX);
recdata=results.value;
if(recdata==255)
{
  Serial.print("\t speed==");
  Serial.println(255);
  speed=recdata;
}
if (speed==200)
{
  Serial.print("\t speed==");
  Serial.println(200);
  speed=recdata;
}
if (speed==150)
{
  Serial.print("\t speed==");
  Serial.println(150);
  speed=recdata;
}if (speed==100)
{
  Serial.print("\t speed==");
  Serial.println(100);
  speed=recdata;
}
delay(40);
irrecv.resume();
}
   // radio.startListening();
    if(radio.available()){
      lcd.setCursor(1,0);
           lcd.print("Radio");
        radio.read(&output,sizeof(output));
        //radio.read(&LeftRight_Output,sizeof(LeftRight_Output));
        } else {
          
          Serial.print("No radio");
          lcd.clear();
           lcd.setCursor(1,0);
           lcd.print("NO radio");
            
              y = 0;
              x = 84;
            goto nosignal;

    }
    /*
     lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("X=");
  lcd.setCursor(3,0);
  lcd.print(output[0]);
  lcd.setCursor(0,1);
  lcd.print("Y=");
  lcd.setCursor(3,1);
  lcd.print(output[1]);
*/
  //  Serial.print(ForeAft_Output);
   // Serial.print("\t");
   //  Serial.println(LeftRight_Output);
/******************************************************/


  // Read pulse width from receiver
 // int y = output[0];
 // int x = output[1];

  // Convert to PWM value (-255 to 255)
   y = (map(output[0], 0, 1023, -speed, speed))+10;
   x = (map(output[1], 0, 1023, 70, 97))+1;
//Serial.print(" y == ");
//Serial.println(y);
//Serial.print(" x == ");
//Serial.println(x);
 
 nosignal:

  // Mix for arcade drive
  int left = y;
  int right = x;

  // Drive motor
  drive(left, right);
  //radio.stopListening();
    delay(20);
   
    }


    
// Positive for forward, negative for reverse
void drive(int speed_a, int speed_b) {

  // Limit speed between -255 and 255
  speed_a = constrain(speed_a, -255, 255);
  speed_b = constrain(speed_b, 70, 97);

  // Set direction for motor A
  if ( speed_a == 0) {
    digitalWrite(2,0 );
    digitalWrite(4, LOW);
    analogWrite(6, 0);
  
  }
  
  if ( speed_a > 10 ) {
    digitalWrite(AIN1_PIN, HIGH);
    digitalWrite(4, LOW);
      analogWrite(6,abs(speed_a));

  } 
  if (speed_a < -10)
  {
    digitalWrite(AIN1_PIN, LOW);
    digitalWrite(4, HIGH);
    analogWrite(6, abs(speed_a));

  }

 


   steer.write(abs(speed_b));

//  steer.write(speed_b);
  /*// Set direction for motor B
  if ( speed_b ==0) {
    
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
      analogWrite(5, 0);

  } else if ( speed_b > 10 ) {
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
    analogWrite(5, abs(speed_b));

  }
  if (speed_b < -10){
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
      analogWrite(5, abs(speed_b));

  }*/

  // Set speed
//  analogWrite(BPWM_PIN, abs(speed_b));

  
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print("SpeedA=");
  lcd.setCursor(7,1);
  lcd.print((speed_a));
  lcd.setCursor(11,1);
  lcd.print("B=");
  lcd.setCursor(12,1);
  lcd.print((speed_b));

  
Serial.print(" speed a == ");
Serial.print(abs(speed_a));
Serial.print("\t");
Serial.print(" speed b == ");
Serial.println(abs(speed_b));

}

/*/ Convert RC pulse value to motor PWM value
int pulseToPWM(int pulse) {
  
  // If we're receiving numbers, convert them to motor PWM
 // if ( pulse > 1000 ) {
    pulse = map(pulse, 0, 1023, -255, 255);
    pulse = constrain(pulse, -255, 255);
 // } else {
 //   pulse = 0;
//  }

  // Anything in deadzone should stop the motor
 // if ( abs(pulse) <= deadzone ) {
 //   pulse = 0;
 // }

  return pulse;
}*/
