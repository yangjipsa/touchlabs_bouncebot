/*
 * ==========================================
 *  Bounce Bot - Bumper Sensor Test
 * ==========================================
 *  Author   : yangjipsa
 *  Company  : TouchLabs (touchlabs.kr)
 *  Version  : 1.0
 *  Date     : 2026-06-16
 *  Product  : Bounce Bot
 *  Purpose  : Test code to read left/right bumper
 *             switch states and print them to
 *             the Serial Monitor.
 *  Board    : Arduino Nano
 *  Pin Map  : Switch Left -> D8, Switch Right -> D7
 * ------------------------------------------
 *  Copyright (c) 2026 TouchLabs.
 *  All rights reserved.
 *
 *  This code is the property of TouchLabs and is
 *  provided for the Bounce Bot product. Unauthorized
 *  copying, distribution, or modification is prohibited.
 * ==========================================
 */

int SWL = 8;   // Left bumper switch pin
int SWR = 7;   // Right bumper switch pin

void setup()
{
  Serial.begin(9600);     // Start serial communication
  pinMode(SWL, INPUT);    // Set left switch as input
  pinMode(SWR, INPUT);    // Set right switch as input
}

void loop()
{
  // Read bumper switch states
  int BumperL = digitalRead(SWL);
  int BumperR = digitalRead(SWR);

  // Print the values to the Serial Monitor
  Serial.print("Bumper L :");
  Serial.print(BumperL);
  Serial.print(", Bumper R :");
  Serial.println(BumperR);

  delay(100);   // Wait 0.1 second
}
