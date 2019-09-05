/*
Code by: www.munphurid.com
M.Hashir

This is a code for Obstacle Avoiding car

Hardware:
Is bought from www.munphurid.com
-Arduino UNO
-Motor driver module L298N
-Munphurid Chassis MN CS01 (Light weight 3 wheeler chassis can also be used)
-HC-sr04 Ultrasonic Distance Sensor
-7V to 12V battery
-10 male to female wires

Connections:
Motor driver module and Arduino
-Connect IN1 to pin 8 of Arduino
-Connect IN2 to pin 13 of Arduino
-Connect IN3 to pin 9 of Arduino
-Connect IN4 to pin 6 of Arduino
-Connect ENA to pin 2 of Arduino
-Connect ENB to pin 7 of Arduino
-Connect 5V of module to 5V of Arduino
-Connect GND of module to GND of Arduino


Distance sensor and Arduino
-Connect Trig of distance sensor to pin 11 of Arduino
-Connect Echo of distance sensor to pin 10 of Arduino
-Connect VCC of distance sensor to 5V of Arduino
-Connect GND of distance sensor to GND of Arduino

Motors
Connect motors to motor driver module

Battery and all circuits
-Connect +ve wire of battery to 12V of motor driver module
-Connect -ve wire of battery to GND of motor driver module
*/


#define IN1 8         //IN1
#define IN2 13        //IN2
#define ENA 2         //ENA
#define ENB 7         //ENB
#define IN3 9         //IN3
#define IN4 6         //IN4
#define trigger 11    //Trigger
#define echo 10       //Echo


void stopm(void);     
void forward(void);   
void inputs(void);    
void sharpright(void);

int duration;         
float distance;   
   
void setup(void)
{
  Serial.begin (9600);        //Dont edit this line
  pinMode(trigger, OUTPUT);   //Dont edit this line
  pinMode(echo, INPUT);       //Dont edit this line
  pinMode(IN1,OUTPUT);        //Dont edit this line
  pinMode(IN2,OUTPUT);        //Dont edit this line
  pinMode(IN3,OUTPUT);        //Dont edit this line
  pinMode(IN4,OUTPUT);        //Dont edit this line
  pinMode(ENA,OUTPUT);        //Dont edit this line
  pinMode(ENB,OUTPUT);        //Dont edit this line
  digitalWrite(ENA,HIGH);     //Used for speed controlling
  digitalWrite(ENB,HIGH);     //Used for speed controlling
 }


void loop(void) {
 inputs();                    //Dont edit this line
if(distance<24){              //Dont edit this line
  sharpright();               //Dont edit this line
}
else
{
forward();                    //Dont edit this line
}
}



void forward(void)                    //The four lines below tell your car how to move forward... you can edit them
{  Serial.println("Forward");         
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}


void sharpright()                     //The four lines below tell your car how to move sharp right... you can edit them
{  Serial.println("sharpright");
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(400);
}




void stopm(void)                      //The four lines below tell your car how to stop... you can edit them
{  Serial.println("stop");
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}


void inputs()                         //Below lines tell your car how to measure distance... you cant edit them
{
      digitalWrite(trigger, LOW);
      delayMicroseconds(2); 
      digitalWrite(trigger, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigger, LOW);
      duration = pulseIn(echo, HIGH);
      distance = (duration / 2) / 29.1;
      digitalWrite(trigger, LOW); 
      
      Serial.print("forward Distance: ");
      Serial.println(distance);
}
