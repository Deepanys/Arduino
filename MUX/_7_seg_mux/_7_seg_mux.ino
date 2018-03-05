


int A=6,
    B=7,
    C=8,
    D=9,
    E=10,
    F=12,
    G=11,
    CA1=3,
    CA2=2;
    

int timer=1,timer2=0; 

int i=1,t=1,state1=0,state=0,pot1=0,pot2=0;





void setup() {
  // initialize serial communication:
  Serial.begin(9600);
  // initialize the LED pins:
  for (int thisPin = 2; thisPin < 13; thisPin++) {
    pinMode(thisPin, OUTPUT);
  }
  pinMode(A0,INPUT);
  digitalWrite(A,LOW);
digitalWrite(B,LOW);
digitalWrite(C,LOW);
digitalWrite(D, LOW);
digitalWrite(E, LOW);
digitalWrite(F, LOW);
digitalWrite(G, LOW);
digitalWrite(CA1, LOW);
digitalWrite(CA2, LOW);
pinMode(22, INPUT_PULLUP);
pinMode(23, INPUT_PULLUP);



}




int seg(char x)
{
    
  }

void loop() {

/* if(t - (millis()/1000)>  1)
 {
  timer++;
  t=(millis()/1000);
  Serial.println(timer);
 }

  if(timer >99)
  timer=0;

  */
//*
 
if(digitalRead(23)==0&&state==0)
{
  timer++;
  state=1;
  }
  if(digitalRead(23)==1&&state==1)
{
  state=0;
  
  }

  
  if(digitalRead(22)==0&&state1==0)
{
  timer--;
  state1=1;
  }
    if(digitalRead(22)==1&&state1==1)
{
  state1=0;
  
  }

/*
pot1=analogRead(A1);
  if(pot1!=pot2)
  {
  timer=map(pot1,0,1024,0,99);
   Serial.println(timer);
  pot2=pot1;
  }//*/
//  timer=88;
   ones();
   Serial.println(timer);
  showdigit(timer);
  delay(1);
 
  //tens();
  //showdigit(timer/10);
 // delay(1);


}

   void ones()
{
  digitalWrite(CA1, 1);
digitalWrite(CA2, 0);
  }

  void tens()
{
  digitalWrite(CA2, 1);
digitalWrite(CA1, 0);
  }



void digit0 () {

digitalWrite(A,1);
digitalWrite(B,1);
digitalWrite(C,1);
digitalWrite(D, 1);
digitalWrite(E, 1);
digitalWrite(F, 1);
digitalWrite(G, 0);
};


void digit1 () {

digitalWrite(A,LOW);
digitalWrite(B, HIGH);
digitalWrite(C, HIGH);
digitalWrite(D, LOW);
digitalWrite(E, LOW);
digitalWrite(F, LOW);
digitalWrite(G, LOW);
};

void digit2 () {

digitalWrite(A,HIGH);
digitalWrite(B, HIGH);
digitalWrite(C, LOW);
digitalWrite(D, HIGH);
digitalWrite(E, HIGH);
digitalWrite(F, LOW);
digitalWrite(G, HIGH);
};

void digit3 () {

digitalWrite(A,HIGH);
digitalWrite(B, HIGH);
digitalWrite(C, HIGH);
digitalWrite(D, HIGH);
digitalWrite(E, LOW);
digitalWrite(F, LOW);
digitalWrite(G, HIGH);
};

void digit4 () {

digitalWrite(A,LOW);
digitalWrite(B, HIGH);
digitalWrite(C, HIGH);
digitalWrite(D, LOW);
digitalWrite(E, LOW);
digitalWrite(F, HIGH);
digitalWrite(G, HIGH);
};

void digit5 () {

digitalWrite(A,HIGH);
digitalWrite(B, LOW);
digitalWrite(C, HIGH);
digitalWrite(D, HIGH);
digitalWrite(E, LOW);
digitalWrite(F, HIGH);
digitalWrite(G, HIGH);
};

void digit6 () {

digitalWrite(A,HIGH);
digitalWrite(B, LOW);
digitalWrite(C, HIGH);
digitalWrite(D, HIGH);
digitalWrite(E, HIGH);
digitalWrite(F, HIGH);
digitalWrite(G, HIGH);
};

void digit7 () {

digitalWrite(A,HIGH);
digitalWrite(B, HIGH);
digitalWrite(C, HIGH);
digitalWrite(D, LOW);
digitalWrite(E, LOW);
digitalWrite(F, LOW);
digitalWrite(G, LOW);
};

void digit8 () {

digitalWrite(A, HIGH);
digitalWrite(B, HIGH);
digitalWrite(C, HIGH);
digitalWrite(D, HIGH);
digitalWrite(E, HIGH);
digitalWrite(F, HIGH);
digitalWrite(G, HIGH);

};

void digit9 () {

digitalWrite(A, HIGH);
digitalWrite(B, HIGH);
digitalWrite(C, HIGH);
digitalWrite(D, HIGH);
digitalWrite(E, LOW);
digitalWrite(F, HIGH);
digitalWrite(G, HIGH);

}

void showdigit (int digit)

{

 switch (digit) {

 case 0:
 digit0 ();
 delay(10);
 break;

 case 1:
 digit1 ();
 delay(10);
 break;

 case 2:
 digit2 ();
 delay(1);
 break;

 case 3:
 digit3 ();
 delay(1);
 break;

 case 4:
 digit4 ();
 delay(10);
 break;

 case 5:
 digit5 ();
 delay(10);
 break;

 case 6:
 digit6 ();
 delay(10);
 break;

 case 7:
 digit7 ();
 delay(10);
 break;

 case 8:
 digit8 ();
 delay(10);
 break;

 case 9:
 digit9 ();
 break;

 default:

 break;

 }; 

};




