int relay=2,
    led2=3,
    btnup=A0,
    btndown=A1,
    enter=4,
    led=5;
int segA=7,
    segB=8,
    segC=11,
    segD=12,
    segE=13,
    segF=6,
    segG=10,
    dot=9;
    int COUNT=0,flag=0,x=0,state1=0,state2=0,d=0;
    long wait=0;

int segment(int COUNT)

{
    switch (COUNT)
                {

               case 0:
                {
                digitalWrite(segA, HIGH);
                digitalWrite(segB, HIGH);
                digitalWrite(segC, HIGH);
                digitalWrite(segD, HIGH);
                digitalWrite(segE, HIGH);
                digitalWrite(segF, HIGH);
                digitalWrite(segG, LOW);
                break;
                }
                case 1:
                {
                digitalWrite(segA, LOW);
                digitalWrite(segB, HIGH);
                digitalWrite(segC, HIGH);
                digitalWrite(segD, LOW);
                digitalWrite(segE, LOW);
                digitalWrite(segF, LOW);
                digitalWrite(segG, LOW);
                break;
                }
                case 2:
                {
                digitalWrite(segA, HIGH);
                digitalWrite(segB, HIGH);
                digitalWrite(segC, LOW);
                digitalWrite(segD, HIGH);
                digitalWrite(segE, HIGH);
                digitalWrite(segF, LOW);
                digitalWrite(segG, HIGH);
                break;
                }
                case 3:
                 {
                digitalWrite(segA, HIGH);
                digitalWrite(segB, HIGH);
                digitalWrite(segC, HIGH);
                digitalWrite(segD, HIGH);
               digitalWrite(segE, LOW);
                digitalWrite(segF, LOW);
               digitalWrite(segG, HIGH);
                break;
                 }
                case 4:
               {
                digitalWrite(segA, LOW);
                digitalWrite(segB, HIGH);
                digitalWrite(segC, HIGH);
                digitalWrite(segD, LOW);
                digitalWrite(segE, LOW);
                digitalWrite(segF, HIGH);
                digitalWrite(segG, HIGH);
                break;
                 }              case 5:// when count value is 5 show”5” on disp
                {
                digitalWrite(segA, HIGH);
                digitalWrite(segB, LOW);
                digitalWrite(segC, HIGH);
                digitalWrite(segD, HIGH);
                digitalWrite(segE, LOW);
                digitalWrite(segF, HIGH);
                digitalWrite(segG, HIGH);
                break;
                }
 

                case 6:
                {
                digitalWrite(segA, HIGH);
                digitalWrite(segB, LOW);
                digitalWrite(segC, HIGH);
                digitalWrite(segD, HIGH);
                digitalWrite(segE, HIGH);
                digitalWrite(segF, HIGH);
                digitalWrite(segG, HIGH);
                break;
                }
                 case 7:
                 {
                digitalWrite(segA, HIGH);
                digitalWrite(segB, HIGH);
                digitalWrite(segC, HIGH);
                digitalWrite(segD, LOW);
                digitalWrite(segE, LOW);
                digitalWrite(segF, LOW);
                digitalWrite(segG, LOW);
                break;
                 }
 

                case 8:
                {
                digitalWrite(segA, HIGH);
                digitalWrite(segB, HIGH);
                digitalWrite(segC, HIGH);
                digitalWrite(segD, HIGH);
                digitalWrite(segE, HIGH);
                digitalWrite(segF, HIGH);
                digitalWrite(segG, HIGH);
                break;
                }
 
               case 9:
                {
                digitalWrite(segA, HIGH);
                digitalWrite(segB, HIGH);
                digitalWrite(segC, HIGH);
                digitalWrite(segD, HIGH);
                digitalWrite(segE, LOW);
                digitalWrite(segF, HIGH);
                digitalWrite(segG, HIGH);
                break;

                }
          }
     
       }

         void dton()
       {
        digitalWrite(dot, HIGH);
        }
          void dtoff()
       {
        digitalWrite(dot, 0);
        }

        int start(int i)
      {

if(i==1)
  wait=1;

  if(i==2)
  wait=2;

  if(i==3)
  wait=3;

  if(i==4)
  wait=4;
  
  if(i==5)
  wait=5;

  if(i==6)
  {
    wait=60;
  }
  if(i==7)
  {
    wait=120;
  }
  

  if(i==8)
  {
  wait=180;
  }
  if(x==9)
  {
    wait=240;
  }
        
         Serial.println(i);
           digitalWrite(led2,1);
           delay(100);
           digitalWrite(led2,0);
           delay(100);
           digitalWrite(led2,1);
           delay(100);
           digitalWrite(led2,0);
           digitalWrite(led,1);

            Serial.println("Service started");
            
            wait = wait*1000;
            Serial.println(wait);
           digitalWrite(relay,1);
           delay(wait);
           digitalWrite(relay,0);
           digitalWrite(led,0);
           Serial.println("Service ended");
            dton();
            segment(x);

        }
                

void setup() {

  Serial.begin(9600);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(A0,INPUT_PULLUP);
  pinMode(A1,INPUT_PULLUP);
  pinMode(4,INPUT_PULLUP);
  Serial.println("Ready");

digitalWrite(led2,0);
 digitalWrite(led,1);
 delay(100);
 digitalWrite(led,0);
 delay(100);
 digitalWrite(led,1);
 delay(100);
 digitalWrite(led,0);


  while(digitalRead(enter)!=0)
  {
    delay(10);
    Serial.println("into loop");
     
      if(digitalRead(btnup)==0 && x<10 && state1 == 0)
        {
          
            x++;
            state1=1;
            Serial.println(x);
          }else
           if(digitalRead(btnup)==1 && state1 == 1)
           {
              state1=0;
           
           }else
       if(digitalRead(btndown)==0 && x>0 && state2 == 0)
        {
          
            x--;
            state2=1;
            Serial.println(x);
         
         }else
           
         if(digitalRead(btndown)==1 && state2 == 1)
           {
              state2=0;
           
           }
        if(x<6)
          {
              dton();
            segment(x);
             Serial.println(x);
          }

        if(x>5  && x<10)
         {
            dtoff();
           segment((x-5));
            Serial.println(x);
         }  
        
         
    }
        Serial.println("exit loop");
 Serial.println(x);

 digitalWrite(led2,1);
 delay(100);
 digitalWrite(led2,0);
 delay(100);
 digitalWrite(led2,1);
 delay(100);
 digitalWrite(led2,0);
 delay(100);
 digitalWrite(led2,1);



  
  delay(10);

  if(x > 0)

  {
    start(x);
    }

    

}

void loop() {


  
           dtoff();
           digitalWrite(led2,1);
           delay(500);
           digitalWrite(led2,0);
           delay(500);
           digitalWrite(led,0);
           dton();
           segment(0);

  
  
}
