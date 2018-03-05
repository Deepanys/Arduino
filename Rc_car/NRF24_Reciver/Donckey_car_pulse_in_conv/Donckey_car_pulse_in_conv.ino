#include<Servo.h>
Servo steer;

const int CH_1_PIN = 9;
const int CH_2_PIN = 10;
const int servo = 11 ;
 
const int deadzone = 20;
const int pwm = 6;
const int a1 = 7;
const int b1 = 8;

void setup() {
  Serial.begin(115200);
  steer.attach(servo);
  pinMode(a1, OUTPUT);
  pinMode(b1, OUTPUT);
  pinMode(pwm, OUTPUT);

 steer.write(abs(90)); 

}

void loop() {



  int x = pulseIn(CH_1_PIN, HIGH, 25000);//9
  int y = pulseIn(CH_2_PIN, HIGH, 25000);//9

Serial.print("ch 1 == ");
  Serial.println(y);//10

  x = pulseToPWM(x);
  y = constrain(y, 0, 1930);
  y = map(y, 1, 1930, 5, 95 ); 
//y = constrain(y, -255, 255);
  
  
Serial.print("\t\t\tservo == ");
  Serial.println(y);//10
  // Drive motor
  drive(x, y);

  delay(5);
}

// Positive for forward, negative for reverse
void drive(int speed_a, int speed_b) {

  // Limit speed between -255 and 255
  speed_a = constrain(speed_a, -255, 255);
  
  steer.write(abs(speed_b)); 

  // Set direction for motor A
  if ( speed_a == 0 ) {
    digitalWrite(a1, LOW);
    digitalWrite(b1, LOW);
     Serial.println("\t\t\t\t\t\t\t\t\t\t\tstop ");
  } else if ( speed_a > 0 ) {
    digitalWrite(a1, HIGH);
    digitalWrite(b1, LOW);
         Serial.println("\t\t\t\t\t\t\t\t\t\t\tFRONT ");

  } else {
    digitalWrite(a1, LOW);
    digitalWrite(b1, HIGH);
         Serial.println("\t\t\t\t\t\t\t\t\t\t\tBack ");

  }


  // Set speed
  analogWrite(pwm, abs(speed_a));

}

//// Convert RC pulse value to motor PWM value
int pulseToPWM(int pulse) {

  // If we're receiving numbers, convert them to motor PWM
  if ( pulse > 3 ) {
    pulse = constrain(pulse, 6, 1932);
    pulse = map(pulse, 6, 1932, -255, 255);
    pulse = constrain(pulse, -255, 255);
  } else {
    pulse = 0;
  }

  // Anything in deadzone should stop the motor
  if ( abs(pulse) <= deadzone ) {
    pulse = 0;
  }
  ///
  return pulse;
}
