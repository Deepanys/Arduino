/*  Receiver Code 
*   Code to receive data from RF24L01+ and use it to control a servo */

#include <SPI.h>
#include <RF24.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x3F, 16, 2);



// Motor driver pins
//const int STBY_PIN = 9;
const int AIN1_PIN = 3;
const int AIN2_PIN = 4;
const int APWM_PIN = 5;
const int BIN1_PIN = 7;
const int BIN2_PIN = 8;
const int BPWM_PIN = 6;

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

void setup() { 

  //  pinMode(STBY_PIN, OUTPUT);
  pinMode(AIN1_PIN, OUTPUT);
  pinMode(AIN2_PIN, OUTPUT);
  pinMode(APWM_PIN, OUTPUT);
  pinMode(BIN1_PIN, OUTPUT);
  pinMode(BIN2_PIN, OUTPUT);
  pinMode(BPWM_PIN, OUTPUT);
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
}
void loop() {
       
    radio.startListening();//increase for debuggy, decrease to decrease jitter
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
           output[0]=0;
           output[1]=0;
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
  int y = output[0];
  int x = output[1];

  // Convert to PWM value (-255 to 255)
  y = (pulseToPWM(y))+10;
  x = (pulseToPWM(x))+8;
Serial.print(" y == ");
Serial.println(y);
Serial.print(" x == ");
Serial.println(x);

  // Mix for arcade drive
  int left = y + x;
  int right = y - x;

  // Drive motor
  drive(left, right);
  radio.stopListening();
    delay(10);
   
    }


    
// Positive for forward, negative for reverse
void drive(int speed_a, int speed_b) {

  // Limit speed between -255 and 255
  speed_a = (constrain(speed_a, -255, 255));
  speed_b = constrain(speed_b, -255, 255);

  // Set direction for motor A
  if ( speed_a < 40) {
    digitalWrite(AIN1_PIN,0 );
    digitalWrite(AIN2_PIN, LOW);
  } else if ( speed_a > 40 ) {
    digitalWrite(AIN1_PIN, HIGH);
    digitalWrite(AIN2_PIN, LOW);
  } 
  if (speed_a < -20)
  {
    digitalWrite(AIN1_PIN, LOW);
    digitalWrite(AIN2_PIN, HIGH);
  }

  // Set direction for motor B
  if ( speed_b <40 ) {
    digitalWrite(BIN1_PIN, LOW);
    digitalWrite(BIN2_PIN, LOW);
  } else if ( speed_b > 40 ) {
    digitalWrite(BIN1_PIN, HIGH);
    digitalWrite(BIN2_PIN, LOW);
  }
  if (speed_b < -20){
    digitalWrite(BIN1_PIN, LOW);
    digitalWrite(BIN2_PIN, HIGH);
  }

  // Set speed
  analogWrite(APWM_PIN, abs(speed_a));
  analogWrite(BPWM_PIN, abs(speed_b));

  
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
Serial.println(abs(speed_a));
Serial.print(" speed b == ");
Serial.println(abs(speed_b));
}

// Convert RC pulse value to motor PWM value
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
}
