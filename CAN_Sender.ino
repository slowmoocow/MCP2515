#include <SPI.h>
#include <mcp2515.h>

#include <Wire.h>

int randNum = 0;

struct can_frame canMsg;
MCP2515 mcp2515(10);

void setup()
{
  Serial.begin(9600);
  SPI.begin();           //Starter SPI kommunikasjon

  mcp2515.reset();
  mcp2515.setBitrate(CAN_500KBPS, MCP_8MHZ); //Setter CAN speed
  mcp2515.setNormalMode();

  canMsg.can_id = 0x036;       //CAN id er 0x036
  canMsg.can_dlc = 1;          //CAN datalengde er 1 byte
}

void loop()
{
  randNum = random(1, 255);
  
  Serial.println(randNum);
 
  canMsg.data[0] = randNum;   

  mcp2515.sendMessage(&canMsg);
  delay(2000);
}
