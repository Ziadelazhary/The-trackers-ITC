#include <Servo.h>
//definiamo i servomotori orizzontale e verticale
Servo servohori;
int servoh = 0;
int servohLimitHigh = 160;
int servohLimitLow = 60;

Servo servoverti; 
int servov = 0; 
int servovLimitHigh = 160;
int servovLimitLow = 60;
//Pin fotoresistenze
int ldrtopl = A2; //top left 
int ldrtopr = A3; //top right 
int ldrbotl = A0; // bottom left 
int ldrbotr = A1; // bottom right 
//  ldrs 0 1 2 3 servos  9 10 
 

#include <Servo.h>

#define ANALOG_IN_PIN A7
Servo myservo;  


float adc_voltage = 0.0;
float in_voltage = 0.0;
float R1 = 30000.0;
float R2 = 7500.0;
float ref_voltage = 5.0;
int adc_value = 0;

float value0=0;
float value1=0;
float value2=0;
float value3=0;
float value4=0;
float value5=0;


 void setup () 
 {

  Serial.begin(9600);
  myservo.attach(6);  
  myservo.write(0);  
    delay(2000);


  adc_value = analogRead(ANALOG_IN_PIN);
  adc_voltage = (adc_value * ref_voltage) / 1024.0;
  in_voltage = adc_voltage / (R2 / (R1 + R2));
  Serial.println(in_voltage, 2);
  myservo.write(30);  
  value0=in_voltage;
  Serial.println(value0);
  delay(3000);


  adc_value = analogRead(ANALOG_IN_PIN);
  adc_voltage = (adc_value * ref_voltage) / 1024.0;
  in_voltage = adc_voltage / (R2 / (R1 + R2));
  Serial.println(in_voltage, 2);
  myservo.write(60);  
  value1=in_voltage;
  Serial.println(value1);
  delay(3000);

  adc_value = analogRead(ANALOG_IN_PIN);
  adc_voltage = (adc_value * ref_voltage) / 1024.0;
  in_voltage = adc_voltage / (R2 / (R1 + R2));
  Serial.println(in_voltage, 2);
  myservo.write(90);  
  value2=in_voltage;
  Serial.println(value2);
  delay(3000);

  adc_value = analogRead(ANALOG_IN_PIN);
  adc_voltage = (adc_value * ref_voltage) / 1024.0;
  in_voltage = adc_voltage / (R2 / (R1 + R2));
  Serial.println(in_voltage, 2);
  myservo.write(120);  
  value3=in_voltage;
  Serial.println(value3);
  delay(3000);

  adc_value = analogRead(ANALOG_IN_PIN);
  adc_voltage = (adc_value * ref_voltage) / 1024.0;
  in_voltage = adc_voltage / (R2 / (R1 + R2));
  Serial.println(in_voltage, 2);
  myservo.write(150);  
  value4=in_voltage;
  Serial.println(value4);
  delay(3000);

  adc_value = analogRead(ANALOG_IN_PIN);
  adc_voltage = (adc_value * ref_voltage) / 1024.0;
  in_voltage = adc_voltage / (R2 / (R1 + R2));
  Serial.println(in_voltage, 2);
  myservo.write(180);  
  value5=in_voltage;
  Serial.println(value5);
  delay(3000);

float arr[]={value0,value1,value2,value3,value4,value5};
int highest = 0;
for(int i = 1;i < 7; ++i) {
    if(arr[0] < arr[i]){
      arr[0] = arr[i];
      highest = i +1;
  }}

  Serial.println("***");
  Serial.println(arr[0]);
  Serial.println("***");
  Serial.println(highest);


  myservo.write(highest*30);  

  servohori.attach(5);
  servohori.write(60);  // swap // swap yellow and white 
  servoverti.attach(4);
  servoverti.write(60);
  Serial.begin(9600);
  delay(500);
  
 }

void loop()
{
  Serial.print("A0:");
  Serial.println(analogRead(A0));
  Serial.print("A1:");
  Serial.println(analogRead(A1));
  Serial.print("A2:");
  Serial.println(analogRead(A2));
  Serial.print("A3:");
  Serial.println(analogRead(A3));
  servoh = servohori.read();

  servov = servoverti.read();
  //Valore Analogico delle fotoresistenza
  int topl = analogRead(ldrtopl);
  int topr = analogRead(ldrtopr);
  int botl = analogRead(ldrbotl);
  int botr = analogRead(ldrbotr);







  // Calcoliamo una Media
  int avgtop = (topl + topr) ; //average of top 
  int avgbot = (botl + botr) ; //average of bottom 
  int avgleft = (topl + botl) ; //average of left 
  int avgright = (topr + botr) ; //average of right

if (avgtop > avgbot)
  {
    servoverti.write(servov +1);
    if (servov > servovLimitHigh) 
     { 
      servov = servovLimitHigh;
     }
    delay(10);
  }
  else if (avgbot > avgtop)
  {
    servoverti.write(servov -1);
    if (servov < servovLimitLow)
  {
    servov = servovLimitLow;
  }
    delay(10);
  }
  else 
  {
    servoverti.write(servov);
  }
  
  if (avgleft > avgright)
  {
    servohori.write(servoh +1);
    if (servoh > servohLimitHigh)
    {
    servoh = servohLimitHigh;
    }
    delay(10);
  }
  else if (avgright > avgleft)
  {
    servohori.write(servoh -1);
    if (servoh < servohLimitLow)
     {
     servoh = servohLimitLow;
     }
    delay(10);
  }
  else 
  {
    servohori.write(servoh);
  }
delay(50);
}
