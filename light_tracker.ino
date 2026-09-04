#include <Servo.h>  

Servo horizontal;  
int servoh = 90;  

Servo vertical;   
int servov = 90;  

int ldrlt = 14;  //LDR top left
int ldrrt = 15;  //LDR top rigt
int ldrld = 16;  //LDR down left
int ldrrd = 17;  //ldr down rigt

void setup() {
  Serial.begin(9600);
  horizontal.attach(3);
  vertical.attach(5);
}

void loop() {
  int lt = analogRead(ldrlt);  // top left
  int rt = analogRead(ldrrt);  // top right
  int ld = analogRead(ldrld);  // down left
  int rd = analogRead(ldrrd);  // down rigt

  Serial.print("LT: ");
  Serial.print(lt);
  Serial.print(" RT: ");
  Serial.print(rt);
  Serial.print(" LD: ");
  Serial.print(ld);
  Serial.print(" RD: ");
  Serial.print(rd);

  int tol = analogRead(19) / 4;
  Serial.print("Tol: ");
  Serial.println(tol);

  int avt = (lt + rt) / 2;  
  int avd = (ld + rd) / 2;  
  int avl = (lt + ld) / 2;  
  int avr = (rt + rd) / 2; 

  int dvert = avt - avd;   
  int dhoriz = avl - avr;  

  if (-1 * tol > dvert || dvert > tol)  
  {
    if (avt > avd) {
      servov = ++servov;
      if (servov > 180) {
        servov = 180;
      }
    } else if (avt < avd) {
      servov = --servov;
      if (servov < 0) {
        servov = 0;
      }
    }
    vertical.write(servov);
  }

  if (-1 * tol > dhoriz || dhoriz > tol)  
  {
    if (avl > avr) {
      servoh = --servoh;
      if (servoh < 0) {
        servoh = 0;
      }
    } else if (avl < avr) {
      servoh = ++servoh;
      if (servoh > 180) {
        servoh = 180;
      }
    } else if (avl == avr) {
      // nothing
    }
    horizontal.write(servoh);
  }
  delay(20);
}
