/* 
 Project Name:     Fidget Cleaner
 Authur List:      Prof. Selvin Futardo, Sitanshu Mathukia, Sanjana Nalawade
 Filename:         eyantra.ino
 Functions:        setup, loop, bylnkwrite
 Global Variables: char auth[] = "MPJ3XLJeu-ORsMpoL1POV6VZ6C5HPIWy"; 
                   char ssid[] = "#"; 
                   char pass[] = "12345678"; 
                   int PWM_RIGHT_SIDE=12;  //D6
                   int PWM_LEFT_SIDE=0;    //D3
                   int IN1=14;              //Right side D5
                   int IN2=13;             //Left side  d7
                   int IN3=2;              //Right reverse d4
                   int IN4=4;              //Left reverse  d2
                   int MAX_PWM_VALUE = 1023;
 */


#define BLYNK_PRINT Serial 
#include <ESP8266WiFi.h> 
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

Servo servo1;
Servo servo2;


// to connect blynk app to the nodemcu code\\
char auth[] = "MPJ3XLJeu-ORsMpoL1POV6VZ6C5HPIWy"; 
char ssid[] = "#"; 
char pass[] = "12345678"; 


// pin connections \\
int PWM_RIGHT_SIDE=12;  //D6
int PWM_LEFT_SIDE=0;    //D3
int IN1=14;              //Right side D5
int IN2=13;             //Left side  d7
int IN3=2;              //Right reverse d4
int IN4=4;              //Left reverse  d2
int MAX_PWM_VALUE = 1023;




/* 
Function Name : setup
Input:          None
Output:         Sets the pinmode 
Logic:          To set the specific pin to a specific mode
Example call:   void setup()
 */
void setup()
{ 
   Serial.begin(9600); 
   Blynk.begin(auth, ssid, pass); 
   pinMode(IN1, OUTPUT); 
   pinMode(IN2, OUTPUT); 
   pinMode(IN3, OUTPUT); 
   pinMode(IN4, OUTPUT);


  servo1.attach(15);
  servo2.attach(5);

} 

/*
 *Function Name:  loop
 *Input:          Blynk.run()
 *Output:         Connects the blynks app 
 *Logic:          Checks the auth code,ssid and password 
 *Example call:   void loop()
 */
 
void loop()
{ 
  Blynk.run(); 
}

/*
 * Function Name:   Blynk_Write
 * Input:           Virtual Pin 
 * Output:          Sets the digital pin at the value of virtual pin received from the blynk app
 * Logic:           Connectivity of the virtual pin to the digital all
 * Example call:    BLYNK_WRITE(V1)
 */
BLYNK_WRITE(V1) //first servo of left hand
{
   servo1.write(param.asInt()); 
}
/*
 * Function Name:   Blynk_Write
 * Input:           Virtual Pin 
 * Output:          Sets the digital pin at the value of virtual pin received from the blynk app
 * Logic:           Connectivity of the virtual pin to the digital all
 * Example call:    BLYNK_WRITE(V1)
 */
//second servo of right hand
BLYNK_WRITE(V2)
{
   servo2.write(param.asInt());
}

/*
 * Function Name:   Blynk_Write
 * Input:           Virtual Pin 
 * Output:          Sets the digital pin at the value of virtual pin received from the blynk app
 * Logic:           Connectivity of the virtual pin to the digital all
 * Example call:    BLYNK_WRITE(V1)
 */
BLYNK_WRITE(V3) //Button 1 Widget is writing to pin V3
{
  int x = param.asInt();
  if(x==1)
  { 
    digitalWrite(IN1, LOW); 
    digitalWrite(IN2, LOW);
    analogWrite(PWM_RIGHT_SIDE, MAX_PWM_VALUE);
      
    digitalWrite(IN3, LOW); 
    digitalWrite(IN4, HIGH);
    analogWrite(PWM_LEFT_SIDE, MAX_PWM_VALUE); 
  }
  else if(x==0)
  { 
    digitalWrite(IN1, LOW); 
    digitalWrite(IN2, LOW);
    analogWrite(PWM_RIGHT_SIDE, MAX_PWM_VALUE);
     
    digitalWrite(IN3, LOW); 
    digitalWrite(IN4, LOW);
    analogWrite(PWM_LEFT_SIDE, MAX_PWM_VALUE);
  }
   
}


/*
 * Function Name:   Blynk_Write
 * Input:           Virtual Pin 
 * Output:          Sets the digital pin at the value of virtual pin received from the blynk app
 * Logic:           Connectivity of the virtual pin to the digital all
 * Example call:    BLYNK_WRITE(V1)
 */
BLYNK_WRITE(V4) //Button 2 Widget is writing to pin V4
{
  int y = param.asInt();
  if(y==1)
  { 
    digitalWrite(IN1, LOW); 
    digitalWrite(IN2, HIGH);
    analogWrite(PWM_RIGHT_SIDE, MAX_PWM_VALUE);
      
    digitalWrite(IN3, LOW); 
    digitalWrite(IN4, LOW);
    analogWrite(PWM_LEFT_SIDE, MAX_PWM_VALUE); 
  }
  else if(y==0)
  { 
    digitalWrite(IN1, LOW); 
    digitalWrite(IN2, LOW);
    analogWrite(PWM_RIGHT_SIDE, MAX_PWM_VALUE);
     
    digitalWrite(IN3, LOW); 
    digitalWrite(IN4, LOW);
    analogWrite(PWM_LEFT_SIDE, MAX_PWM_VALUE);
  }
   
} 
