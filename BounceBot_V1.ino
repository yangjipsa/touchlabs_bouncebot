/*
 * ==========================================
 *  Bounce Bot - Collision Avoidance Robot
 * ==========================================
 *  Author   : yangjipsa
 *  Company  : TouchLabs (touchlabs.kr)
 *  Version  : 1.0
 *  Date     : 2026-06-16
 *  Product  : Bounce Bot
 *  Purpose  : Drive forward and avoid obstacles using
 *             two front bumper switches.
 *             - Left bumper hit  -> back up, turn right
 *             - Right bumper hit -> back up, turn left
 *  Board    : Arduino Nano
 *  Pin Map  : Bumper Left  -> D8,  Bumper Right -> D7
 *             Left  Motor - IA -> D10, IB -> D9
 *             Right Motor - IA -> D6,  IB -> D5 (physical)
 *  Note     : Bumper switches use pull-up, so pressed = LOW.
 *             Motors are mounted symmetrically, so the right
 *             motor IA/IB are swapped in software.
 * ------------------------------------------
 *  Copyright (c) 2026 TouchLabs.
 *  All rights reserved.
 *
 *  This code is the property of TouchLabs and is
 *  provided for the Bounce Bot product. Unauthorized
 *  copying, distribution, or modification is prohibited.
 * ==========================================
 */

// Bumper switch pins
int SWL = 8;     // Left bumper switch
int SWR = 7;     // Right bumper switch

// Left motor driver pins
int L_IA = 10;
int L_IB = 9;

// Right motor driver pins (swapped in software for mirrored mount)
int R_IA = 5;    // Physically wired to IB (D5)
int R_IB = 6;    // Physically wired to IA (D6)

// ----- Settings (tune these) -----
int motorSpeed = 100;   // Motor speed (0 - 255)
int backTime   = 300;   // Reverse time (ms)
int turn90Time = 200;   // Time to rotate about 90 degrees (ms)
int pauseTime  = 200;   // Brief stop time (ms)

void setup()
{
  Serial.begin(9600);

  pinMode(SWL, INPUT);
  pinMode(SWR, INPUT);
  pinMode(L_IA, OUTPUT);
  pinMode(L_IB, OUTPUT);
  pinMode(R_IA, OUTPUT);
  pinMode(R_IB, OUTPUT);

  stop();
}

void loop()
{
  int bumperL = digitalRead(SWL);
  int bumperR = digitalRead(SWR);

  if (bumperL == LOW) 
  {
    // Left bumper hit -> obstacle on front-left
    Serial.println("Left hit -> turn right");
    stop();        
    delay(pauseTime);
    
    backward();    
    delay(backTime);
    
    stop();        
    delay(pauseTime);
    
    turnRight();   
    delay(turn90Time);
    
    stop();        
    delay(pauseTime);
  }
  else if (bumperR == LOW) 
  {
    // Right bumper hit -> obstacle on front-right
    Serial.println("Right hit -> turn left");
    stop();        
    delay(pauseTime);
    
    backward();    
    delay(backTime);
   
    stop();        
    delay(pauseTime);
    
    turnLeft();    
    delay(turn90Time);
    
    stop();        
    delay(pauseTime);
  }
  else 
  {
    // No obstacle -> keep going forward
    forward();
  }
}

// ---------- Movement functions ----------

void forward()
{
  analogWrite(L_IA, motorSpeed);   
  digitalWrite(L_IB, LOW);
  analogWrite(R_IA, motorSpeed);   
  digitalWrite(R_IB, LOW);
}

void backward()
{
  digitalWrite(L_IA, LOW);   
  analogWrite(L_IB, motorSpeed);
  digitalWrite(R_IA, LOW);   
  analogWrite(R_IB, motorSpeed);
}

void turnRight()   // Left wheel forward, right wheel backward
{
  analogWrite(L_IA, motorSpeed);   
  digitalWrite(L_IB, LOW);
  digitalWrite(R_IA, LOW);         
  analogWrite(R_IB, motorSpeed);
}

void turnLeft()    // Left wheel backward, right wheel forward
{
  digitalWrite(L_IA, LOW);   
  analogWrite(L_IB, motorSpeed);
  analogWrite(R_IA, motorSpeed);   
  digitalWrite(R_IB, LOW);
}

void stop()
{
  digitalWrite(L_IA, LOW);   
  digitalWrite(L_IB, LOW);
  digitalWrite(R_IA, LOW);   
  digitalWrite(R_IB, LOW);
}
