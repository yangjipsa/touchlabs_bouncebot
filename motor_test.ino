/*
 * ==========================================
 *  Bounce Bot - Motor Driver Test
 * ==========================================
 *  Author   : yangjipsa
 *  Company  : TouchLabs (touchlabs.kr)
 *  Version  : 1.0
 *  Date     : 2026-06-16
 *  Product  : Bounce Bot
 *  Purpose  : Test code to control two DC motors
 *             using two L9110S motor drivers.
 *             Tests forward and backward rotation.
 *  Board    : Arduino Nano
 *  Pin Map  : Left  Motor - IA -> D10, IB -> D9
 *             Right Motor - IA -> D6,  IB -> D5 (physical)
 *  Note     : Motors are mounted symmetrically.
 *             Right motor IA/IB are swapped in software
 *             so both motors share the same drive logic.
 * ------------------------------------------
 *  Copyright (c) 2026 TouchLabs.
 *  All rights reserved.
 *
 *  This code is the property of TouchLabs and is
 *  provided for the Bounce Bot product. Unauthorized
 *  copying, distribution, or modification is prohibited.
 * ==========================================
 */

// Left motor driver pins
int L_IA = 10;   // Left motor IA
int L_IB = 9;    // Left motor IB

// Right motor driver pins (swapped in software for mirrored mount)
int R_IA = 5;    // Physically wired to IB (D5)
int R_IB = 6;    // Physically wired to IA (D6)

int motorSpeed = 200;   // Motor speed (0 - 255)

void setup()
{
  Serial.begin(9600);    // Start serial communication

  pinMode(L_IA, OUTPUT);
  pinMode(L_IB, OUTPUT);
  pinMode(R_IA, OUTPUT);
  pinMode(R_IB, OUTPUT);
}

void loop()
{
  // ---------- Forward ----------
  Serial.println("Forward");
  analogWrite(L_IA, motorSpeed);   // Left motor forward
  digitalWrite(L_IB, LOW);
  analogWrite(R_IA, motorSpeed);   // Right motor forward
  digitalWrite(R_IB, LOW);
  delay(2000);

  // ---------- Backward ----------
  Serial.println("Backward");
  digitalWrite(L_IA, LOW);
  analogWrite(L_IB, motorSpeed);   // Left motor backward
  digitalWrite(R_IA, LOW);
  analogWrite(R_IB, motorSpeed);   // Right motor backward
  delay(2000);
}
